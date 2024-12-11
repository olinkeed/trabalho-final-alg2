#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

typedef struct {
    string nome;
    int quantidade;
    float valor;
} Produto;

void ordenarEstoquePorPreco(Produto *estoque, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (estoque[j].valor < estoque[menor].valor) {
                menor = j;
            }
        }
        if (menor != i) {
            Produto aux = estoque[i];
            estoque[i] = estoque[menor];
            estoque[menor] = aux;
        }
    }
}

int main() {
    Produto estoque[5] = {{"Café", 100, 1.50}, {"Pastel", 40, 3.50}, {"Coxinha", 50, 2.50}, {"Bolo de Fubá", 20, 7.00}, {"Empadão", 30, 10.00}};
    int tamanho = 5;

    // Ordena o estoque por preço
    ordenarEstoquePorPreco(estoque, tamanho);

    // Verificação: O primeiro item deve ser o mais barato (Café - 1.50)
    assert(estoque[0].valor == 1.50);

    cout << "Testes passaram!" << endl;
    return 0;
}
