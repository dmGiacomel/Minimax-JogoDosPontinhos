#include <iostream>
#include "matriz.hpp"
#include <vector>
#include "pontinhos_helper.hpp"
#include "pontinhos.hpp"



int main(int argc, char **argv)
{

    std::vector<res_minimax> filhos;
    Pontinhos *pontinhos = new Pontinhos(3, 3);
    pontinhos->fazerJogada(-1, 2, 2, 1, 2);
    Matriz<char> *view = pontinhos->generateView();
    std::cout << "-----------Primeira jogada-----------\n";
    view->printMatriz();
    filhos = PontinhosHelper::gerarFilhos(pontinhos, PLAYER_2);

    std::cout << filhos.size() << "\n";
    int i = 0;
    for(std::vector<res_minimax>::iterator it = filhos.begin(); it != filhos.end(); it++, i++){
        std::cout << "Filho" << i << "\n";
        view = (*it).result.filho->generateView();
        view->printMatriz();
    }

    pontinhos->fazerJogada(-1, 0, 0, 1, 0);
    view = pontinhos->generateView();
    std::cout << "-----------Segunda jogada-----------\n";
    view->printMatriz();
    filhos = PontinhosHelper::gerarFilhos(pontinhos, PLAYER_2);

    std::cout << filhos.size() << "\n";

    i = 0;
    for(std::vector<res_minimax>::iterator it = filhos.begin(); it != filhos.end(); it++, i++){
        std::cout << "Filho" << i << "\n";
        view = (*it).result.filho->generateView();
        view->printMatriz();
    }

    return 0;
}