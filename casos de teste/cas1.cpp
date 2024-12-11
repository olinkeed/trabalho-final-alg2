#include <iostream>
#include <cassert>

using namespace std;

typedef struct {
    string nome;
    int quantidade;
    float valor;
} Produto;

void adicionarAlimentos(Produto *estoque, int &tamanho) {
    estoque[tamanho].nome = "Coxinha";
    estoque[tamanho].quantidade = 50;
    estoque[tamanho].valor = 2.50;
    tamanho++;
}

int main() {
    Produto estoque[20];
    int tamanho = 5;  // Estoque inicial com 5 produtos

    // Adiciona um novo produto
    adicionarAlimentos(estoque, tamanho);

    // Verificações
    assert(tamanho == 6);  // O tamanho do estoque deve ter aumentado de 5 para 6
    assert(estoque[5].nome == "Coxinha");  // O nome do novo item deve ser "Coxinha"
    assert(estoque[5].quantidade == 50);  // A quantidade do novo item deve ser 50
    assert(estoque[5].valor == 2.50);  // O preço do novo item deve ser 2.50

    cout << "Testes passaram!" << endl;
    return 0;
}
