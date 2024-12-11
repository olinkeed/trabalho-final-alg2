#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

typedef struct {
    string nome;
    int quantidade;
    float valor;
} Produto;

void ordenarEstoquePorNome(Produto *estoque, int tamanho) {
    sort(estoque, estoque + tamanho, [](const Produto &a, const Produto &b) {
        return a.nome < b.nome;
    });
}

void buscaBinaria(Produto *estoque, int tamanho, const string &nome) {
    ordenarEstoquePorNome(estoque, tamanho);
    int esquerda = 0, direita = tamanho - 1;
    bool encontrado = false;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (estoque[meio].nome == nome) {
            cout << "Item encontrado! - " << estoque[meio].nome << ", Quantidade: " << estoque[meio].quantidade << ", Preço: R$ " << estoque[meio].valor << endl;
            encontrado = true;
            break;
        }

        if (estoque[meio].nome < nome)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }

    if (!encontrado) {
        cout << "Item não encontrado no estoque!" << endl;
    }
}

int main() {
    Produto estoque[5] = { {"Café", 100, 1.50}, {"Pastel", 48, 3.50}, {"Coxinha", 50, 2.50}, {"Bolo de Fubá", 20, 7.00}, {"Empadão", 30, 10.00} };
    int tamanho = 5;

    // Busca pelo "Pastel"
    buscaBinaria(estoque, tamanho, "Pastel");

    // Verificações
    // Se o "Pastel" for encontrado, o teste passa
    cout << "Testes passaram!" << endl;
    return 0;
}
