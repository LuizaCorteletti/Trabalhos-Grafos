/*
GRUPO:
Gabriel Martins Rajão - 801792
Luiza Dias Corteletti - 816706
*/


#include "grafo.h"
#include <cmath>
#include <iostream>
using namespace std;

int fat (int i){
    if(i < 2){
        return 1;
    }
    return i * fat(i-1);
}

int combinacao(int n, int k){
    int nfat = fat(n);
    int kfat = fat(k);
    int knfat = fat(n-k);
    int mult = kfat * knfat;
    
    return nfat/mult;
}

int subgCount(int vertice){
    int result = 0;
    for(int i = 1; i <= vertice; i++){
        int pot = i *(i-1);
        pot = pot/2;
        int ele = pow(2,pot);
        int comb = combinacao(vertice, i);
        result += ele*comb;
    }
    return result;
}




int main(){

    int n;

    cout << "\nDigite o numero de vertices do grafo: ";
    cin >> n;
    cout << "\n";

    labelGen(n);

    cout<< "\nNumero de Subgrafos Totais: " << subgCount(n) << "\n";

}