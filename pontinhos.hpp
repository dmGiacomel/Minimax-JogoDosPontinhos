#ifndef PONTINHOS_HPP
#define PONTINHOS_HPP
#include <vector>
#include "general_helper.hpp"
#include "matriz.hpp"

const int L = 0;
const int T = 1;
const int R = 2;
const int B = 3;

typedef struct pontinho{
    //std::vector<bool> arestas_com_vizinho;
    //bool direcionais[4];
    char direcionais[4] = {'f', 'f', 'f', 'f'};
} pontinho;

class Pontinhos{
private:
    Matriz<pontinho> *grid;
    Matriz<int> *closed_squares;
    int linhas, colunas;
    bool jogadaValida(int l1, int c1, int l2, int c2);

public:
    Pontinhos(int linhas, int colunas);
    ~Pontinhos();
    void fazerJogada(int l1, int c1, int l2, int c2);
    int getLinhas();
    int getColunas();
    pontinho getPontinhoAt(int linha, int coluna);
    Matriz<char>* generateView();
    
};

#endif