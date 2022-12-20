#include <iostream>
#include "pontinhos.hpp"
#include "matriz.hpp"
#include "objetojs.hpp"

int main(int argc, char **argv){
    int linhas_pontinhos = atoi(argv[1]);
    int colunas_pontinhos = atoi(argv[2]);

    Pontinhos *pontinhos = new Pontinhos(linhas_pontinhos, colunas_pontinhos);
    Matriz<char> *matriz = pontinhos->generateView();
    matriz->printMatriz();

    int player = 0, aux = 0;
    int status = 0;
    while((status == 0) || (status == 1)){
        
        if(aux % 2 == 0){
            player = PLAYER_1;
        }else{
            player = PLAYER_2;  
        }

        system("clear");
        matriz->printMatriz();
        std::cout << "---------------PLAYER'S "<< abs(player) << " TURN------------------\n";
        //status = pontinhos->fazerJogada(player, jl1, jc1, jl2, jc2);
        std::cout << "\n";
        matriz = pontinhos->generateView();
        matriz->printMatriz();
        while(status == 1){
            //um dos players fechou um quadrado, mas nãoa cabou o jogo
            //std::cin >> jl1 >> jc1 >> jl2 >> jc2;
            //status = pontinhos->fazerJogada(player, jl1, jc1, jl2, jc2);
            //matriz = pontinhos->generateView();
            //matriz->printMatriz();
        }

        if(status == PLAYER_1){
            std::cout << "Player 1 venceu!\n";
        }
        if(status == PLAYER_2){
            std::cout << "Player 2 venceu!\n";
        }

        aux++;
    }

    delete(pontinhos);
    //delete(matriz);
    return 0;
}