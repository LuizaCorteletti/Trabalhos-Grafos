#include <iostream>
/*
GRUPO:
Gabriel Martins Rajão - 801792
Luiza Dias Corteletti - 816706
*/
class Inteiro
{
public:
    int elemento;
    Inteiro(int elemento)
    {
        this->elemento = elemento;
    }
};

class Celula
{
public:
    Inteiro *inte;
    Celula *prox;

    Celula()
    {
        this->inte = NULL;
        this->prox = NULL;
    }

    Celula(int elemento)
    {
        this->inte = new Inteiro(elemento);
        this->prox = NULL;
    }
    Celula(int elemento, Celula *prox)
    {
        this->inte = new Inteiro(elemento);
        this->prox = prox;
    }
    ~Celula()
    {
        if (this->prox != NULL)
        {
            delete this->prox;
        }
        if (this->inte != NULL)
        {
            delete this->inte;
        }
    }

    void setElemento(int elemento)
    {
        if (this->inte == NULL)
            this->inte = new Inteiro(elemento);
        else
            this->inte->elemento = elemento;
    }
    Inteiro *getElemento()
    {
        return this->inte;
    }
    void deleteElemento()
    {
        if (this->inte != NULL)
        {
            delete this->inte;
            this->inte = NULL;
        }
        else
        {
            throw(1);
        }
    }
};

class Coluna
{
public:
    int tamanho;
    Celula *head;
    Coluna *prox;

    Coluna(int tamanho)
    {
        this->tamanho = tamanho;
        this->head = new Celula();
        Celula *temp = this->head;
        for (int i = 0; i < this->tamanho - 1; i++)
        {
            temp->prox = new Celula();
            temp = temp->prox;
        }
        this->prox = NULL;
    }
    ~Coluna()
    {
        if (this->head != NULL)
        {
            delete this->head;
        }
        if (this->prox != NULL)
        {
            delete this->prox;
        }
    }


    void setAll(int elemento){
        Celula * temp = this->head;
        while(temp!= NULL){
            temp->setElemento(elemento);
            temp = temp->prox;
        }
    }

    void set(int coluna, int elemento)
    {
        if (coluna < tamanho && coluna > -1)
        {
            Celula *temp = this->head;
            for (int i = 0; i != coluna; i++)
            {
                temp = temp->prox;
            }
            temp->setElemento(elemento);
        }
        else
        {
            throw(0);
        }
    }
    void del(int coluna)
    {
        if (coluna < tamanho && coluna > -1)
        {
            Celula *temp = this->head;
            for (int i = 0; i != coluna; i++)
            {
                temp = temp->prox;
            }
            temp->deleteElemento();
        }
        else
        {
            throw(0);
        }
    }
    void print()
    {
        Celula *temp = this->head;
        std::cout << "[";
        Inteiro *ele = temp->getElemento();
        if (ele == NULL)
        {
            std::cout << "VAZIO";
        }
        else
        {
            std::cout << ele->elemento;
        }
        temp = temp->prox;
        while (temp != NULL)
        {
            ele = temp->getElemento();
            if (ele == NULL)
            {
                std::cout << ", VAZIO";
            }
            else
            {
                std::cout << ", " << ele->elemento;
            }
            temp = temp->prox;
        }
        std::cout << "]\n";
    }

    int busca(int elemento)
    {
        int coluna = 0;
        Celula *temp = this->head;
        while (temp != NULL)
        {
            Inteiro *ele = temp->getElemento();
            if (ele != NULL && ele->elemento == elemento)
            {
                return coluna;
            }
            temp = temp->prox;
            coluna++;
        }

        return -1;
    }
};

class Linha
{
protected:
    bool quad;
    Coluna *head;
    int tamanho;

public:
    Linha(int linhas, int colunas)
    {
        if (linhas < 1 || colunas < 1)
        {
            throw(0);
        }
        if( linhas == colunas)quad = true;
        else quad = false;

        this->tamanho = linhas;
        this->head = new Coluna(colunas);
        Coluna *temp = this->head;
        for (int i = 0; i < this->tamanho - 1; i++)
        {
            temp->prox = new Coluna(colunas);
            temp = temp->prox;
        }
    }
    ~Linha()
    {
        delete head;
    }
    void print()
    {
        std::cout <<"==============" <<"PrintandoGrafo"<<"==============\n";
        Coluna *temp = this->head;
        while (temp != NULL)
        {
            temp->print();
            temp = temp->prox;
        }
        std::cout <<"=============="<<"=============="<<"==============\n";
    }


    void setDiag(int elemento){
        if(quad == false)throw(0);

        int i  = 0;
        Coluna * temp = this->head;
        while(temp != NULL){
            temp->set(i++,elemento);
            temp = temp->prox;
        }

    }

    void setAll(int elemento){
        Coluna *temp = this->head;
        while(temp != NULL){
            temp->setAll(elemento);
            temp = temp->prox;
        }
    }

    void set(int linha, int coluna, int elemento)
    {
        if (linha > -1 && linha < this->tamanho)
        {
            Coluna *temp = this->head;
            for (int i = 0; i != linha; i++)
            {
                temp = temp->prox;
            }
            temp->set(coluna, elemento);
        }
        else
        {
            throw(0);
        }
    }
    void del(int linha, int coluna)
    {
        if (linha > -1 && linha < this->tamanho)
        {
            Coluna *temp = this->head;
            for (int i = 0; i != linha; i++)
            {
                temp = temp->prox;
            }
            temp->del(coluna);
        }
        else
        {
            throw(0);
        }
    }
    Celula *busca(int elemento)
    {
        Celula *lista = NULL;
        Celula *t = NULL;
        Coluna *temp = this->head;
        int linha = 0;
        while (temp != NULL)
        {
            int result = temp->busca(elemento);
            if (result != -1)
            {
                std::cout << linha << " " << result << "\n";
                if (lista == NULL)
                {
                    lista = new Celula(linha);
                    lista->prox = new Celula(result);
                    t = lista->prox;
                }
                else
                {
                    t->prox = new Celula(linha);
                    t = t->prox;
                    t->prox = new Celula(result);
                    t = t->prox;
                }
            }
            temp = temp->prox;
            linha++;
        }

        return lista;
    }
};


