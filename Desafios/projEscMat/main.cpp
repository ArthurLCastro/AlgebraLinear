// Projeto Determinates - Álgebra Linear
// Arthur Castro
// Setembro de 2019

#include <iostream>
using namespace std;

#include "..\..\Matrizes\Matrizes.h"

unsigned int ordem;

void apresentacao();
void cabecalho();
void matrizDemo();

Matrizes minhaMatriz;

int main() {
    // Apresentação inicial
    apresentacao();

    // Definição das dimensões da matriz
    cabecalho();
    cout << "\n\t\xAF Insira a ordem da Matriz quadrada: ";
    cin >> ordem;
    minhaMatriz.dimensoes(ordem, ordem);

    // Insere valores à matriz
    cabecalho();
    cout << "\n\t\xAF Insira os valores da matriz como a do exemplo a seguir:\n\n";
    matrizDemo();
    cout << "\n";
    for (int linha=1; linha<=ordem; linha++){
        for (int coluna=1; coluna<=ordem; coluna++){
            float valor;
            cout << "\t> a(" << linha << " " << coluna << "): ";
            cin >> valor;
            minhaMatriz.setMatriz(linha-1, coluna-1, valor);
        }
    }

    // TESTE - Calculo de Cofator
    cabecalho();
    cout << "\n";
    minhaMatriz.imprimeFormatada();
    unsigned int lin, col;
    cout << "Linha para cofator: ";
    cin >> lin;
    cout << "\n";
    cout << "Coluna para cofator: ";
    cin >> col;
    cout << "\n";
    cout << "\n\t\xAF A matriz possui cofator\n\n\t\t" << minhaMatriz.calcCofator(lin, col) << "\n\n\t";
    system("pause");

    // // Calcula e imprime o determinante e a matriz
    // cabecalho();
    // cout << "\n";
    // minhaMatriz.imprimeFormatada();
    // cout << "\n\t\xAF A matriz possui determinante\n\n\t\t det(M) = " << minhaMatriz.detLaplace() << "\n\n\t";
    // system("pause");

    return 0;
}

// Funções Auxiliares
void apresentacao(){
    system("cls");
    cout << "================================================================================\n";
    cout << "|                                                                              |\n";
    cout << "|                                                                              |\n";
    cout << "|                            DETERMINANTE DE MATRIZ                            |\n";
    cout << "|                          QUADRADA DE QUALQUER ORDEM                          |\n";
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
    cout << "|               DETERMINANTE DE MATRIZ QUADRADA DE QUALQUER ORDEM              |\n";
    cout << "================================================================================\n\n";
}

void matrizDemo(){
    cout << "\t     \xBA a11 a12 a13 ... a1n \xBA \n";
    cout << "\t     \xBA a21 a22 a23 ... a2n \xBA \n";
    cout << "\t M = \xBA a31 a32 a33 ... a3n \xBA \n";
    cout << "\t     \xBA ... ... ... ... ... \xBA \n";
    cout << "\t     \xBA am1 am2 am3 ... amn \xBA \n";
}