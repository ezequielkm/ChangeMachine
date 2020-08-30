#include "validator.h"
#include <iostream>
using namespace std;

void validator::inputValidSupply(int pos, int* coin_box)
{
    int qtd;
    cout << "Qual quantidade destas moedas ira inserir?\n";
    cin >> qtd;
    while (cin.fail() || qtd < 0)
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "Digite uma quantidade valida ou 0 para retornar: \n";
        cin >> qtd;
    }
    coin_box[pos] += qtd;
    printf("Existem %d moedas deste valor. \n", coin_box[pos]);
}

void validator::inputValidBleed(int pos, int* coin_box)
{
    int qtd;
    cout << "Quantidade de moedas a retirar: ";
    cin >> qtd;
    while (cin.fail() || qtd > coin_box[pos] || qtd < 0)
    {
        if (cin.fail() || qtd < 0)
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "Digite uma quantidade valida: \n";
        }
        else
        {
            printf("Existem apenas %d moedas deste valor, digite uma quantia valida ou 0 para retornar: \n", coin_box[pos]);
        }
        cin >> qtd;
    }

    coin_box[pos] -= qtd;
    printf("Existem %d moedas deste valor. \n", coin_box[pos]);
}

int validator::inputValidChange(int value)
{
    while (cin.fail() || value < 0)
    {
        cin.clear();
        cin.ignore();
        cout << "Digite um valor valido ou 0 para retornar.";
        cin >> value;
    }
    if (value == 0)
        return 0;
    return value;
}



