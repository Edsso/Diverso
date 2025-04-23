#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <vector>
#include "produto.hpp"

using namespace std;

class Estoque {
private:
    vector<Produto> produtos;

public:
    void adicionarProduto(const Produto& produto);
    bool removerProduto(const string& nome);
    Produto* buscarProdutoPorNome(const string& nome);
    void exibirTodosProdutos() const;
    void exibirProdutosComDesconto() const;
};

#endif