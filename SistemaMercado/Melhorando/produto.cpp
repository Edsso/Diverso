#include "produto.hpp"

Produto::Produto(string nome, double preco, string categoria, int quantidade, double desconto)
    : nome(nome), preco(preco), categoria(categoria), quantidade(quantidade), desconto(desconto) {}

void Produto::exibirDetalhes() const{
    cout << "Nome: " << nome << " | Preco: " << preco << " | Categoria: " << categoria << " | Quantidade: " << quantidade << "  | Desconto: " << desconto << "%\n";
}

void Produto::ajustarPreco(double novoPreco){
    preco = novoPreco;
}

void Produto::ajustarDesconto(double novoDesconto){
    desconto = novoDesconto;
}

void Produto::reabastecer(int quantidade){
    this->quantidade += quantidade;
}

bool Produto::reduzirEstoque(int quantidade){
    if (this->quantidade >= quantidade){
        this->quantidade -= quantidade;
        return true;
    }
    return false;
}

string Produto::getNome() const{
    return nome;
}

string Produto::getCategoria() const{
    return categoria;
}

double Produto::getPrecoComDesconto() const{
    return preco - (preco * desconto / 100);
}