/*      TicTacToel      */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void imprimirTabuleiro(char Tabela[3][3]){
        cout << "     |     |   " << endl;
        cout << "  " << Tabela[0][0] << "  |  " << Tabela[0][1] << "  |  " << Tabela[0][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |   " << endl;
        cout << "  " << Tabela[1][0] << "  |  " << Tabela[1][1] << "  |  " << Tabela[1][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |   " << endl;
        cout << "  " << Tabela[2][0] << "  |  " << Tabela[2][1] << "  |  " << Tabela[2][2] << endl;
        cout << "     |     |   " << endl;
}

void imprimirTabuleiro(char Tabela[6][6]){
        cout << "     |     |     |     |     |     |" << endl;
        cout << "  " << Tabela[0][0] << "  |  " << Tabela[0][1] << "  |  " << Tabela[0][2] << "  |  " << Tabela[0][3] << "  |  " << Tabela[0][4] << "  |  " << Tabela[0][5] << "  |  " << endl;
        cout << "_____|_____|_____|_____|_____|_____|" << endl;
        cout << "     |     |     |     |     |     |" << endl;
        cout << "  " << Tabela[1][0] << "  |  " << Tabela[1][1] << "  |  " << Tabela[1][2] << "  |  " << Tabela[1][3] << "  |  " << Tabela[1][4] << "  |  " << Tabela[1][5] << "  |  " << endl;
        cout << "_____|_____|_____|_____|_____|_____|" << endl;
        cout << "     |     |     |     |     |     |" << endl;
        cout << "  " << Tabela[2][0] << "  |  " << Tabela[2][1] << "  |  " << Tabela[2][2] << "  |  " << Tabela[2][3] << "  |  " << Tabela[2][4] << "  |  " << Tabela[2][5] << "  |  " << endl;
        cout << "_____|_____|_____|_____|_____|_____|" << endl;
        cout << "     |     |     |     |     |     |" << endl;
        cout << "  " << Tabela[3][0] << "  |  " << Tabela[3][1] << "  |  " << Tabela[3][2] << "  |  " << Tabela[3][3] << "  |  " << Tabela[3][4] << "  |  " << Tabela[3][5] << "  |  " << endl;
        cout << "_____|_____|_____|_____|_____|_____|" << endl;
        cout << "     |     |     |     |     |     |" << endl;
        cout << "  " << Tabela[4][0] << "  |  " << Tabela[4][1] << "  |  " << Tabela[4][2] << "  |  " << Tabela[4][3] << "  |  " << Tabela[4][4] << "  |  " << Tabela[4][5] << "  |  " << endl;
        cout << "_____|_____|_____|_____|_____|_____|" << endl;
        cout << "     |     |     |     |     |     |" << endl;
        cout << "  " << Tabela[5][0] << "  |  " << Tabela[5][1] << "  |  " << Tabela[5][2] << "  |  " << Tabela[5][3] << "  |  " << Tabela[5][4] << "  |  " << Tabela[5][5] << "  |  " << endl;
        cout << "_____|_____|_____|_____|_____|_____|" << endl;
}

void limparTabela(int l, int c, char Tabela[][3]){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            Tabela[i][j] = ' ';
        }
    }
}
void limparTabela6(int l, int c, char Tabela[][6]){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            Tabela[i][j] = ' ';
        }
    }
}

