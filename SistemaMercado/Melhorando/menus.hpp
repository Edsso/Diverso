#ifndef MENUS_HPP
#define MENUS_HPP

#include <iostream>
using namespace std;

void menuPrincipal() {
    cout << "\n=== Menu Principal ===\n";
    cout << "1. Menu do Funcionario\n";
    cout << "2. Menu do Cliente\n";
    cout << "3. Exibir Estatisticas\n";
    cout << "4. Sair\n";
    cout << "Escolha uma opcao: ";
}

void menuFuncionario() {
    cout << "\n=== Menu do Funcionario ===\n";
    cout << "1. Adicionar Produto\n";
    cout << "2. Remover Produto\n";
    cout << "3. Exibir Todos os Produtos\n";
    cout << "4. Voltar ao Menu Principal\n";
    cout << "Escolha uma opcao: ";
}

void menuCliente() {
    cout << "\n=== Menu do Cliente ===\n";
    cout << "1. Buscar Produto\n";
    cout << "2. Exibir Produtos com Desconto\n";
    cout << "3. Voltar ao Menu Principal\n";
    cout << "Escolha uma opcao: ";
}

#endif