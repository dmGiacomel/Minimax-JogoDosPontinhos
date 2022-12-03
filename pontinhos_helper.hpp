#ifndef PONTINHOS_HELPER_HPP
#define PONTINHOS_HELPER_HPP
#include "pontinhos.hpp"
#include <iostream>

class PontinhosHelper{
    
public:
    static char** generateView(Pontinhos p_grid){

        int char_colunas = 2 + p_grid.getColunas() + (p_grid.getColunas() - 1) * 3;
        int char_linhas = 2 * p_grid.getLinhas();
        
        // --------- alocando matriz de caracteres que será retornada ------
        char** matriz_Dispor = (char**)malloc(char_linhas * sizeof(char*));

        for(int i = 0; i < char_colunas; i++){
            matriz_Dispor[i] = (char*)malloc(sizeof(char));
        }
        // -----------------------------------------------------------------

        for(int i = 0; i < char_linhas; i++){
            for(int j = 0; j < char_colunas; j++){
                int aux = 0;
                
                // se estiver na primeira linha e primeira coluna ou na primeira linha e na segunda coluna, precisa só deixar um espaço
                if((i == 0 && j == 0) || (i == 0 && j == 1) ){
                    std::cout << " ";
                    matriz_Dispor[i][j] = ' ';
                }

                // caso esteja na primeira linha, mas em posições que sejam pares, mas não com mod 4 == 0, deve escrever
                // o número de visualização da coluna
                else if((i == 0) && // par          // mas não divisível por 4
                                    ((j % 2 == 0) && (j % 4 != 0))){
                    std::cout << aux;
                    matriz_Dispor[i][j] = aux;
                    aux++;
                }

                // se nao for o caso, caso esteja em uma linha ímpar e na primeira coluna, deve
                // dispor o número de visualização da linha
                else if(i % 2 != 0 && j == 0){
                    std::cout << i;
                    matriz_Dispor[i][j] = i;
                }

                // se estiver em uma linha ímpar E estiver em uma coluna onde está disposto o número da coluna, deve
                // escrever o "pontinho", através do caractere '*'
                else if(i % 2 != 0 && // par          // mas não divisível por 4
                                    ((j % 2 == 0) && (j % 4 != 0))){
                    std::cout << "*";
                    matriz_Dispor[i][j] = '*';
                    //if(p_grid->) 
                        // nao sei fazer essa parte aqui
                        // precisa verificar se o pontinho tem conexão com a direita, para
                        // escrever '---' para demonstrar a conexão dos pontinhos
                        // mas não to conseguindo acessar as direções do pontinho
                }
            }
            
            std::cout << std::endl;
        }

        return matriz_Dispor;
    }
};

#endif