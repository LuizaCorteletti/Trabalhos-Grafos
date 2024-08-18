/*
GRUPO:
Gabriel Martins Rajão - 801792
Luiza Dias Corteletti - 816706
*/

#include <iostream>
#include "matriz.h"

//contador global de grafos feitos (o ideal era fazer uma nova classe para armazenar os subgrafos, mas reduziria a capacidade do programa devido a memoria)
int counter = 1;

// a classe grafo é basicamente uma matriz (funcoes e atributos herdados de Linha do arquivo matriz.h)
class Grafo: public Linha{
    void fazGraComp(){
        this->setAll(1);
        this->setDiag(0);
    }
    public: 
    Grafo(int vertice) : Linha(vertice, vertice)
    {
        fazGraComp();
    }
    Grafo(std::string str, int vertice):Linha(vertice,vertice)
    {
        this->setAll(0);
        int strind = 0;
        for(int i = 0; i < vertice - 1; i++){
            for(int j = i + 1; j < vertice; j++){
                char ha = str.at(strind++);
                setAresta(i,j,(int) ha - 48);
            }
        }
    }
    void setAresta(int v1, int v2, int el){
        set(v1,v2,el);
        set(v2,v1,el);
    }

    void print(std::string label, int num){
        int i = 0;
        std::cout <<"==============" <<"PrintandoGrafo "<<num<<"==============\n";
        Coluna *temp = this->head;
        while (temp != NULL)
        {
            std::cout<<label.at(i++)<<": ";
            temp->print();
            temp = temp->prox;
        }
        std::cout <<"=============="<<"=============="<<"==============\n";
    }
};



//Gera todas as possibilidades de grafos para um numero de vertices
//Ex: 3 vertices, temos 3*(3-1)/2 = 3 arestas. Teremos tres bits(000) representando as arestas a1, a2 e a3 respectivamente
//a1 liga a e b, a2 liga a e c, a3 liga b e c
void GeraSubgrafos( int vertice, std::string str, std::string label){
    int p = str.size();
    int ares = vertice*(vertice - 1);
    ares = ares/2;
    if(p < ares ){
        GeraSubgrafos( vertice, str+"0", label);
        GeraSubgrafos( vertice, str+"1", label);
    } else {
        int p = str.size();
        if(p > 0){
            Grafo * g = new Grafo(str, vertice);
            g->print(label, counter++);
            delete g;
        } else {
            std::cout <<"==============" <<"PrintandoGrafo "<<counter++<<"==============\n";
            std::cout<<label<<": []\n";
            std::cout <<"=============="<<"=============="<<"==============\n";
            }
    }
}

//gera as labels para os vertices de cada grafo
// Exemplo: temos um grafo com 4 vertices (0,1,2,3) queremos reduzi-lo para tres
// essa funcao gerara todas as labels possiveis (0,1,2),(0,1,3),(0,2,3),(1,2,3) e envia elas para a funcao geraSubgrafos
void allOpt(int last,int tam, int vertice, std::string str){
    int p = str.size();
    int m = 0;
    if(last != -1)m = last;
    if(p < tam ){
        for(int i = m; i < vertice; i++){
            std::string temp = "";
            temp += (i+48);
            if(str.find(temp) == -1)allOpt(i,tam,vertice, str + temp);
        }
    } else {
        GeraSubgrafos(tam, "", str);
    }
}


//repete n vezes
void labelGen(int vertice){
    counter = 1;
    int nums = vertice;
    while(nums > 0){
        allOpt(-1,nums,vertice, "");
        nums--;
    }
}




