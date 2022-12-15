#ifndef PONTINHOS_HELPER_HPP
#define PONTINHOS_HELPER_HPP
#include "pontinhos.hpp"
#include <iostream>
#include "matriz.hpp"
class PontinhosHelper{

public:
    static Matriz<char>* generateView(Pontinhos *p_grid);
};

/* 
ʲ/ᶦ ⁰¹²³⁴⁵⁶⁷⁸⁹⁰¹²³⁴ 
  ⁰   0   1   2   3
  ¹ 0 *---*   *   *
  ²   | D | 
  ³ 1 *---*   *   *
  ⁴             
  ⁵ 2 *   *   *   *
  ⁶         
  ⁷ 3 *   *   *   *

   caracteres colunas = 2 do label da esquerda
            + m dos pontinhos
            + (m-1) * 3 dos tracinhos

    caracteres linhas = 1 label de cima
                        + m dos pontinhos
                        + (m-1) dos tracinhos
*/

//-------------NÃO COMPLETAMENTE TESTADA , MAS PARECE ESTAR EM ORDEM-------------
Matriz<char>* PontinhosHelper::generateView(Pontinhos *p_grid){

    //determinacao das dimensoes
    int colunas = 2 + p_grid->getColunas() + (p_grid->getColunas() - 1) * 3;
    int linhas = 1 + 2 * p_grid->getLinhas() - 1;

    //alocacao da matriz de chars;
    Matriz<char> *view = new Matriz<char>(linhas, colunas); 

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            view->matriz[i][j] = ' ';
        }
    }

    //escrita dos labels e dos pontinhos como *
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){

            //setando os labels na primeira linha
            //linha 0 e coluna - 2 é múltipla de 4 
            if((i == 0) && (((j - 2) % 4) == 0)){
                view->matriz[i][j] = (j - 2)/4 + 0x30;
            }

            //setando os labels na primeira coluna
            //coluna 0 e linha - 1 é par
            if((j == 0) && (((i - 1) % 2) == 0)){
                view->matriz[i][j] = (i - 1)/2 + 0x30;
            }

            //se não vai escrever labels
            if((i != 0) && (j != 0)){

                //escrever os *
                //se a coluna é par e não múltipla de 4 e linha não é par
                if((j % 2 == 0) && (j % 4 != 0) && (i % 2 != 0)){
                    view->matriz[i][j] = '*';
                }
            }

        }
    }

    //escrita das arestas verticais
    //Verificação do direcional B nos pontinhos das (linhas-1) linhas
    for(int i = 0; i < p_grid->getLinhas() - 1; i++){
        for (int j = 0; j < p_grid->getColunas(); j++){

            if(p_grid->getPontinhoAt(i,j).direcionais[B] == 'v'){
                view->matriz[i * 2 + 2][j * 4 + 2] = '|';
            }
        }
    }

    //escrita das arestas horizontais
    //Verificacao do direcional R nos pontinhos das (colunas -1) colunas
    for (int i = 0; i < p_grid->getLinhas(); i++){
        for(int j = 0; j < p_grid->getColunas() - 1; j++){
            if(p_grid->getPontinhoAt(i,j).direcionais[R] == 'v'){
                view->matriz[i * 2 + 1][j * 4 + 3] = '-';
                view->matriz[i * 2 + 1][j * 4 + 4] = '-';
                view->matriz[i * 2 + 1][j * 4 + 5] = '-';
            }
        }
    }

    //escrita dos numerinhos do meio
    for(int i = 0; i < p_grid->getLinhas() - 1; i++){
        for(int j = 0; j < p_grid->getColunas() - 1; j++){

            int aux = p_grid->getQuadradoAt(i, j); 
            if(aux == PLAYER_1){
                view->matriz[(i + 1) * 2][j * 4 + 4] = '1';
            }
            if(aux == PLAYER_2){
                view->matriz[(i + 1) * 2][j * 4 + 4] = '2';
            }
        }
    }



    return view; 
}



#endif