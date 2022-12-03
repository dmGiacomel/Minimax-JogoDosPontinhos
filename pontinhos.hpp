#ifndef PONTINHOS_HPP
#define PONTINHOS_HPP
#include <iostream>
#include "general_helper.hpp"
#include "pontinhos_helper.hpp"
#include <stdlib.h>
#include <map>

/*const int L = 0;
const int T = 1;
const int R = 2;
const int B = 3;*/

typedef struct pontinho{
    //std::vector<bool> arestas_com_vizinho;
    //bool direcionais[4];
    std::map<char, char> direcionais = {{'L', 'f'}, 
                                        {'T', 'f'},
                                        {'R', 'f'},
                                        {'B', 'f'}};

} pontinho;

class Pontinhos{
private:
    pontinho **grid;
    int **closed_squares;
    int linhas, colunas;

public:
    Pontinhos(int linhas, int colunas);
    void fazerJogada(int l1, int c1, int l2, int c2);
    int getLinhas();
    int getColunas();
};

#endif