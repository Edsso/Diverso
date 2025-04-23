#include "estoque.hpp"

void Estoque::adicionarProduto(const Produto& produto) {
    produtos.push_back(produto);
}

bool Estoque::removerProduto(const std::string& nome) {
    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->getNome() == nome) {
            produtos.erase(it);
            return true;
        }
    }
    return false;
}

Produto* Estoque::buscarProdutoPorNome(const std::string& nome) {
    for (auto& produto : produtos) {
        if (produto.getNome() == nome) {
            return &produto;
        }
    }
    return nullptr;
}

void Estoque::exibirTodosProdutos() const {
    for (const auto& produto : produtos) {
        produto.exibirDetalhes();
    }
}

void Estoque::exibirProdutosComDesconto() const {
    for (const auto& produto : produtos) {
        if (produto.getPrecoComDesconto() < produto.getPrecoComDesconto()) {
            produto.exibirDetalhes();
        }
    }
}