#include <iostream>
#include "matriz.hpp"
#include <vector>
#include "pontinhos.hpp"


int main(int argc, char **argv)
{

    std::vector<Pontinhos *> filhos;
    Pontinhos *pontinhos = new Pontinhos(3, 3);
    pontinhos->fazerJogada(-1, 0, 0, 1, 0);
    Matriz<char> *view = pontinhos->generateView();
    view->printMatriz();
    filhos = pontinhos->gerarFilhos();

    std::cout << pontinhos->gerarFilhos().size() << "\n";

    for(std::vector<Pontinhos*>::iterator it = filhos.begin(); it != filhos.end(); it++){
        std::cout << "to aquii\n";
        view = (*it)->generateView();
        view->printMatriz();
    }

    return 0;
}