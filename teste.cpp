// g++ teste.cpp pontinhos.cpp -o teste
// ./ teste m n

#include <iostream>
#include "pontinhos.hpp"
#include "matriz.hpp"

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        std::cout << "Por favor especifique as dimensões através dos parâmetros de execução.\n";
        exit(1);
    }

    int linhas_pontinhos = atoi(argv[1]);
    int colunas_pontinhos = atoi(argv[2]);
    int jl1, jc1, jl2, jc2;

    Pontinhos *pontinhos = new Pontinhos(linhas_pontinhos, colunas_pontinhos);
    Matriz<char> *matriz = pontinhos->generateView();
   

    int aux = 0, player = 0;

    while(true){
        
        if(aux % 2 == 0){
            player = PLAYER_1;
        }else{
            player = PLAYER_2;  
        }

        system("clear");
        matriz->printMatriz();
        std::cout << "---------------PLAYER'S "<< abs(player) << " TURN------------------\n";


        std::cout << "Informe a jogada que deseja realizar (l1, c1, l2, c2)\n";
        std::cin >> jl1 >> jc1 >> jl2 >> jc2;
        pontinhos->fazerJogada(player, jl1, jc1, jl2, jc2);
        std::cout << "direcional BOTTOM do ponto (1,1)--> " << pontinhos->getPontinhoAt(1, 1).direcionais[B] << std::endl;
        std::cout << "\n";
        matriz = pontinhos->generateView();
        matriz->printMatriz();

        aux++;
    }
    delete (matriz);

    return 0;
}