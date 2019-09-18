// Projeto Relação de Dependência - Álgebra Linear
// Arthur Castro
// Setembro de 2019

#include <iostream>
using namespace std;

#include "..\..\Vetores\Vetores.h"

unsigned int elementos, qtdVetores;

Vetores arrayVetores[100];          // Forma incorreta!!! Apenas para testes! Usar Alocação Dinâmica de Memória

void apresentacao();
void cabecalho();

// Função Principal
int main() {
    apresentacao();

    cabecalho();
    cout << "\n\t\xAF Insira a quantidade de vetores da lista (max de 100 por enquanto): ";
    cin >> qtdVetores;
    cout << "\n\t\xAF Insira a quantidade de elementos por vetor: ";
    cin >> elementos;

    // Vetores* arrayVetores = (Vetores*)malloc(qtdVetores * sizeof(Vetores));
 
    for(int numVetor=1; numVetor<=qtdVetores; numVetor++){
        arrayVetores[numVetor-1].dimensao(elementos);
    }

    cabecalho();
    for (int numVetor=1; numVetor<=qtdVetores; numVetor++){
        cout << "\n\t\xAF Atribua valores ao vetor " << numVetor << ".\n";
        for (int indice=1; indice<=elementos; indice++){
            float valor;
            cout << "\t\t> vetor" << numVetor << "(" << indice << "): ";
            cin >> valor;
            arrayVetores[numVetor-1].setVetor(indice-1, valor);
        }
    }

    cabecalho();
    cout << "\n\t\xAF Os vetores\n\n";
    for(int numVetor=1; numVetor<=qtdVetores; numVetor++){
        for(int indice=1; indice<=elementos; indice++){
            cout << "\t\t> vetor" << numVetor << "(" << indice << "): " << arrayVetores[numVetor-1].getValor(indice-1) << "\n";
        }
        cout << "\n";
    }
    cout << "\n\t   sao " << "dependencia\n\n\t";

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