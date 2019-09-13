// Resolução de Sistemas Lineares pelo Método de Gauss
// Arthur Castro
// Setembro de 2019

#include <stdio.h>

int ordemMat = 0;
// //float matriz[3][3] = {  {1, 2, 3},
//                         {4, 5, 6},
//                         {7, 8, 9}   };
//float matriz[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9} // Também funciona

void apresentacao();
void cabecalho();
void matrizDemo();

int main(){
    unsigned int linha, coluna;

    // Apresentação ======================================================================
   apresentacao();

    // Inserção da Matriz ================================================================
    cabecalho();
    printf("\t\xAF Insira a ordem da matriz quadrada: ");
    scanf("%i", &ordemMat);
    printf("\n\t");
    system("pause");
    
    float matriz[ordemMat][ordemMat];

    cabecalho();
    matrizDemo();
    printf("\n\t\xAF Atribua valores respectivos a matriz como no exemplo acima: \n");
    for (linha=1; linha<=ordemMat; linha++){
        for (coluna=1; coluna<=ordemMat; coluna++){
            printf("\t\t> a%i%i: ", linha, coluna);
            scanf("%f", &matriz[linha-1][coluna-1]);
        }        
    }

    // Impressão da Matriz ================================================================
    cabecalho();
    printf("\n\t\xAF A matriz gerada foi: \n\n");
    printf("\t\xBA");
    for (linha=1; linha<=ordemMat; linha++){
       for (coluna=1; coluna<=ordemMat; coluna++){
            printf("%.2f ", matriz[linha-1][coluna-1]);
        }
        if ((coluna > ordemMat) && (linha != ordemMat)){
            printf("\xBA\n\t\xBA");
        } else {
            printf("\xBA\n");
        }
    }
    printf("\n\t");
    
   system("pause");

    return 0;
}

void apresentacao(){
    system("cls");
    printf("================================================================================\n");
    printf("|                                                                              |\n");
    printf("|                        RESOLUCAO DE SISTEMAS LINEARES                        |\n");
    printf("|                               Metodo de Gauss                                |\n");
    printf("|                                                                              |\n");
    printf("|                   ----------------------------------------                   |\n");
    printf("|                                                                              |\n");
    printf("|                       Algebra Linear 2019.2 - UPE/POLI                       |\n");
    printf("|                         Aluno: Arthur Lima de Castro                         |\n");
    printf("|                    Prof.: Paulo Hugo Espirito Santo Lima                     |\n");
    printf("|                                                                              |\n");
    printf("================================================================================\n\n");
    system("pause");
}

void cabecalho(){
    system("cls");
    printf("================================================================================\n");
    printf("|                        RESOLUCAO DE SISTEMAS LINEARES                        |\n");
    printf("|                               Metodo de Gauss                                |\n");
    printf("================================================================================\n\n");
}

void matrizDemo(){
    printf("\t     \xBA a11 a12 a13 ... a1n \xBA \n");
    printf("\t     \xBA a21 a22 a23 ... a2n \xBA \n");
    printf("\t M = \xBA a31 a32 a33 ... a3n \xBA \n");
    printf("\t     \xBA ... ... ... ... ... \xBA \n");
    printf("\t     \xBA am1 am2 am3 ... amn \xBA \n");
}