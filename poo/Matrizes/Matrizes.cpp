#include "Matrizes.h"

Matrizes::Matrizes(){
}

Matrizes::Matrizes(unsigned int linhas, unsigned int colunas){
    defMatriz(linhas, colunas);
}

void Matrizes::defMatriz(unsigned int qtdLinhas, unsigned int qtdColunas){
    cout << "\nLinhas: " << qtdLinhas;
    cout << "\nColunas: " << qtdColunas;
    // // Alocação Dinâmica de Memória para Matriz de qualquer ordem =====================================
    // this->matriz = new float **matriz = (float**)malloc(qtdLinhas * sizeof(float*));
    // for (int i=0; i<(qtdLinhas); i++){
    //     matriz[i]=(float*)malloc(qtdColunas * sizeof(float));
    // }
}