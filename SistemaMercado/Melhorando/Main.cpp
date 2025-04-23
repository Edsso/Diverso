#include "produto.hpp"
#include "estoque.hpp"
#include "Menus.hpp"
#include "produto.cpp"
#include "estoque.cpp"
#include <iostream>

using namespace std;

void verificadorOpcao(int& opcao) {
    cin >> opcao;
    while (cin.fail() || opcao < 1 || opcao > 4) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Opcao invalida. Tente novamente: ";
        cin >> opcao;
    }
}

int main() {
    Estoque estoque;
    int opcao = 0;

    while (true) {
        menuPrincipal();
        verificadorOpcao(opcao);

        switch (opcao) {
        case 1: {
            int opcaoFuncionario;
            menuFuncionario();
            verificadorOpcao(opcaoFuncionario);

            if (opcaoFuncionario == 1) {
                string nome, categoria;
                double preco, desconto;
                int quantidade;
                cout << "Digite o nome do produto: ";
                cin >> nome;
                cout << "Digite a categoria: ";
                cin >> categoria;
                cout << "Digite o preco: ";
                cin >> preco;
                cout << "Digite a quantidade: ";
                cin >> quantidade;
                cout << "Digite o desconto: ";
                cin >> desconto;

                estoque.adicionarProduto(Produto(nome, preco, categoria, quantidade, desconto));
                cout << "Produto adicionado com sucesso!\n";
            } else if (opcaoFuncionario == 2) {
                string nome;
                cout << "Digite o nome do produto a remover: ";
                cin >> nome;
                if (estoque.removerProduto(nome)) {
                    cout << "Produto removido com sucesso!\n";
                } else {
                    cout << "Produto nao encontrado.\n";
                }
            } else if (opcaoFuncionario == 3) {
                estoque.exibirTodosProdutos();
            }
            break;
        }
        case 2: {
            int opcaoCliente;
            menuCliente();
            verificadorOpcao(opcaoCliente);

            if (opcaoCliente == 1) {
                string nome;
                cout << "Digite o nome do produto: ";
                cin >> nome;
                Produto* produto = estoque.buscarProdutoPorNome(nome);
                if (produto) {
                    produto->exibirDetalhes();
                } else {
                    cout << "Produto nao encontrado.\n";
                }
            } else if (opcaoCliente == 2) {
                estoque.exibirProdutosComDesconto();
            }
            break;
        }
        case 3:
            cout << "Estatisticas ainda nao implementadas.\n";
            break;
        case 4:
            cout << "Saindo do sistema...\n";
            return 0;
        }
    }
}