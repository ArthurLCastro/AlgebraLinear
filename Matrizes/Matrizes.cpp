// Biblioteca "Matrizes" para cálculos de Álgebra Linear
// Arthur Castro

#include "Matrizes.h"

// #define DEBUG

Matrizes::Matrizes(){
}

Matrizes::Matrizes(unsigned int ordem){
    dimensoes(ordem, ordem);
}

Matrizes::Matrizes(unsigned int linhas, unsigned int colunas){
    dimensoes(linhas, colunas);
}

void Matrizes::dimensoes(unsigned int qtdLinhas, unsigned int qtdColunas){
    this->numLinhas = qtdLinhas;
    this->numColunas = qtdColunas;

    #ifdef DEBUG
        cout << "\n\n[DEBUG](dimensoes) Quantidade de Linhas: " << numLinhas;
        cout << "\n[DEBUG](dimensoes) Quantidade de Colunas: " << numColunas;
        cout << "\n";
        system("pause");
    #endif

    // Aloca Dinamicamente o Espaço de Memória necessário
    float** matriz = (float**)malloc(numLinhas * sizeof(float*));
    for (int i=0; i<numColunas; i++){
        matriz[i]=(float*)malloc(numColunas * sizeof(float));
    }
    // Torna uma matriz global
    this->mat = matriz;
}

unsigned int Matrizes::getQtdLinhas(){
    return this->numLinhas;
}

unsigned int Matrizes::getQtdColunas(){
    return this->numColunas;
}

bool Matrizes::quadrada(){
    if(this->numLinhas == this->numColunas){
        this->ordemMatQuad = this->numLinhas;
        return true;
    } else {
        return false;
    }
}

void Matrizes::setMatriz(unsigned int linha, unsigned int coluna, float valor){         // Inserir dados da Matriz
    this->mat[linha][coluna] = valor;
}

float Matrizes::detLaplace(){
    float detM = 0;
    unsigned int linhaFixa = 0;     // Verificar o tipo da "variável", mudar para constante
    unsigned int coluna;

    if(quadrada()){
        if(this->getQtdLinhas() == 1){          // Se a ordem da Matriz for 1, o determinante é o próprio valor do elemento que a compõe
            #ifdef DEBUG
            cout << "\n[DEBUG] Matriz de ordem 1";
            #endif
            detM = mat[0][0];
        } else {
            #ifdef DEBUG
            cout << "\n[DEBUG] Matriz de ordem maior que 1";
            cout << "\nordemMatQuad: " << ordemMatQuad << "\n";
            #endif
            for(coluna=1; coluna<=ordemMatQuad; coluna++){
                detM += ((mat[linhaFixa][coluna-1]) * calcCofator(linhaFixa+1, coluna));
                #ifdef DEBUG
                cout << "\n\n Determinante parcial: " << detM << "\n";
                #endif
            }
        }
        return detM;
    } else {
        cout << "[Erro detLaplace()] Matriz nao quadrada! \n";
        system("pause");
    }
}

float Matrizes::calcCofator(unsigned int linha, unsigned int coluna){      // Verificar se o tipo float é adequado
    if(this->quadrada()){
        unsigned int ordemMatAux = ordemMatQuad;
        Matrizes matrizAuxiliar(ordemMatAux);

        for (int line=1; line<=ordemMatAux; line++){
            for (int column=1; column<=ordemMatAux; column++){
                matrizAuxiliar.setMatriz(line-1, column-1, this->mat[line-1][column-1]);
            }
        }

        #ifdef DEBUG
            cout << "Impressao da Matriz Auxiliar:\n";
            matrizAuxiliar.imprimeFormatada();
            cout << "\nLinha a ser deletada: " << linha;
            cout << "\nColuna a ser deletada: " << coluna;
        #endif

        matrizAuxiliar.diminuirMatriz(linha, coluna);

        #ifdef DEBUG
            cout << "\n\nImpressao da Matriz Auxiliar Diminuida:\n";
            matrizAuxiliar.imprimeFormatada();
        #endif
        return ((pow(-1,((linha) + (coluna)))) * matrizAuxiliar.detLaplace());
    } else {
        cout << "[Erro calcCofator()] Matriz nao quadrada! \n";
        system("pause");
    }
}

void Matrizes::diminuirMatriz(unsigned int linhaDel, unsigned int colunaDel){         // Inserir dados da Matriz Automaticamente
    if(this->quadrada()){
        // Copia os valores da linha abaixo da linhaDel para uma linha acima
        for (int count=0; count<ordemMatQuad; count++){
            for(int aux=0; aux<(ordemMatQuad-linhaDel); aux++){
                mat[(linhaDel-1)+aux][count] = mat[(linhaDel-1)+(aux+1)][count];
            }
        }
        // Insere NULL à última linha da matriz maior
        for (int inc=0; inc<ordemMatQuad; inc++){
            mat[ordemMatQuad-1][inc] = NULL;
        }

        // Copia os valores da coluna à direita da colunaDel para uma coluna à esquerda
        for (int count=0; count<ordemMatQuad; count++){
            for(int aux=0; aux<(ordemMatQuad-colunaDel); aux++){
                mat[count][(colunaDel-1)+aux] = mat[count][(colunaDel-1)+(aux+1)];
            }
        }
        // Insere NULL à última coluna da matriz maior
        for (int inc=0; inc<ordemMatQuad; inc++){
            mat[inc][ordemMatQuad-1] = NULL;
        }

        numLinhas--;
        numColunas--;  
        ordemMatQuad--;
    } else {
        cout << "[Erro diminuir()] Matriz nao quadrada! \n";
        system("pause");
    }
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