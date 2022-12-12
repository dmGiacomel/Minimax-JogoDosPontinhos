#include <iostream>
#include "pontinhos.hpp"
#include "matriz.hpp"

int main(int argc, char **argv){

    int linhas_pontinhos = atoi(argv[1]);
    int colunas_pontinhos = atoi(argv[2]);

    Pontinhos *pontinhos = new Pontinhos(linhas_pontinhos, colunas_pontinhos); 
    Matriz<char>* matriz = pontinhos->generateView();
    matriz->printMatriz();
    delete(matriz);

    return 0;
}