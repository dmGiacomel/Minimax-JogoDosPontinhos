#include <iostream>
#include <vector>
#include <stdlib.h>
#include <map>

/*const int L = 0;
const int T = 1;
const int R = 2;
const int B = 3;*/

typedef struct pontinho{
    //std::vector<bool> arestas_com_vizinho;
    //bool direcionais[4];
    std::map<char, char> direcionais = {{'L', 'f'}, 
                                        {'T', 'f'},
                                        {'R', 'f'},
                                        {'B', 'f'}};

} pontinho;

template <typename datatype> 
datatype** alocarMatriz(int linhas, int colunas){
    
    datatype **M;

    M = (datatype**)malloc(sizeof(datatype*) * linhas);
    M[0] = (datatype*)malloc(linhas * colunas * sizeof(datatype));

    for(int i = 1; i < colunas; i++){
        M[i] = M[0] + i * colunas;
    }

    return M;
}

template <typename datatype> 
void liberarMatriz(datatype **M){
    free(M[0]);
    free(M);
}

class Pontinhos{
private:
    pontinho **grid;
    int **closed_squares;
    int m, n;

public:
    Pontinhos(int linhas, int colunas);
    void fazerJogada(int l1, int c1, int l2, int c2);
};

Pontinhos::Pontinhos(int linhas, int colunas){
    this->m = linhas;
    this->n = colunas;
    this->grid = alocarMatriz<pontinho>(this->m, this->n);
    this->closed_squares = alocarMatriz<int>(this->m - 1, this->n - 1);

    for(int i = 0; i < m; i++){
        grid[i][0].direcionais['L'] = 'n'; 
        grid[i][n - 1].direcionais['R'] = 'n';
    }

    for(int j = 0; j < n; j++){
        grid[0][j].direcionais['T'] = 'n';
        grid[m - 1][j].direcionais['B'] = 'n';
    }
}

void Pontinhos::fazerJogada(int l1, int c1, int l2, int c2){
     // verifica se a jogada é válida (distância máxima de 1)
     if((abs(l1 - l2) || abs(c1 - c2)) > 1){
        std::cout << "Jogada inválida, você deve conectar apenas dois pontos" << std::endl;
        // fazer jogada novamente
     }

     // escreve jogada no grid (atualizar direções dos pares ordenados)
    
        // se a primeira linha for maior que a segunda, deve haver conexão do TOP e BOTTOM, respectivamente, para os pontos
        if((l1 > l2) && (c1 == c2)){
            grid[l1][c1].direcionais['T'] = 'v';
            grid[l2][c2].direcionais['B'] = 'v';
        }

        // se a segunda linha for maior que a primeira, deve haver conexão do BOTTOM e TOP, respectivamente, para os pontos
        else if((l2 > l1) && (c1 == c2)){
            grid[l1][c1].direcionais['B'] = 'v';
            grid[l2][c2].direcionais['T'] = 'v';
        }

        // se a primeira coluna for maior que a segunda, deve haver conexão do LEFT e RIGHT, respectivamente, para os pontos
        else if((c1 > c2) && (l1 == l2)){
            grid[l1][c1].direcionais['L'] = 'v';
            grid[l2][c2].direcionais['R'] = 'v';
        }

        // se a segunda coluna for maior que a primeira, deve haver conexão do RIGHT e LEFT, respectivamente, para os pontos
        else if((c2 > c1) && (l1 == l2)){
            grid[l1][c1].direcionais['R'] = 'v';
            grid[l2][c2].direcionais['L'] = 'v';
        }

        
    // verifica se fechou quadrado, para atualizar a matriz de quadrados fechados (se necessário)
        // como fazer isso pelo amor de deus

    // se fechou, verifica vitória
        // como fazer isso pelo amor de deus 2

    // se não há vitória, o jogador que fechou quadrado joga novamente
        // chama função de fazerJogada novamente, nao to colocando ainda por medo do codigo se rodar sozinho e gerar uma recursao fudida e quebrar tudo
    
}

class PontinhoView{
   // atributos
private:
    int m, n; // linhas e colunas da matriz

    // métodos

public:
    PontinhoView(int m, int n);

    ~PontinhoView();

    char** generateView(Pontinhos p_grid);
};

PontinhoView::PontinhoView(int m, int n){
    this-> m = m;
    this->n = n;
}

char** PontinhoView::generateView(Pontinhos p_grid){
    int char_colunas = 2 + n + (n - 1) * 3;
    int char_linhas = 2 * m;
    
    // --------- alocando matriz de caracteres que será retornada ------
    char** matriz_Dispor = (char**)malloc(char_linhas * sizeof(char*));

    for(int i = 0; i < char_colunas; i++){
        matriz_Dispor[i] = (char*)malloc(sizeof(char));
    }
    // -----------------------------------------------------------------

    for(int i = 0; i < char_linhas; i++){
        for(int j = 0; j < char_colunas; j++){
            int aux = 0;
            
            // se estiver na primeira linha e primeira coluna, precisa só deixar um espaço
            if(i == 0 && j == 0){
                std::cout << " ";
                matriz_Dispor[i][j] = ' ';
            }

            // caso esteja na primeira linha, mas em posições cuja posição anterior tenha mod 4 == 0, deve escrever
            // o número de visualização da coluna
            else if((i == 0) && ((j-1) % 4 == 0)){
                std::cout << aux;
                matriz_Dispor[i][j] = aux;
            }

            // se nao for o caso, caso esteja em uma linha ímpar e na primeira coluna, deve
            // dispor o número de visualização da linha
            else if(i % 2 != 0 && j == 0){
                std::cout << i;
                matriz_Dispor[i][j] = i;
            }

            // se estiver em uma linha ímpar E estiver em uma coluna onde está disposto o número da coluna, deve
            // escrever o "pontinho", através do caractere '*'
            else if(i % 2 != 0 && ((j-1) % 4 == 0)){
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
}

/*
      0   1   2   3
    0 *---*   *   *
      | D |
    1 *---*   *   *

    2 *   *   *   *

    3 *   *   *   *

   caracteres linha = 2 do label da esquerda
            + m dos pontinhos
            + (m-1) * 3 dos tracinhos

    caracteres coluna = 1 label de cima
                        + m dos pontinhos
                        + (m-1) dos tracinhos
*/