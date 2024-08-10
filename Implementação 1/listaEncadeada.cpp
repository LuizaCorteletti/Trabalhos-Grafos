/*
GRUPO:
Gabriel Martins Rajão - 801792
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

void busca (No *n, int val) { 
    while (n != NULL)
    {
        if (n->num == val)
        {
            cout << "\nValor Encontrado!\n";
            return;
        }
        else
        {
            n = n->prox;
        }
        
    }
    cout << "\nValor Nao Encontrado!\n";
    
    
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
        cout << "[1] - Inserir no inicio\n";
        cout << "[2] - Remover no inicio\n";
        cout << "[3] - Inserir no final\n";
        cout << "[4] - Remover no final\n";
        cout << "[5] - Imprimir lista\n";
        cout << "[6] - Buscar na lista\n";
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
            removeInicio(n1);
            cout << "\n";
            break;
        
        case 3:
            cout << "\nDigite o valor a ser inserido: ";
            cin >> valor;
            insereFim(n1, valor);
            cout << "\n";
            if (counter == 1)
            {
                removeInicio(n1);
            }
            break;

        case 4:
            removeFim(n1);
            cout << "\n";
            break;

        case 5:
            imprime(n1);
            cout << "\n";
            break;

        case 6:
            cout << "\nDigite o valor a ser buscado: ";
            cin >> valor;
            busca(n1, valor);
            cout << "\n";
            break;
        
        default:
            break;
        }
        counter++;
        
    } while (escolha != 0);
    
    
}

