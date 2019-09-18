// Projeto Relação de Dependência - Álgebra Linear
// Arthur Castro
// Setembro de 2019

#include <iostream>
using namespace std;

// #include "..\..\Vetores\Vetores.h"

unsigned int elementos, qtdVetores;

void apresentacao();
void cabecalho();

// Função Principal
int main() {
    apresentacao();

    cabecalho();
    cout << "\n\t\xAF Insira a quantidade de vetores da lista: ";
    cin >> qtdVetores;
    cout << "\n\t\xAF Insira a quantidade de elementos por vetor: ";
    cin >> elementos; 


    // // Aloca dinamicamente o espaço necessário na memória para guardar os vetores
    // // Vetores* arrayVetores = (Vetores*)malloc(qtdVetores * sizeof(Vetores));
    // // Sabendo que um vetor é dimensionado como float** vetor = (float*)malloc(qtdElem * sizeof(float));
    // Vetores* arrayVetores = (Vetores*)malloc(qtdVetores * sizeof(elementos * sizeof(float)));
    //
    // cabecalho();
    // for (int numVetor=1; numVetor<=qtdVetores; numVetor++){
    //     cout << "\n\t\xAF Atribua valores ao vetor " << numVetor << ".\n";
    //     for (int indice=0; indice<elementos; indice++){
    //         float valor;
    //         cout << "\t\t> vetor" << numVetor << "(" << indice+1 << "): ";
    //         cin >> valor;
    //         arrayVetores[indice].setVetor(indice, valor);
    //     }
    // }


    // // Aloca Dinamicamente o Espaço de Memória necessário
    // float** arrayVetores = (float**)malloc(qtdVetores * sizeof(float*));
    // for (int i=0; i<qtdVetores; i++){
    //     arrayVetores[i]=(float*)malloc(elementos * sizeof(float));
    //     for (int j=0; j<elementos; j++){
    //         arrayVetores[i][j] = 0;
    //     }
    // }

    float** arrayVetores = (float**)malloc(qtdVetores * sizeof(float*));
    for (int i=0; i<qtdVetores; i++){
        arrayVetores[i]=(float*)malloc(elementos * sizeof(float));
    }

    cabecalho();
    for (int numVetor=1; numVetor<=qtdVetores; numVetor++){
        cout << "\n\t\xAF Atribua valores ao vetor " << numVetor << ".\n";
        for (int indice=1; indice<=elementos; indice++){
            float valor;
            cout << "\t\t> vetor" << numVetor << "(" << indice << "): ";
            cin >> valor;
            arrayVetores[numVetor-1][indice-1] = valor;
        }
    }

    // cabecalho();
    // cout << "\n\t\xAF Os vetores\n\n";
    // for(int indice=0; indice<elementos; indice++){
    //     cout << "\t\tu(" << indice+1 << "): " << vetorU.getValor(indice) << "\n";
    // }
    // cout << "\n";
    // for(int indice=0; indice<elementos; indice++){
    //     cout << "\t\tv(" << indice+1 << "): " << vetorV.getValor(indice) << "\n";
    // }

    // cout << "\n\t   sao " << "dependencia\n\n\t";

    system("pause");
    return 0;
}

// Funções Auxiliares
void apresentacao(){
    system("cls");
    cout << "================================================================================\n";
    cout << "|                                                                              |\n";
    cout << "|                                                                              |\n";
    cout << "|                        PROJETO RELACAO DE DEPENDENCIA                        |\n";
    cout << "|                                                                              |\n";
    cout << "|                Classifica uma lista de vetores como LI ou LD                 |\n";
    cout << "|                                                                              |\n";
    cout << "|                   ----------------------------------------                   |\n";
    cout << "|                                                                              |\n";
    cout << "|                            Arthur Lima de Castro                             |\n";
    cout << "|                              Setembro de 2019                                |\n";
    cout << "|                           Algebra Linear - POLI/UPE                          |\n";
    cout << "|                     Prof.: Paulo Hugo Espirito Santo Lima                    |\n";
    cout << "|                                                                              |\n";
    cout << "================================================================================\n\n";
    system("pause");
}

void cabecalho(){
    system("cls");
    cout << "================================================================================\n";
    cout << "|                        PROJETO RELACAO DE DEPENDENCIA                        |\n";
    cout << "================================================================================\n\n";
}