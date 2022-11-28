#include <iostream>
#include <vector>
#include <stdlib.h>
#include <map>

const int L = 0;
const int T = 1;
const int R = 2;
const int B = 3;

typedef struct pontinho{
    //std::vector<bool> arestas_com_vizinho;
    //bool direcionais[4];
    std::map<char, bool> direcionais = {{'L', false}, 
                                        {'T', false},
                                        {'R', false},
                                        {'B', false}};

} pontinho;

/*
      0   1   2   3
    0 *---*   *   *
      | D |
    1 *---*   *   *

    2 *   *   *   *

    3 *   *   *   *

   caracteres linha = 2 do label da esquerda
            + m dos pontinhos
            + (m-1) * 3 dos tracinhos

    caracteres coluna = 1 label de cima
                        + m dos pontinhos
                        + (m-1) dos tracinhos
*/

class Pontinhos{
private:
    pontinho **grid;
    int m, n;

public:
    Pontinhos(int linhas, int colunas);

};

class PontinhoView{
   // atributos
private:
    int m, n; // linhas e colunas da matriz

    // métodos

public:
    PontinhoView(int m, int n);

    ~PontinhoView();

    char** generateView(Pontinhos p_grid);
};

PontinhoView::PontinhoView(int m, int n){
    this-> m = m;
    this->n = n;
}

template <typename datatype> 
datatype** alocarMatriz(int linhas, int colunas){
    
    datatype **M;

    M = (datatype**)malloc(sizeof(datatype*) * linhas);
    M[0] = (datatype*)malloc(linhas * colunas * sizeof(datatype));

    for(int i = 1; i < colunas; i++){
        M[i] = M[0] + i * colunas;
    }

    return M;
}

template <typename datatype> 
void liberarMatriz(datatype **M){
    free(M[0]);
    free(M);
}