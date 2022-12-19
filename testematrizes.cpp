#include <iostream>
#include "matriz.hpp"
#include <vector>
#include "pontinhos_helper.hpp"
#include "pontinhos.hpp"



int main (){
    Pontinhos *p = new Pontinhos(2, 3);

    p->fazerJogada(-1, 0, 0, 0, 1);
    p->fazerJogada(-1, 0, 0, 1, 0);
    p->fazerJogada(-1, 1, 0, 1, 1);
    p->fazerJogada(-1, 1, 2, 1, 1);
    p->fazerJogada(-1, 0, 1, 0, 2);


    std::vector<resultado> res = PontinhosHelper::gerarFilhos(p, -1);

    for(std::vector<resultado>::iterator it = res.begin(); it != res.end(); it++){
        Matriz<char> *view  = PontinhosHelper::generateView(it->filho);

        view->printMatriz();
        std::cout << std::endl;
    }
}