int main(){

    char Tabela3x3[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    char Tabela6x6[6][6] = {' ', ' ', ' ', ' ', ' ', ' ',
                            ' ', ' ', ' ', ' ', ' ', ' ',
                            ' ', ' ', ' ', ' ', ' ', ' ',
                            ' ', ' ', ' ', ' ', ' ', ' ',
                            ' ', ' ', ' ', ' ', ' ', ' ',
                            ' ', ' ', ' ', ' ', ' ', ' '};

    const char JogadorX = 'X';
    const char JogadorO = 'O';
    const char Maquina = 'M';
    const int tamanho6 = 6;
    char JogadorAtual;
    int linha = -1;
    int coluna = -1;
    char vencedor = ' ';

    int op;

    do{
        
        system("cls");

        cout << "Ola, seja bem-vindo ao jogo TicTacToe ou jogo da velha" << endl;
        cout << "================ Menu ================" << endl;
        cout << "\t1 - Jogar 1 vs 1" << endl;
        cout << "\t2 - Desafiar a maquina" << endl;
        cout << "\t3 - Sobre" << endl;
        cout << "\t4 - Sair" << endl;
        cout << "========== Escolha uma opcao ========= " << endl;
        cin >> op;

        switch (op) {
            // Jogadores x Jogadores
            case 1: {
                // Reinicia a jogatina
                limparTabela(3, 3, Tabela3x3);

                vencedor = ' ';
                char JogadorAtual = (rand()% 2 == 0) ? JogadorX : JogadorO;

                system("cls");

                    cout << "================ Menu ================" << endl;
                    cout << "\t1. Tradicional (3x3)" << endl;
                    cout << "\t2. Ampliado (6x6)" << endl;
                    cout << "========== Escolha uma opcao =========" << endl;
                    cin >> op;

                    switch (op) {
                        // 3x3 Completo
                        case 1:{
                                for (int i = 0; i < 9; i++){
                                system("cls");
                                imprimirTabuleiro(Tabela3x3);
                                
                                    if(vencedor != ' '){
                                        break;
                                    }

                                cout << "Jogador atual e " << JogadorAtual << endl;
                                while(true){
                                    cout << "Digite a linha coluna (3 1) de 0-2 da Linha e Coluna: ";
                                    cin >> linha >> coluna;
                                    if(linha < 0 || linha > 2 || coluna < 0 || coluna > 2){
                                        cout << "Numero invalido" << endl;
                                    } else if(Tabela3x3[linha][coluna] != ' ') {
                                        cout << "Espaco ja ocupado" << endl;
                                    } else {
                                        break;
                                    }

                                linha = -1;
                                coluna = -1;
                                cin.clear();
                                cin.ignore();
                                }

                                Tabela3x3[linha][coluna] = JogadorAtual;
                                JogadorAtual = (JogadorAtual == JogadorX) ? JogadorO : JogadorX;

                                // Checar a vitoria

                                //Linhas na horizontal
                                for(int linha = 0; linha < 3; linha++){
                                    if (Tabela3x3[linha][0] != ' ' && Tabela3x3[linha][0] == Tabela3x3[linha][1] && Tabela3x3[linha][1] == Tabela3x3[linha][2]) {
                                        vencedor = Tabela3x3[linha][0];
                                        break;
                                    }
                                }

                                //Colunas na vertical
                                for(int coluna = 0; coluna < 3; coluna++){
                                    if(Tabela3x3[0][coluna] != ' ' && Tabela3x3[0][coluna] == Tabela3x3[1][coluna] && Tabela3x3[1][coluna] == Tabela3x3[2][coluna]){
                                        vencedor = Tabela3x3[0][coluna];
                                        break;
                                    }
                                }

                                //Diagonal
                                if(Tabela3x3[0][0] != ' ' && Tabela3x3[0][0] == Tabela3x3[1][1] && Tabela3x3[1][1] == Tabela3x3[2][2]){
                                    vencedor = Tabela3x3[0][0];
                                } else if(Tabela3x3[0][2] != ' ' && Tabela3x3[0][2] == Tabela3x3[1][1] && Tabela3x3[1][1] == Tabela3x3[2][0]){
                                    vencedor = Tabela3x3[0][2];
                                }
                            }

                            if(vencedor != ' '){
                                cout << "Jogador " << vencedor << " e o vencedor!" << endl;
                            }else{
                                cout << "Paia" << endl;
                                }

                            cout << "\nPressione Enter para voltar ao menu..." << endl;
                            cin.ignore();
                            cin.get();
                            
                            break;
                        }

                        // 6x6 Completo
                        case 2:{   
                                limparTabela6(6, 6, Tabela6x6);
                                for (int i = 0; i < 36; i++){
                                system("cls");
                                imprimirTabuleiro(Tabela6x6);
                                
                                    if(vencedor != ' '){
                                        break;
                                    }
                                int linha, coluna;
                                cout << "Jogador atual e " << JogadorAtual << endl;
                                while(true){
                                    cout << "Digite a linha coluna (3 1) de 0-5 da Linha e Coluna: ";
                                    cin >> linha >> coluna;
                                    if(linha < 0 || linha > 5 || coluna < 0 || coluna > 5){
                                        cout << "Numero invalido" << endl;
                                    } else if(Tabela6x6[linha][coluna] != ' ') {
                                        cout << "Espaco ja ocupado" << endl;
                                    } else {
                                        break;
                                    }

                                }

                                Tabela6x6[linha][coluna] = JogadorAtual;
                                JogadorAtual = (JogadorAtual == JogadorX) ? JogadorO : JogadorX;

                                // Checar a vitoria

                                //Linhas na horizontal
                                for (int l = 0; l < tamanho6; l++) {
                                    for (int c = 0; c <= tamanho6 - 3; c++) {
                                        if (Tabela6x6[l][c] != ' ' && Tabela6x6[l][c] == Tabela6x6[l][c + 1] && Tabela6x6[l][c + 1] == Tabela6x6[l][c + 2]) {
                                            vencedor = Tabela6x6[l][c];
                                        }
                                    }
                                }

                                // Colunas
                                for (int c = 0; c < tamanho6; c++) {
                                    for (int l = 0; l <= tamanho6 - 3; l++) {
                                        if (Tabela6x6[l][c] != ' ' && Tabela6x6[l][c] == Tabela6x6[l + 1][c] && Tabela6x6[l + 1][c] == Tabela6x6[l + 2][c]) {
                                            vencedor = Tabela6x6[l][c];
                                        }
                                    }
                                }

                                // Diagonais principais (da esquerda superior para a direita inferior)
                                for (int l = 0; l <= tamanho6 - 3; l++) {
                                    for (int c = 0; c <= tamanho6 - 3; c++) {
                                        if (Tabela6x6[l][c] != ' ' && Tabela6x6[l][c] == Tabela6x6[l + 1][c + 1] && Tabela6x6[l + 1][c + 1] == Tabela6x6[l + 2][c + 2]) {
                                            vencedor = Tabela6x6[l][c];
                                        }
                                    }
                                }

                                // Diagonais secundárias (da direita superior para a esquerda inferior)
                                for (int l = 0; l <= tamanho6 - 3; l++) {
                                    for (int c = 2; c < tamanho6; c++) {
                                        if (Tabela6x6[l][c] != ' ' && Tabela6x6[l][c] == Tabela6x6[l + 1][c - 1] && Tabela6x6[l + 1][c - 1] == Tabela6x6[l + 2][c - 2]) {
                                            vencedor = Tabela6x6[l][c];
                                        }
                                    }
                                }
                            }

                            if(vencedor != ' '){
                                cout << "Jogador " << vencedor << " e o vencedor!" << endl;
                            }else{
                                cout << "Deu Empate!" << endl << endl;
                                }

                            cout << "\nPressione Enter para voltar ao menu..." << endl;
                            cin.ignore();
                            cin.get();
                            
                            break;
                            }

                        default:
                            cout << "Opcao invalida." << endl;
                            break; 
                        }

                break;
            }

            // Jogador x Maquina
            case 2: {

                srand(time(NULL));
                // Reinicia a jogatina
                limparTabela(3, 3, Tabela3x3);

                vencedor = ' ';
                char JogadorAtual = (rand()% 2 == 0) ? JogadorX : Maquina;

                    cout << "================ Menu ================" << endl;
                    cout << "\t1. Tradicional (3x3)" << endl;
                    cout << "========== Escolha uma opcao =========" << endl;
                    cin >> op;

                    switch (op) {
                        
                        // 3x3 Completo (Melhorar bot)
                        case 1:{
                                for (int i = 0; i < 9; i++){
                                system("cls");
                                imprimirTabuleiro(Tabela3x3);
                                
                                    if(vencedor != ' '){
                                        break;
                                    }

                                cout << "Jogador atual e " << JogadorAtual << endl;
                                if(JogadorAtual == JogadorX){
                                    while(true){
                                        cout << "Digite a linha coluna (3 1) de 0-2 da Linha e Coluna: ";
                                        cin >> linha >> coluna;
                                        if(linha < 0 || linha > 2 || coluna < 0 || coluna > 2){
                                            cout << "Numero invalido" << endl;
                                        } else if(Tabela3x3[linha][coluna] != ' ') {
                                            cout << "Espaco ja ocupado" << endl;
                                        } else {
                                            break;
                                        }
                                    }
                                }else{
                                    do{
                                        linha = rand()% 3;
                                        coluna = rand()% 3;
                                    }while(Tabela3x3[linha][coluna] != ' ');
                                    cout << "Maquina jogou na linha " << linha << ", coluna " << coluna << endl;
                                }


                                Tabela3x3[linha][coluna] = JogadorAtual;
                                JogadorAtual = (JogadorAtual == JogadorX) ? Maquina : JogadorX;

                                // Checar a vitoria

                                //Linhas na horizontal
                                for(int linha = 0; linha < 3; linha++){
                                    if (Tabela3x3[linha][0] != ' ' && Tabela3x3[linha][0] == Tabela3x3[linha][1] && Tabela3x3[linha][1] == Tabela3x3[linha][2]) {
                                        vencedor = Tabela3x3[linha][0];
                                        break;
                                    }
                                }

                                //Colunas na vertical
                                for(int coluna = 0; coluna < 3; coluna++){
                                    if(Tabela3x3[0][coluna] != ' ' && Tabela3x3[0][coluna] == Tabela3x3[1][coluna] && Tabela3x3[1][coluna] == Tabela3x3[2][coluna]){
                                        vencedor = Tabela3x3[0][coluna];
                                        break;
                                    }
                                }

                                //Diagonal
                                if(Tabela3x3[0][0] != ' ' && Tabela3x3[0][0] == Tabela3x3[1][1] && Tabela3x3[1][1] == Tabela3x3[2][2]){
                                    vencedor = Tabela3x3[0][0];
                                } else if(Tabela3x3[0][2] != ' ' && Tabela3x3[0][2] == Tabela3x3[1][1] && Tabela3x3[1][1] == Tabela3x3[2][0]){
                                    vencedor = Tabela3x3[0][2];
                                }
                            }

                            if(vencedor != ' '){
                                cout << "Jogador " << vencedor << " e o vencedor!" << endl;
                            }else{
                                cout << "Deu Empate!" << endl;
                                }
                            
                            cout << "\nPressione Enter para voltar ao menu..." << endl;
                            cin.ignore();
                            cin.get();

                            break;
                        }
                        default:
                            cout << "Opcao invalida." << endl;
                            break; 
                        }
                    break;
                }

            // Sobre o desenvolvedor
            case 3: {
                    cout << "\nDesenvolvido por Edson" << endl;
                    cout << "\nPressione Enter para voltar ao menu..." << endl;
                    cin.ignore();
                    cin.get();
            
                break;
            }

            // Sair
            case 4: {
                cout << "\nSaindo...";
                break;
            }

            default:
                system("cls");
                cout << "Opcao invalida! Escolha novamente." << endl;
            }

        }while(op != 4);

}

