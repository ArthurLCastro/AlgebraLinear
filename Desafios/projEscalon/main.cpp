// Projeto Escalonamento de Matrizes - Álgebra Linear
// Arthur Castro
// Setembro de 2019

#include <iostream>
using namespace std;

#include "..\..\Matrizes\Matrizes.h"

unsigned int qtdLinhas, qtdColunas;

void apresentacao();
void cabecalho();
void matrizDemo();

Matrizes minhaMatriz;

int main() {
    // Apresentação inicial
    apresentacao();

    // Definição das dimensões da matriz
    cabecalho();
    cout << "\n\t\xAF Insira a quantidade de Linhas da Matriz: ";
    cin >> qtdLinhas;
    cout << "\n\t\xAF Insira a quantidade de Colunas da Matriz: ";
    cin >> qtdColunas;
    minhaMatriz.dimensoes(qtdLinhas, qtdColunas);

    // Insere valores à matriz
    cabecalho();
    cout << "\n\t\xAF Insira os valores da matriz como a do exemplo a seguir:\n\n";
    matrizDemo();
    cout << "\n";
    for (unsigned int linha=1; linha<=qtdLinhas; linha++){
        for (unsigned int coluna=1; coluna<=qtdColunas; coluna++){
            float valor;
            cout << "\t> a(" << linha << " " << coluna << "): ";
            cin >> valor;
            minhaMatriz.setMatriz(linha-1, coluna-1, valor);
        }
    }

    // Imprime a Matriz inserida e a Matriz Escalonada
    cabecalho();
    cout << "\n";
    minhaMatriz.imprimeFormatada();
    cout << "\n\t\xAF A matriz escalonada fica:\n\n";
    minhaMatriz.elimGauss();
    cout << "\n\n\t";
    system("pause");

    return 0;
}

// Funções Auxiliares
void apresentacao(){
    system("cls");
    cout << "================================================================================\n";
    cout << "|                                                                              |\n";
    cout << "|                                                                              |\n";
    cout << "|                         ESCALONAMENTO DE UMA MATRIZ                          |\n";
    cout << "|                                                                              |\n";
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
    cout << "|                         ESCALONAMENTO DE UMA MATRIZ                          |\n";
    cout << "================================================================================\n\n";
}

void matrizDemo(){
    cout << "\t     \xBA a11 a12 a13 ... a1n \xBA \n";
    cout << "\t     \xBA a21 a22 a23 ... a2n \xBA \n";
    cout << "\t M = \xBA a31 a32 a33 ... a3n \xBA \n";
    cout << "\t     \xBA ... ... ... ... ... \xBA \n";
    cout << "\t     \xBA am1 am2 am3 ... amn \xBA \n";
}