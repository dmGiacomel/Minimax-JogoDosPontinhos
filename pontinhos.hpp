#include <iostream>
#include <vector>
#include <stdlib.h>

typedef struct pontinho{
    std::vector<bool> arestas_com_vizinho;
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

class PontinhoView{
   // char 
};

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

class Pontinhos{
private:
    pontinho **grid;

public:
    Pontinhos(int linhas, int colunas);

};

