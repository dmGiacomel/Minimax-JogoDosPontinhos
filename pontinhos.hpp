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
    std::map<char, char> direcionais = {{'L', 'f'}, 
                                        {'T', 'f'},
                                        {'R', 'f'},
                                        {'B', 'f'}};

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
    int **closed_squares;
    int m, n;

public:
    Pontinhos(int linhas, int colunas);
    void fazerJogada(int l1, int c1, int l2, int c2);
};

Pontinhos::Pontinhos(int linhas, int colunas){
    this->m = linhas;
    this->n = colunas;
    this->grid = alocarMatriz<pontinho>(this->m, this->n);
    this->closed_squares = alocarMatriz<int>(this->m - 1, this->n - 1);

    for(int i = 0; i < m; i++){
        grid[i][0].direcionais['L'] = 'n'; 
        grid[i][n - 1].direcionais['R'] = 'n';
    }

    for(int j = 0; j < n; j++){
        grid[0][j].direcionais['T'] = 'n';
        grid[m - 1][j].direcionais['B'] = 'n';
    }
}

void Pontinhos::fazerJogada(int l1, int c1, int l2, int c2){
     // verifica se a jogada é válida (distância máxima de 1)
     if((abs(l1 - l2) || abs(c1 - c2)) > 1){
        std::cout << "Jogada inválida, você deve conectar apenas dois pontos" << std::endl;
        // fazer jogada novamente
     }

     // escreve jogada no grid (atualizar direções dos pares ordenados)
        if((l1 > l2) && (c1 == c2)){
            grid[l1][c1].direcionais['T'] = 'v';
            grid[l2][c2].direcionais['B'] = 'v';
        }
        else if((l2 > l1) && (c1 == c2)){
            grid[l1][c1].direcionais['B'] = 'v';
            grid[l2][c2].direcionais['T'] = 'v';
        }
        else if((c1 > c2) && (l1 == l2)){
            grid[l1][c1].direcionais['L'] = 'v';
            grid[l2][c2].direcionais['R'] = 'v';
        }
        else if((c2 > c1) && (l1 == l2)){
            grid[l1][c1].direcionais['R'] = 'v';
            grid[l2][c2].direcionais['L'] = 'v';
        }
    // verifica se fechou quadrado, para atualizar a matriz de quadrados fechados (se necessário)

    // se fechou, verifica vitória

    // se não há vitória, o jogador que fechou quadrado joga novamente
    
}

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