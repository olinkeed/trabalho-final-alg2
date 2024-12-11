#include <iostream>
#include <cassert>

using namespace std;

typedef struct {
    string nome;
    int quantidade;
    float valor;
} Produto;

int verificarAlocacao(Produto *estoque) {
    if (estoque == nullptr) {
        cout << "Falha de alocacao de memoria" << endl;
        return 1;
    }
    return 0;
}

int main() {
    Produto *estoque = new Produto[20]; // Aloca memória para o estoque
    int resultado = verificarAlocacao(estoque);

    // Verificação: se a alocação foi bem-sucedida, o resultado deve ser 0
    assert(resultado == 0);

    cout << "Testes passaram!" << endl;
    delete[] estoque;  // Liberar a memória alocada
    return 0;
}
