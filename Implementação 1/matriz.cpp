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
    Coluna *head;
    int tamanho;

public:
    Linha(int linhas, int colunas)
    {
        if (linhas < 1 || colunas < 1)
        {
            throw(0);
        }
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
        Coluna *temp = this->head;
        while (temp != NULL)
        {
            temp->print();
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

void Quatro(int valor, Linha * matriz)
{
    Celula *resultado = matriz->busca(valor);
    if (resultado == NULL)
        std::cout << "ELEMENTO NAO ENCONTRADO\n";
    else
    {
        std::cout << "ELEMENTO ENCONTRADO NAS POSICOES: \n";
        Celula *temp = resultado;
        while (temp != NULL)
        {
            std::cout << "\t[";
            std::cout << temp->getElemento()->elemento;
            std::cout << ", ";
            temp = temp->prox;
            std::cout << temp->getElemento()->elemento;
            std::cout << "]\n";
            temp = temp->prox;
        }
        std::cout << "FIM\n";
        delete resultado;
    }
}

    // Codigos
    // 0 : VALOR INVALIDO
    // 1 : VAZIO

    int main(){
        Linha *matriz = NULL;
        try
        {

            int lin;
            int col;
            int val;
            int esc = -1;
            std::cout << "Digite o numero de linhas: ";
            std::cin >> lin;
            std::cout << "Digite o numero de colunas: ";
            std::cin >> col;
            matriz = new Linha(lin, col);
            while (esc != 0)
            {
                std::cout << "ESCOLHA UMA OPCAO\n";
                std::cout << "[1] - Inserir\n";
                std::cout << "[2] - Remover\n";
                std::cout << "[3] - Imprimir matriz\n";
                std::cout << "[4] - Buscar elemento\n";
                std::cout << "[0] - Encerrar\n";
                std::cout << "Digite sua opcao: ";
                std::cin >> esc;
                switch (esc)
                {
                case 0:
                    break;
                case 1:
                    lin = 0;
                    while(lin != -1){
                        std::cout << "Digite a linha do elemento(-1 para encerrar): ";
                        std::cin >> lin;
                        if(lin != -1){
                            std::cout << "Digite a coluna do elemento: ";
                            std::cin >> col;
                            std::cout << "Digite o valor do elemento: ";
                            std::cin >> val;
                            matriz->set(lin,col,val);
                        }
                    }
                    break;
                case 2:
                    lin = 0;
                    while(lin != -1){
                        std::cout << "Digite a linha do elemento(-1 para encerrar): ";
                        std::cin >> lin;
                        if(lin != -1){
                            std::cout << "Digite a coluna do elemento: ";
                            std::cin >> col;
                            matriz->del(lin,col);
                        }
                    }
                    break;
                case 3:
                    matriz->print();
                    break;
                case 4:
                    std::cout << "Digite um valor para busca: ";
                    std::cin >> val;
                    Quatro(val, matriz);
                    break;
                default:
                    throw(0);
                    break;
                }
            }




        }
        catch (int err)
        {
            switch (err)
            {
            case 0:
                std::cout << "ERRO: VALOR INVALIDO";
                break;
            case 1:
                std::cout << "ERRO: VARIAVEL VAZIA";
                break;
            }
        }
        if(matriz!= NULL){
            delete matriz;
            matriz = NULL;
        }
        return 0;
    }
