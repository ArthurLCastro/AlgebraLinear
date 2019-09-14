// Leitura e Impressão de uma Matriz
// Arthur Castro
// Setembro de 2019

#include <iostream>
using namespace std;

#include "Matrizes/Matrizes.h"

// Definição de variáveis globais ==============================================================
unsigned int linhas, colunas;

// Definição de objetos ========================================================================

// Declaração de protótipos das funções ========================================================
void apresentacao();

// Função Principal - main() ===================================================================
int main(){
    // Apresentação ============================================================================
    apresentacao();
    
    system("cls");
    printf("\t>> Insira a quantidade de linhas da matriz: ");
    scanf("%i", &linhas);
    printf("\t>> Insira a quantidade de colunas da matriz: ");
    scanf("%i", &colunas);

    Matrizes minhaMatriz(linhas, colunas);

    return 0;
}

void apresentacao(){
    system("cls");
    printf("================================================================================\n");
    printf("|                                                                              |\n");
    printf("|                                                                              |\n");
    printf("|                      LEITURA E IMPRESSAO DE UMA MATRIZ                       |\n");
    printf("|                                                                              |\n");
    printf("|                                                                              |\n");
    printf("|                   ----------------------------------------                   |\n");
    printf("|                                                                              |\n");
    printf("|                                                                              |\n");
    printf("|                            Arthur Lima de Castro                             |\n");
    printf("|                              Setembro de 2019                                |\n");
    printf("|                                                                              |\n");
    printf("|                                                                              |\n");
    printf("================================================================================\n\n");
    system("pause");
}