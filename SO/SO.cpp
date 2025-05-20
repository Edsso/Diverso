#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;

int tempo_global = 0;

// ---------------------- Estrutura do Processo ----------------------
struct Processo {
    string id;
    int chegada, exec1, exec2, espera;
    bool bloqueia;

    // Estados de controle
    int tempo_restante;
    int quantum_restante;
    int tempo_inicio = -1;
    int tempo_fim = -1;
    int tempo_espera = 0;
    int tempo_executado = 0;
    int turnaround = 0;
    int trocas_contexto = 0;
    bool em_execucao = false;
    bool foi_bloqueado = false;
    int bloqueado_em = -1;

    Processo(string id_, int chegada_, int e1, bool blk, int esp, int e2)
        : id(id_), chegada(chegada_), exec1(e1), exec2(e2), espera(esp), bloqueia(blk) {
        tempo_restante = exec1;
    }
};

// ---------------------- Variáveis Globais ----------------------
vector<Processo> todos_processos;
vector<Processo*> nucleos;
vector<vector<string>> linha_do_tempo;
queue<Processo*> prontos;
vector<Processo*> bloqueados;

// ---------------------- Funções de Log ----------------------
void log_evento(const string& msg, const string& id) {
    cout << "[t=" << tempo_global << "] Processo " << id << " " << msg << "\n";
}

// ---------------------- Leitura do Arquivo ----------------------
void carregar_entrada(const string& arquivo) {
    ifstream in(arquivo);
    string linha;
    getline(in, linha); // pular cabeçalho
    while (getline(in, linha)) {
        replace(linha.begin(), linha.end(), '|', ' ');
        string id, blk;
        int ch, e1, esp, e2;
        stringstream ss(linha);
        ss >> id >> ch >> e1 >> blk >> esp >> e2;
        bool bloqueia = (blk == "S" || blk == "s");
        todos_processos.emplace_back(id, ch, e1, bloqueia, esp, e2);
    }
}

// ---------------------- Inserção Dinâmica ----------------------
void chegada_dinamica() {
    for (auto& p : todos_processos) {
        if (p.chegada == tempo_global) {
            prontos.push(&p);
            log_evento("chegou", p.id);
        }
    }
}

// ---------------------- Verifica Desbloqueio ----------------------
void verificar_desbloqueios() {
    vector<Processo*> desbloqueados;
    for (auto* p : bloqueados) {
        if (tempo_global - p->bloqueado_em >= p->espera) {
            p->tempo_restante = p->exec2;
            p->foi_bloqueado = true;
            prontos.push(p);
            desbloqueados.push_back(p);
            log_evento("desbloqueado", p->id);
        }
    }
    for (auto* p : desbloqueados) {
        bloqueados.erase(remove(bloqueados.begin(), bloqueados.end(), p), bloqueados.end());
    }
}

// ---------------------- Escalonador Round Robin ----------------------
void escalonar(int quantum) {
    for (size_t i = 0; i < nucleos.size(); i++) {
        auto* atual = nucleos[i];
        if (!atual || atual->quantum_restante == 0 || atual->tempo_restante == 0) {
            if (atual && atual->tempo_restante > 0) {
                atual->trocas_contexto++;
                atual->em_execucao = false;
                prontos.push(atual);
                log_evento("preemptado", atual->id);
            }
            if (!prontos.empty()) {
                auto* novo = prontos.front(); prontos.pop();
                if (novo->tempo_inicio == -1) novo->tempo_inicio = tempo_global;
                novo->quantum_restante = quantum;
                novo->em_execucao = true;
                nucleos[i] = novo;
            } else {
                nucleos[i] = nullptr;
            }
        }
    }
}

// ---------------------- Executar 1 Ciclo ----------------------
void executar_ciclo() {
    for (size_t i = 0; i < nucleos.size(); i++) {
        auto* p = nucleos[i];
        if (p) {
            p->tempo_restante--;
            p->quantum_restante--;
            p->tempo_executado++;
            linha_do_tempo[i].push_back(p->id);
            if (p->tempo_restante == 0) {
                if (p->bloqueia && !p->foi_bloqueado) {
                    p->bloqueado_em = tempo_global;
                    bloqueados.push_back(p);
                    log_evento("bloqueado", p->id);
                } else {
                    p->tempo_fim = tempo_global + 1;
                    p->turnaround = p->tempo_fim - p->chegada;
                    log_evento("finalizado", p->id);
                }
                nucleos[i] = nullptr;
                p->em_execucao = false;
            }
        } else {
            linha_do_tempo[i].push_back("IDLE");
        }
    }
}

// ---------------------- Atualizar Espera ----------------------
void atualizar_espera() {
    for (auto& p : todos_processos) {
        if (!p.em_execucao && p.tempo_inicio != -1 && p.tempo_fim == -1) {
            p.tempo_espera++;
        }
    }
}

// ---------------------- Imprimir Resultados ----------------------
void imprimir_resultados() {
    cout << "\n=== Métricas ===\n";
    cout << setw(5) << "ID" << setw(10) << "Espera" << setw(12) << "Turnaround"
         << setw(10) << "CPU" << setw(10) << "Contexto\n";
    for (auto& p : todos_processos) {
        cout << setw(5) << p.id << setw(10) << p.tempo_espera << setw(12) << p.turnaround
             << setw(10) << p.tempo_executado << setw(10) << p.trocas_contexto << endl;
    }

    cout << "\n=== Linha do Tempo (Gantt) ===\n";
    for (size_t i = 0; i < linha_do_tempo.size(); i++) {
        cout << "Núcleo " << i << ": ";
        for (const auto& nome : linha_do_tempo[i]) {
            cout << nome << " ";
        }
        cout << endl;
    }
}

// ---------------------- Função Principal ----------------------
int main() {
    carregar_entrada("entrada.txt");

    int quantum = 2;
    int num_nucleos = 2;

    nucleos.resize(num_nucleos, nullptr);
    linha_do_tempo.resize(num_nucleos);

    while (true) {
        chegada_dinamica();
        verificar_desbloqueios();
        escalonar(quantum);
        executar_ciclo();
        atualizar_espera();

        bool todos_finalizados = all_of(todos_processos.begin(), todos_processos.end(), [](const Processo& p) {
            return p.tempo_fim != -1;
        });
        if (todos_finalizados) break;

        tempo_global++;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    imprimir_resultados();
    return 0;
}
