#include <iostream>
#include "pontinhos.hpp"

int main(){
    
    //pontinho **pontos; 
    //int lin, col;
    //lin = 3, col = 3;
    //PontinhoView view = new PontinhoView(lin, col); // que??? deu um erro estranho aqui
    int **a;

    //pontos = alocarMatriz<pontinho>(3,3);
    //liberarMatriz<pontinho>(pontos);

    a = GeneralHelper::alocarMatriz<int>(3,3);

    for(int i =0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << "a[" << i << "][" << j << "] = " << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    GeneralHelper::liberarMatriz<int>(a);

    return 0;
}