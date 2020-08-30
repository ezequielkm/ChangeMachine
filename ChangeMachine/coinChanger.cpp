#include "coinChanger.h"
#include <iostream>
#include <string>
#include "validator.h"

using namespace std;

void coinChanger::coinSupply(int* coin_box)
{
    validator valid;

    int aux_coin;
    int follow = 1;
    while (follow == 1)
    {
        cout << "Qual valor da moeda voce ira inserir (5, 10, 25, 50, 1)?\n";
        cin >> aux_coin;


        switch (aux_coin)
        {
        case 5:
            valid.inputValidSupply(0, &coin_box[0]);
            break;

        case 10:
            valid.inputValidSupply(1, &coin_box[0]);

            break;

        case 25:
            valid.inputValidSupply(2, &coin_box[0]);

            break;

        case 50:

            valid.inputValidSupply(3, &coin_box[0]);

            break;

        case 1:
            valid.inputValidSupply(4, &coin_box[0]);
            break;

        default:

            if (cin.fail())
            {
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Favor digitar uma opcao valida.\n";
            break;
        }

        cout << "Deseja continuar adicionando moedas? - 1 para sim, qualquer outra tecla para sair. \n";
        cin >> follow;
        if (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            follow = 0;
        }
    }
    return;
}

void coinChanger::coinBleed(int* coin_box)
{
    cout << "Qual valor da moeda voce ira retirar (5, 10, 25, 50, 1)?\n";
    int aux_coin;
    int follow = 1;
    validator valid;
    while (follow == 1)
    {
        cin >> aux_coin;
        switch (aux_coin)
        {
        case 5:

            valid.inputValidBleed(0, &coin_box[0]);
            break;

        case 10:
            valid.inputValidBleed(1, &coin_box[0]);
            break;

        case 25:
            valid.inputValidBleed(2, &coin_box[0]);
            break;

        case 50:

            valid.inputValidBleed(3, &coin_box[0]);
            break;

        case 1:
            valid.inputValidBleed(4, &coin_box[0]);
            break;

        default:
            if (std::cin.fail())
            {
                cin.clear(); // clear input buffer to restore cin to a usable state
                cin.ignore(INT_MAX, '\n'); // ignore last input

            }
            cout << "Favor digitar uma opcao valida.\n";
            break;
        }

        cout << "Deseja continuar retirando moedas? - 1 para sim, qualquer outra tecla para sair. \n";
        cin >> follow;
        if (cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            follow = 0;
        }
    }
}

void coinChanger::coinChange(int* coin_box)
{
    validator valid;
    int input, purchase, change;
    cout << "Digite valor inserido na maquina em centavos.\n";
    cin >> input;
    if (valid.inputValidChange(input) == 0)
        return;
    cout << "Digite valor da compra na maquina em centavos.\n";
    cin >> purchase;
    if (valid.inputValidChange(purchase) == 0)
        return;

    if (input < purchase)
    {
        cout << "O valor inserido deve ser maior que o da compra. Repita a operacao.\n";
        return;
    }
    else if (input == purchase)
    {
        cout << "O valor inserido e igual ao da compra. Nao ha troco para esta operacao.\n";
        return;
    }
    else
    {
        change = input - purchase;
        int invalido = 0;
        int aux;
        int change_coins[5] = { 0,0,0,0,0 };
        int temp_box[5] = { coin_box[0],coin_box[1],coin_box[2],coin_box[3],coin_box[4] };
        // MOEDAS DE 1 REAL
        aux = change / 100;
        if (aux <= temp_box[4])
        {
            change_coins[4] = aux;
            temp_box[4] = temp_box[4] - change_coins[4];
            change = change - (change_coins[4] * 100);
        }

        else
        {
            change_coins[4] = temp_box[4];
            temp_box[4] = 0;
            change = change - (change_coins[4] * 100);
        }

        //MOEDAS DE 50
        aux = change / 50;

        if (aux <= temp_box[3])
        {
            change_coins[3] = aux;
            temp_box[3] = temp_box[3] - change_coins[3];
            change = change - (change_coins[3] * 50);

        }
        else
        {
            change_coins[3] = temp_box[3];
            temp_box[3] = 0;
            change = change - (change_coins[3] * 50);
        }

        // MOEDAS DE 25
        aux = change / 25;

        if (aux <= temp_box[2])
        {
            change_coins[2] = aux;
            temp_box[2] = temp_box[2] - change_coins[2];
            change = change - (change_coins[2] * 25);
        }
        else
        {
            change_coins[2] = temp_box[2];
            temp_box[2] = 0;
            change = change - (change_coins[2] * 25);
        }

        // MOEDAS DE 10
        aux = change / 10;

        if (aux <= temp_box[1])
        {
            change_coins[1] = aux;
            temp_box[1] = temp_box[1] - change_coins[1];
            change = change - (change_coins[1] * 10);
        }
        else
        {
            change_coins[1] = temp_box[1];
            temp_box[1] = 0;
            change = change - (change_coins[1] * 10);
        }

        //MOEDAS 5
        aux = change / 5;

        if (aux <= temp_box[0] && change % 5 == 0)
        {
            change_coins[0] = aux % 5;
            temp_box[0] = temp_box[0] - change_coins[0];
            change = change - (change_coins[0] * 5);
        }
        else
        {
            cout << "Nao e possivel fornecer este valor de troco. Bloqueando a operacao. \n";
            invalido = 1;
        }


        if (invalido == 0)
        {
            cout << "O troco devido contem: " << "\n";
            cout << "Moedas de 5 cents: " << change_coins[0] << "\n";
            cout << "Moedas de 10 cents: " << change_coins[1] << "\n";
            cout << "Moedas de 25 cents: " << change_coins[2] << "\n";
            cout << "Moedas de 50 cents: " << change_coins[3] << "\n";
            cout << "Moedas de 1 real: " << change_coins[4] << "\n";

            for (int i = 0; i < 5; i++)
            {
                coin_box[i] = temp_box[i];
            }
            cout << "Operacao realizada com sucesso." << "\n";

        }

    }

}

