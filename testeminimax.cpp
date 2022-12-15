#include <iostream>
#include "pontinhos.hpp"
#include "matriz.hpp"
#include "pontinhos_helper.hpp"
#include <vector>

int main(int argc, char **argv)
{

    std::vector<Pontinhos *> filhos;
    Pontinhos *pontinhos = new Pontinhos(3, 3);
    pontinhos->fazerJogada(-1, 1, 1, 1, 0);
    Matriz<char> *view = pontinhos->generateView();
    view->printMatriz();
    filhos = PontinhosHelper::gerarFilhos(pontinhos);



    for(std::vector<Pontinhos*>::iterator it = filhos.begin(); it != filhos.end(); it++){
        view = (*it)->generateView();
        view->printMatriz();

    }

    return 0;
}