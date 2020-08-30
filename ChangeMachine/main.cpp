
#include <iostream>
#include <string>
#include "coinChanger.h"
using namespace std;

int main()
{
    int opt = 0;
    bool follow = true;
    int coin_box[5] = {0,0,0,0,0};
    string menu = "Qual operacao voce deseja realizar? \n 1 - Abastecer moedas;\n 2 - Sangrar moedas;\n 3 - Gerar troco;\n 4 - Mostrar Caixa;\n 5 - Sair \n";
    coinChanger coin_changer;
    while (follow)
    {
        opt = 0;
        cout << menu;
        cin >> opt;
        while (std::cin.fail())
        {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "Favor digitar uma opcao valida.\n";
            cout << menu;
            cin >> opt;
        }
        switch (opt) {
        case 1:
            coin_changer.coinSupply(&coin_box[0]);
            
            break;
        case 2:
            coin_changer.coinBleed(&coin_box[0]);
            
            break;

        case 3:
            coin_changer.coinChange(&coin_box[0]);
            
            break;
        case 4:
            printf("O Caixa contem: \n %d moedas de 5 cents \n %d moedas de 10 cents \n %d moedas de 25 cents \n %d moedas de 50 cents \n %d moedas de 1 real. \n\n", coin_box[0], coin_box[1], coin_box[2], coin_box[3], coin_box[4]);
            break;
        case 5:
            follow = false;
            break;
        default:
            cout << "Favor digitar uma opcao valida.\n";
        }
    }
}
