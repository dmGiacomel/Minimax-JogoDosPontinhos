#ifndef GENERAL_HELPER_HPP
#define GENERAL_HELPER_HPP

class GeneralHelper{

public: 
    template <typename datatype> static datatype** alocarMatriz(int linhas, int colunas);
    template <typename datatype> static void liberarMatriz(datatype **M);
};


template <typename datatype>
datatype** GeneralHelper::alocarMatriz(int linhas, int colunas){

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

#endif