#include "Vetores.h"

// #define DEBUG

Vetores::Vetores(){
}

Vetores::Vetores(unsigned int qtdElem){
    dimensao(qtdElem);
}

void Vetores::dimensao(unsigned int qtdElem){
    numElem = qtdElem;

    #ifdef DEBUG
    cout << "\nQuantidade de elementos: " << qtdElem << "\n";
    #endif

    // Aloca Dinamicamente o Espaço de Memória necessário para o Vetor "vet"
    vet = (float*)malloc(qtdElem * sizeof(float));
}

void Vetores::setVetor(unsigned int indice, float valor){         // Inserir dados do Vetor
    vet[indice] = valor;
}

float Vetores::getValor(unsigned int indice){
    return vet[indice];
}