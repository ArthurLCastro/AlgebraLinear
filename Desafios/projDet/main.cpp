#include <iostream>
using namespace std;

#include "..\..\Matrizes\Matrizes.h"

unsigned int line, columns;

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
    cin >> line;
    cout << "\t\xAF Insira a quantidade de Colunas da Matriz: ";
    cin >> columns;
    minhaMatriz.dimensoes(line, columns);

    cabecalho();
    if (minhaMatriz.quadrada()){                // Verifica se a matriz é quadrada
        // Insere valores à matriz
        cout << "\n\t\xAF Insira os valores da matriz como a do exemplo a seguir:\n\n";
        matrizDemo();
        cout << "\n";
        minhaMatriz.setMatriz();
    
        // // Calcula e imprime o determinante e a matriz
        // cabecalho();
        // cout << "\n";
        // minhaMatriz.imprimeFormatada();
        // cout << "\n\t\xAF A matriz possui determinante\n\t det(M) = " << minhaMatriz.detLaplace() << "\n\n\t";
        // system("pause");

        // TESTE DIMINUIR MATRIZ
        cabecalho();
        cout << "\n";
        minhaMatriz.imprimeFormatada();

        unsigned int linhaDelete, colunaDelete;
        cout << "\t\xAF Linha a ser deletada: ";
        cin >> linhaDelete;
        cout << "\t\xAF Coluna a ser deletada: ";
        cin >> colunaDelete;
        minhaMatriz.diminuirMatriz(linhaDelete, colunaDelete);
        minhaMatriz.imprimeFormatada();
        system("pause");
        

    } else {
        // Imprime mensagem de erro
        cout << "\n\tMATRIZ INVALIDA!";
        cout << "\n\tInsira uma matriz quadrada! (Ex: n x n)\n\n\t";
        system("pause");
        return 0;
    }

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