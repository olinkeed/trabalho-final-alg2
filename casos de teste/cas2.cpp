#include <iostream>
#include <cassert>

using namespace std;

typedef struct
{
    string nome;
    int quantidade;
    float valor;
} Produto;

void atualizarvalor(Produto *estoque, int tamanho, int escolha, float novoValor)
{
    if (escolha > 0 && escolha <= tamanho)
    {
        estoque[escolha - 1].valor = novoValor;
    }
}

int main()
{
    Produto estoque[20] = {{"Café", 100, 1.50}, {"Pastel", 40, 3.50}};
    int tamanho = 2;

    // Atualiza o preço do "Café" para 2.00
    atualizarvalor(estoque, tamanho, 1, 2.00);

    // Verificações
    assert(estoque[0].valor == 2.00); // O preço do "Café" deve ser 2.00

    cout << "Testes passaram!" << endl;
    return 0;
}
