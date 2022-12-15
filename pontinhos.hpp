#ifndef PONTINHOS_HPP
#define PONTINHOS_HPP
#include <vector>
#include "general_helper.hpp"
#include "matriz.hpp"

const int L = 0;
const int T = 1;
const int R = 2;
const int B = 3;

const int ZERO_ARESTAS = 0;
const int UMA_ARESTA = 1;
const int DUAS_ARESTAS = 2;
const int TRES_ARESTAS = 3;
const int QUATRO_ARESTAS = 4; 

const int PLAYER_1 = -1;
const int PLAYER_2 = -2;

const bool VITORIA = true;
const bool DERROTA = false;

typedef struct pontinho{
    //std::vector<bool> arestas_com_vizinho;
    //bool direcionais[4];
    char direcionais[4] = {'f', 'f', 'f', 'f'};
} pontinho;

class Pontinhos{
private:
    Matriz<pontinho> *grid;
    Matriz<int> *squares;
    int linhas, colunas;
    bool jogadaValida(int l1, int c1, int l2, int c2);
    bool atualizarMatrizQuadrado(int player, int l1, int c1, int l2, int c2);
    bool acabouJogo();
    int quemGanhou();

public:
    Pontinhos(int linhas, int colunas);
    bool ganhouJogo();
    ~Pontinhos();
    int fazerJogada(int player, int l1, int c1, int l2, int c2);
    int atualizaJogada(int player, int l1, int c1, int l2, int c2);
    int getLinhas();
    int getColunas();
    Matriz<pontinho>* getGrid();
    Matriz<int>* getSquares();
    int getQuadradoAt(int linha, int coluna);
    pontinho getPontinhoAt(int linha, int coluna);
    Matriz<char>* generateView();

    std::vector<Pontinhos*> gerarFilhos();
    
};

#endif