#ifndef PONTINHOS_CPP
#define PONTINHOS_CPP
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "pontinhos.hpp"
#include "pontinhos_helper.hpp"
#include "matriz.hpp"

int Pontinhos::getLinhas(){
    return this->linhas;    
} 

int Pontinhos::getColunas(){
    return this->colunas;
}

Matriz<char>* Pontinhos::generateView(){
    return PontinhosHelper::generateView(this);
}

pontinho Pontinhos::getPontinhoAt(int linha, int coluna){
    return grid->matriz[linha][coluna];
}

Pontinhos::Pontinhos(int linhas, int colunas){

    this->linhas = linhas;
    this->colunas = colunas;

    grid = new Matriz<pontinho>(linhas, colunas);
    closed_squares = new Matriz<int>(linhas - 1, colunas - 1);

    for(int i = 0; i < linhas; i++){
        grid->matriz[i][0].direcionais[L] = 'n';
        grid->matriz[i][colunas - 1].direcionais[R] = 'n';
    }


    for(int j = 0; j < colunas; j++){
        grid->matriz[0][j].direcionais[T] = 'n';
        grid->matriz[linhas - 1][j].direcionais[B] = 'n';
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
            grid->matriz[l1][c1].direcionais[T] = 'v';
            grid->matriz[l2][c2].direcionais[B] = 'v';
        }

        // se a segunda linha for maior que a primeira, deve haver conexão do BOTTOM e TOP, respectivamente, para os pontos
        else if((l2 > l1) && (c1 == c2)){
            grid->matriz[l1][c1].direcionais[B] = 'v';
            grid->matriz[l2][c2].direcionais[T] = 'v';
        }

        // se a primeira coluna for maior que a segunda, deve haver conexão do LEFT e RIGHT, respectivamente, para os pontos
        else if((c1 > c2) && (l1 == l2)){
            grid->matriz[l1][c1].direcionais[L] = 'v';
            grid->matriz[l2][c2].direcionais[R] = 'v';
        }

        // se a segunda coluna for maior que a primeira, deve haver conexão do RIGHT e LEFT, respectivamente, para os pontos
        else if((c2 > c1) && (l1 == l2)){
            grid->matriz[l1][c1].direcionais[R] = 'v';
            grid->matriz[l2][c2].direcionais[L] = 'v';
        }

    // verifica se fechou quadrado, para atualizar a matriz de quadrados fechados (se necessário)
        // como fazer isso pelo amor de deus

    // se fechou, verifica vitória
        // como fazer isso pelo amor de deus 2

    // se não há vitória, o jogador que fechou quadrado joga novamente
        // chama função de fazerJogada novamente, nao to colocando ainda por medo do codigo se rodar sozinho e gerar uma recursao fudida e quebrar tudo
    
}

Pontinhos::~Pontinhos(){
    delete(grid);
    delete(closed_squares);
}


#endif