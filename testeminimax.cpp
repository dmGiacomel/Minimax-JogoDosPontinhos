#include <iostream>
#include "matriz.hpp"
#include <vector>
#include "pontinhos_helper.hpp"
#include "pontinhos.hpp"



int main(int argc, char **argv)
{

    std::vector<resultado> filhos;
    Pontinhos *pontinhos = new Pontinhos(3, 3);
    pontinhos->fazerJogada(-1, 0, 0, 0, 1);
    Matriz<char> *view = pontinhos->generateView();
    std::cout << "-----------Primeira jogada-----------\n";

    view->printMatriz();

    res_minimax temp = PontinhosHelper::minimax({pontinhos, {0, 0}, {0, 0}}, true);

    pontinhos->fazerJogada(-2, temp.result.p1_gerador.linha, temp.result.p1_gerador.coluna, 
                            temp.result.p2_gerador.linha, temp.result.p2_gerador.coluna);

    view = pontinhos->generateView();
    std::cout << "-----------Segunda jogada-----------\n";
    view->printMatriz();

    return 0;
}