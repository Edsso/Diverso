#ifndef PRODUTO_HPP
#define PRODUTO_HPP


#include <iostream>
#include <string>
using namespace std;

class Produto{
    private:
        string nome;
        double preco;
        string categoria;
        int quantidade;
        double desconto;

    public:
        Produto(string nome, double preco, string categoria, int quantidade, double desconto = 0.0);
        void exibirDetalhes() const;
        void ajustarPreco(double novoPreco);
        void ajustarDesconto(double novoDesconto);
        void reabastecer(int quantidade);
        bool reduzirEstoque(int quantidade);
        string getNome() const;
        string getCategoria() const;
        double getPrecoComDesconto() const;          
};

#endif