#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

typedef struct
{
    string nome;
    int quantidade;
    float valor;
} Produto;

void MENSAGEM();
void adicionarAlimentos(Produto *estoque, int &tamanho);
void navegarpeloestoque(Produto *estoque, int tamanho);
void atualizarvalor(Produto *estoque, int tamanho);
void ordenarEstoquePorPreco(Produto *estoque, int tamanho);
void ordenarEstoquePorNome(Produto *estoque, int tamanho);
void buscaBinaria(Produto *estoque, int tamanho, const string &nome);
void removerItem(Produto *estoque, int &tamanho, const string &nome);
void validarEntrada(int &num, const string &mensagem);
void validarEntrada2(float &num, const string &mensagem);
int verificarAlocacao(Produto *estoque);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int item1;
    int tamanho = 5;
    Produto *estoque = new (nothrow) Produto[20];

    if (verificarAlocacao(estoque))
    {
        return 1;
    }

    estoque[0] = {"Coxinha", 20, 2.50};
    estoque[1] = {"Empadão", 10, 10.00};
    estoque[2] = {"Bolo de Fubá", 5, 7.00};
    estoque[3] = {"Pastel", 3, 3.50};
    estoque[4] = {"Café", 10, 1.50};
    estoque[5] = {"Pão Frances", 100, 2.20};

    do
    {
        MENSAGEM();
        cin >> item1;
        system("cls");

        if (item1 == 1)
        {
            navegarpeloestoque(estoque, tamanho);
        }
        else if (item1 == 2)
        {
            atualizarvalor(estoque, tamanho);
        }
        else if (item1 == 3)
        {
            adicionarAlimentos(estoque, tamanho);
        }
        else if (item1 == 4)
        {
            ordenarEstoquePorPreco(estoque, tamanho);
            cout << "Estoque ordenado do mais barato para o mais caro!" << endl;
            system("pause");
            system("cls");
        }
        else if (item1 == 5)
        {
            string nomeBusca;
            cout << "Digite o nome do item a ser buscado: ";
            cin.ignore();
            getline(cin, nomeBusca);
            buscaBinaria(estoque, tamanho, nomeBusca);
        }
        else if (item1 == 6)
        {
            string nomeRemover;
            cout << "Digite o nome do item a ser removido: ";
            cin.ignore();
            getline(cin, nomeRemover);
            removerItem(estoque, tamanho, nomeRemover);
        }

    } while (item1 != 0);

    delete[] estoque;
    return 0;
}

void MENSAGEM()
{
    cout << "===========================================" << endl;
    cout << "         PADARIA 1BENZENO2METANO" << endl;
    cout << "  Onde o sabor e a química se encontram!" << endl;
    cout << "===========================================" << endl;
    cout << "NAVEGAR PELO ESTOQUE[1]" << endl;
    cout << "ALTERAR PRECIFICAÇÃO[2]" << endl;
    cout << "ADICIONAR ALIMENTOS[3]" << endl;
    cout << "ORDENAR ESTOQUE POR PREÇO[4]" << endl;
    cout << "BUSCAR ITEM NO ESTOQUE[5]" << endl;
    cout << "REMOVER ITEM DO ESTOQUE[6]" << endl;
    cout << "SAIR[0]" << endl;
}

void navegarpeloestoque(Produto *estoque, int tamanho)
{
    cout << "ITENS ARMAZENADOS NO ESTOQUE:\n";
    Produto *ponteiro = estoque;
    for (int i = 0; i < tamanho; i++)
    {
        cout << "ITEM: " << (*(ponteiro + i)).nome
             << ", QUANTIDADE: " << (*(ponteiro + i)).quantidade
             << ", PREÇO: R$ " << (*(ponteiro + i)).valor << endl;
    }
    system("pause");
    system("cls");
}

void atualizarvalor(Produto *estoque, int tamanho)
{
    int escolha;
    cout << "Escolha o item que deseja alterar o valor:" << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cout << i + 1 << " - " << estoque[i].nome << endl;
    }
    cout << "0 - Nenhum" << endl;
    cout << "Digite o número do item: ";
    cin >> escolha;

    if (escolha > 0 && escolha <= tamanho)
    {
        cout << "Digite o novo valor para " << estoque[escolha - 1].nome << ": ";
        cin >> estoque[escolha - 1].valor;
    }
    else if (escolha != 0)
    {
        cout << "Opção inválida!" << endl;
    }
    system("pause");
    system("cls");
}

void adicionarAlimentos(Produto *estoque, int &tamanho)
{
    cout << "Digite o nome do novo item: ";
    cin.ignore();
    getline(cin, estoque[tamanho].nome);

    validarEntrada(estoque[tamanho].quantidade, "Quantas unidades deseja adicionar? ");
    validarEntrada2(estoque[tamanho].valor, "Digite o preço do item: ");

    tamanho++;

    cout << "Item adicionado com sucesso!" << endl;
    system("pause");
    system("cls");
}

void ordenarEstoquePorPreco(Produto *estoque, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (estoque[j].valor < estoque[menor].valor)
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            Produto aux = estoque[i];
            estoque[i] = estoque[menor];
            estoque[menor] = aux;
        }
    }
}

void ordenarEstoquePorNome(Produto *estoque, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (estoque[j].nome < estoque[menor].nome)
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            Produto aux = estoque[i];
            estoque[i] = estoque[menor];
            estoque[menor] = aux;
        }
    }
}

void buscaBinaria(Produto *estoque, int tamanho, const string &nome)
{
    ordenarEstoquePorNome(estoque, tamanho);

    int esquerda = 0, direita = tamanho - 1;
    bool encontrado = false;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (estoque[meio].nome == nome)
        {
            cout << "Item encontrado! " << estoque[meio].nome << ", Quantidade: " << estoque[meio].quantidade
                 << ", Preço: R$ " << estoque[meio].valor << endl;
            encontrado = true;
            break;
        }

        if (estoque[meio].nome < nome)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }

    if (!encontrado)
    {
        cout << "Item não encontrado no estoque!" << endl;
    }
    system("pause");
    system("cls");
}

void removerItem(Produto *estoque, int &tamanho, const string &nome)
{
    int posicao = -1;

   
    for (int i = 0; i < tamanho; i++)
    {
        if (estoque[i].nome == nome)
        {
            posicao = i;
            break;
        }
    }

    if (posicao == -1)
    {
        cout << "Item não encontrado no estoque!" << endl;
    }
    else
    {

        for (int i = posicao; i < tamanho - 1; i++)
        {
            estoque[i] = estoque[i + 1];
        }
        tamanho--;
        cout << "Item removido com sucesso!" << endl;
    }
    system("pause");
    system("cls");
}

void validarEntrada(int &num, const string &mensagem)
{
    do
    {
        cout << mensagem;
        cin >> num;
        if (num < 0)
        {
            cout << "Valor inválido! Por favor, insira um número positivo." << endl;
        }
    } while (num < 0);
}

void validarEntrada2(float &num, const string &mensagem)
{
    do
    {
        cout << mensagem;
        cin >> num;
        if (num < 0)
        {
            cout << "Valor inválido! Por favor, insira um número positivo." << endl;
        }
    } while (num < 0);
}

int verificarAlocacao(Produto *estoque)
{
    if (estoque == nullptr)
    {
        cout << "Falha de alocação de memória!" << endl;
        return 1;
    }
    return 0;
}
