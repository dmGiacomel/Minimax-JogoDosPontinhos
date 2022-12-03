#ifndef PONTINHOS_CPP
#define PONTINHOS_CPP
#include <iostream>
#include <stdlib.h>
#include <map>
#include "pontinhos.hpp"
#include "general_helper.hpp"

Pontinhos::Pontinhos(int linhas, int colunas){
    this->linhas = linhas;
    this->colunas = colunas;
    this->grid = GeneralHelper::alocarMatriz<pontinho>(this->linhas, this->colunas);
    this->closed_squares = GeneralHelper::alocarMatriz<int>(this->linhas - 1, this->colunas - 1);

    for(int i = 0; i < linhas; i++){
        grid[i][0].direcionais['L'] = 'n'; 
        grid[i][colunas - 1].direcionais['R'] = 'n';
    }

    for(int j = 0; j < colunas; j++){
        grid[0][j].direcionais['T'] = 'n';
        grid[linhas - 1][j].direcionais['B'] = 'n';
    }
}

void Pontinhos::fazerJogada(int l1, int c1, int l2, int c2){
     // verifica se a jogada é válida (distância máxima de 1)
     if(((abs(l1 - l2) > 1) || (abs(c1 - c2)) > 1)){
        std::cout << "Jogada inválida, você deve conectar apenas dois pontos" << std::endl;
        // fazer jogada novamente
     }

     // escreve jogada no grid (atualizar direções dos pares ordenados)
    
        // se a primeira linha for maior que a segunda, deve haver conexão do TOP e BOTTOM, respectivamente, para os pontos
        if((l1 > l2) && (c1 == c2)){
            grid[l1][c1].direcionais['T'] = 'v';
            grid[l2][c2].direcionais['B'] = 'v';
        }

        // se a segunda linha for maior que a primeira, deve haver conexão do BOTTOM e TOP, respectivamente, para os pontos
        else if((l2 > l1) && (c1 == c2)){
            grid[l1][c1].direcionais['B'] = 'v';
            grid[l2][c2].direcionais['T'] = 'v';
        }

        // se a primeira coluna for maior que a segunda, deve haver conexão do LEFT e RIGHT, respectivamente, para os pontos
        else if((c1 > c2) && (l1 == l2)){
            grid[l1][c1].direcionais['L'] = 'v';
            grid[l2][c2].direcionais['R'] = 'v';
        }

        // se a segunda coluna for maior que a primeira, deve haver conexão do RIGHT e LEFT, respectivamente, para os pontos
        else if((c2 > c1) && (l1 == l2)){
            grid[l1][c1].direcionais['R'] = 'v';
            grid[l2][c2].direcionais['L'] = 'v';
        }


    // verifica se fechou quadrado, para atualizar a matriz de quadrados fechados (se necessário)
        // como fazer isso pelo amor de deus

    // se fechou, verifica vitória
        // como fazer isso pelo amor de deus 2

    // se não há vitória, o jogador que fechou quadrado joga novamente
        // chama função de fazerJogada novamente, nao to colocando ainda por medo do codigo se rodar sozinho e gerar uma recursao fudida e quebrar tudo
    
}


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

   caracteres linha = 2 do label da esquerda
            + m dos pontinhos
            + (m-1) * 3 dos tracinhos

    caracteres coluna = 1 label de cima
                        + m dos pontinhos
                        + (m-1) dos tracinhos
*/
#endif