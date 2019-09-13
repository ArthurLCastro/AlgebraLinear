// Leitura e Impressão de Matriz quadrada de qualquer ordem
// Arthur Castro
// Setembro de 2019

#include <stdio.h>
#include <stdlib.h>

// Definição de variáveis globais ==============================================================
int ordemMat;
float **matriz;

// Declaração de protótipos das funções =========================================================
void apresentacao();
void cabecalho();
void defOrdem();
float **alocacaoDinamica();   
void matrizDemo();
void leitura();
void impressao();

// Função Principal - main() ====================================================================
int main(){
    apresentacao();
    defOrdem();
    matriz = alocacaoDinamica();
    leitura();
    impressao();
    return 0;
}

// Apresentação =================================================================================
void apresentacao(){
    system("cls");
    printf("================================================================================\n");
    printf("|                                                                              |\n");
    printf("|                                                                              |\n");
    printf("|                         LEITURA E IMPRESSAO DE MATRIZ                        |\n");
    printf("|                          QUADRADA DE QUALQUER ORDEM                          |\n");
    printf("|                                                                              |\n");
    printf("|                                                                              |\n");
    printf("|                   ----------------------------------------                   |\n");
    printf("|                                                                              |\n");
    printf("|                                                                              |\n");
    printf("|                            Arthur Lima de Castro                             |\n");
    printf("|                              Setembro de 2019                                |\n");
    printf("|                                                                              |\n");
    printf("================================================================================\n\n");
    system("pause");
}

void cabecalho(){
    system("cls");
    printf("================================================================================\n");
    printf("|           LEITURA E IMPRESSAO DE MATRIZ QUADRADA DE QUALQUER ORDEM           |\n");
    printf("================================================================================\n\n");
}

// Definir a Ordem da Matriz Quadrada =================================================================
void defOrdem(){
    cabecalho();

    printf("\t\xAF Insira a ordem da matriz quadrada: ");
    scanf("%i", &ordemMat);
    printf("\n\t");
    system("pause");
}

void matrizDemo(){
    printf("\t     \xBA a11 a12 a13 ... a1n \xBA \n");
    printf("\t     \xBA a21 a22 a23 ... a2n \xBA \n");
    printf("\t M = \xBA a31 a32 a33 ... a3n \xBA \n");
    printf("\t     \xBA ... ... ... ... ... \xBA \n");
    printf("\t     \xBA am1 am2 am3 ... amn \xBA \n");
}

// Alocação Dinâmica de Memória para Matriz de qualquer ordem =====================================
float **alocacaoDinamica(){
    float **matriz = (float**)malloc(ordemMat * sizeof(float*));
    for (int i=0; i<(ordemMat); i++){
        matriz[i]=(float*)malloc(ordemMat * sizeof(float));
    }
    return matriz;
}

// Insrir dados da Matriz =====================================================================
void leitura(){
    unsigned int linha, coluna;

    cabecalho();

    matrizDemo();
    
    printf("\n\t\xAF Atribua valores respectivos a matriz como no exemplo acima: \n");
    for (linha=1; linha<=ordemMat; linha++){
        for (coluna=1; coluna<=ordemMat; coluna++){
            printf("\t\t> a(%i %i): ", linha, coluna);
            scanf("%f", &matriz[linha-1][coluna-1]);
        }        
    }
}

// Impressão da Matriz ========================================================================
void impressao(){
    unsigned int linha, coluna;

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
}