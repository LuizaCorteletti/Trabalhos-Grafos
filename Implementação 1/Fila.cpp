/*
GRUPO:
Gabriel Martins Rajão - [matricula]
Luiza Dias Corteletti - 816706
*/

#include <iostream>
using namespace std;

struct No {

    int num;
    No *prox;

};

void imprime (No *n) { 
    cout << "\n--- IMPRIMIR LISTA ---\n";
    while (n != NULL)
    {
        cout << n->num << "\n";
        n = n->prox;
    }
    
    
}

void insereInicio (No *&n, int val) {
    No *novo = new No;
    novo->num = val;
    novo->prox = n;
    n = novo;
}

void removeInicio (No *&cabeca) {
    if (cabeca != NULL)
    {
        cabeca = cabeca->prox;
    }
}

void insereFim (No *&n, int val) {
    No *novo = new No;
    novo->num = val;
    novo->prox = NULL;
    if (n == NULL) //LISTA VAZIA
    {
        n = novo;
    }
    else //LISTA COM ELEMENTOS
    {
        No *no = n;
        while (no->prox != NULL)
        {
            no = no->prox;
        }
        no->prox = novo;
        
    }
    
}

void removeFim (No *&cabeca) {
    if (cabeca != NULL)
    {
        No *n = cabeca;
        while (n->prox->prox != NULL)
        {
            n = n->prox;
        }
        n->prox = NULL;
        
    }
    
}



int main() {
    
    No *n1 = new No; //cabeça
    n1->num = 0;
    n1->prox = NULL;
    int escolha;
    int valor;
    int counter = 1;
    cout << "\n";
    do
    {
        cout << "ESCOLHA UMA OPCAO\n";
        cout << "[1] - Inserir\n";
        cout << "[2] - Remover\n";
        cout << "[3] - Imprimir lista\n";
        cout << "[0] - Encerrar\n";
        cout << "\n";
        cin >> escolha;
        
        
        switch (escolha)
        {
        case 1:
            cout << "\nDigite o valor a ser inserido: ";
            cin >> valor;
            insereInicio(n1, valor);
            cout << "\n";
            if (counter == 1)
            {
                removeFim(n1);
            }
            
            break;

        case 2:
            removeFim(n1);
            cout << "\n";
            break;

        case 3:
            imprime(n1);
            cout << "\n";
            break;
        
        default:
            break;
        }
        counter++;
        
    } while (escolha != 0);
    
    
}

