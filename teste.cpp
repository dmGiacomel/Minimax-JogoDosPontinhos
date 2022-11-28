#include <iostream>
#include "pontinhos.hpp"

int main(){
    
    pontinho **pontos; 
    int **a;

    pontos = alocarMatriz<pontinho>(3,3);
    liberarMatriz<pontinho>(pontos);

    a = alocarMatriz<int>(3,3);
    liberarMatriz<int>(a);

    return 0;
}