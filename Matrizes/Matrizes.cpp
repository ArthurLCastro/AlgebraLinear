#include "Matrizes.h"

Matrizes::Matrizes(){
}

Matrizes::Matrizes(unsigned int ordem){
    dimensoes(ordem, ordem);
}

Matrizes::Matrizes(unsigned int linhas, unsigned int colunas){
    dimensoes(linhas, colunas);
}

void Matrizes::dimensoes(unsigned int qtdLinhas, unsigned int qtdColunas){
    numLinhas = qtdLinhas;
    numColunas = qtdColunas;

    cout << "\nQuantidade de Linhas: " << qtdLinhas;
    cout << "\nQuantidade de Colunas: " << qtdColunas;
    cout << "\n";

    // Aloca Dinamicamente o Espaço de Memória necessário
    float** matriz = (float**)malloc(qtdLinhas * sizeof(float*));
    for (int i=0; i<(qtdColunas); i++){
        matriz[i]=(float*)malloc(qtdColunas * sizeof(float));
    }
    // Torna uma matriz global
    mat = matriz;
}

unsigned int Matrizes::getQtdLinhas(){
    return numLinhas;
}

unsigned int Matrizes::getQtdColunas(){
    return numColunas;
}

bool Matrizes::quadrada(){
    if(numLinhas == numColunas){
        ordemMatQuad = numLinhas;
        return true;
    } else {
        return false;
    }
}

void Matrizes::setMatriz(){         // Inserir dados da Matriz
    for (int linha=1; linha<=numLinhas; linha++){
        for (int coluna=1; coluna<=numColunas; coluna++){
            cout << "\t> a(" << linha << " " << coluna << "): ";
            cin >> mat[linha-1][coluna-1];
        }        
    }
}

float Matrizes::detLaplace(){
    float detM = 0;
    unsigned int linhaFixa = 0;     // Verificar o tipo da "variável", mudar para constante
    unsigned int coluna;

    if(this->getQtdLinhas() == 1){          // Se a ordem da Matriz for 1, o determinante é o próprio valor do elemento que a compõe
        detM = mat[0][0];
    } else {
        // cout << "[DEBUG] Matriz de ordem maior que 1";
        for(coluna=1; coluna<=ordemMatQuad; coluna++){
            coluna--;
            detM += (mat[linhaFixa][coluna]) * calcCofator(linhaFixa, coluna);
        }
    }

    return detM;
}

float Matrizes::calcCofator(unsigned int linha, unsigned int coluna){      // Verificar se o tipo float é adequado
    unsigned int ordemMatAux = ordemMatQuad - 1;
    Matrizes matrizAuxiliar(ordemMatAux);

    matrizAuxiliar.diminuirMatriz(linha, coluna);
    return (((-1)^(linha + coluna)) * matrizAuxiliar.detLaplace());
}

void Matrizes::diminuirMatriz(unsigned int linhaDel, unsigned int colunaDel){         // Inserir dados da Matriz Automaticamente
    // Copia os valores da linha abaixo da linhaDel para uma linha acima
    for (int count=0; count<ordemMatQuad; count++){
        for(int aux=0; aux<(ordemMatQuad-linhaDel); aux++){
            mat[linhaDel+aux][count] = mat[linhaDel+(aux+1)][count];
        }
    }
    // Insere NULL à última linha da matriz maior
    for (int inc=0; inc<ordemMatQuad; inc++){
        mat[ordemMatQuad][inc] = NULL; 
    }

    // Copia os valores da coluna a direita da colunaDel para uma coluna a esquerda
    for (int count=0; count<ordemMatQuad; count++){
        for(int aux=0; aux<(ordemMatQuad-colunaDel); aux++){
            mat[count][colunaDel+aux] = mat[count][colunaDel+(aux+1)];
        }
    }
    // Insere NULL à última coluna da matriz maior
    for (int inc=0; inc<ordemMatQuad; inc++){
        mat[inc][ordemMatQuad] = NULL; 
    }

    // numLinhas--;
    // numColunas--;  
    // ordemMatQuad--;
}

void Matrizes::imprime(){
    for(int i=0; i<numLinhas; i++){
        for(int j=0; j<numColunas; j++){
            cout << "\na" << i+1 << j+1 << ": " << mat[i][j];
        }
    }
}

void Matrizes::imprimeFormatada(){
    unsigned int linha, coluna;

    cout << "\t\xBA";
    for (linha=1; linha<=numLinhas; linha++){
       for (coluna=1; coluna<=numColunas; coluna++){
            cout << mat[linha-1][coluna-1] << " ";
        }
        if ((coluna > numColunas) && (linha != numLinhas)){
            cout << "\xBA\n\t\xBA";
        } else {
            cout << "\xBA\n";
        }
    }
    cout << "\n\t";
}