// Biblioteca "Matrizes" para cálculos de Álgebra Linear
// Arthur Castro

#include "Matrizes.h"

// #define DEBUG
#define DEBUG_elimGauss
// #define DEBUG_pivo

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
    for (unsigned int i=0; i<numLinhas; i++){
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

        for (unsigned int line=1; line<=ordemMatAux; line++){
            for (unsigned int column=1; column<=ordemMatAux; column++){
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
        for (unsigned int count=0; count<ordemMatQuad; count++){
            for(unsigned int aux=0; aux<(ordemMatQuad-linhaDel); aux++){
                mat[(linhaDel-1)+aux][count] = mat[(linhaDel-1)+(aux+1)][count];
            }
        }
        // Insere NULL à última linha da matriz maior
        for (unsigned int inc=0; inc<ordemMatQuad; inc++){
            mat[ordemMatQuad-1][inc] = NULL;
        }

        // Copia os valores da coluna à direita da colunaDel para uma coluna à esquerda
        for (unsigned int count=0; count<ordemMatQuad; count++){
            for(unsigned int aux=0; aux<(ordemMatQuad-colunaDel); aux++){
                mat[count][(colunaDel-1)+aux] = mat[count][(colunaDel-1)+(aux+1)];
            }
        }
        // Insere NULL à última coluna da matriz maior
        for (unsigned int inc=0; inc<ordemMatQuad; inc++){
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
    for(unsigned int i=0; i<numLinhas; i++){
        for(unsigned int j=0; j<numColunas; j++){
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

void Matrizes::elimGauss(){
    Matrizes matEscalonamento(numLinhas, numColunas);

    // Copia a Matriz inserida para a Matriz usada no Escalonamento
    for (unsigned int line=1; line<=numLinhas; line++){
        for (unsigned int column=1; column<=numColunas; column++){
            matEscalonamento.setMatriz(line-1, column-1, this->mat[line-1][column-1]);
        }
    }
    #ifdef DEBUG_elimGauss
    cout << "\n[DEBUG_elimGauss] Matriz Escalonamento:\n";
    matEscalonamento.imprimeFormatada();
    #endif

    // Zera os elementos abaixo dos pivos:
    for(unsigned int linha=1; linha<=numLinhas; linha++){
        cout << "\n\t[For DEBUG] " << linha << "\n";
        float valorDoPivo;
        valorDoPivo = matEscalonamento.pivo(linha, "valor");
        cout << "\n\t[Piv DEBUG] " << valorDoPivo << "\n";

        if(valorDoPivo == 1){
            #ifdef DEBUG_elimGauss
            cout << "\n[DEBUG_elimGauss] Pivo igual a '1'\n";
            #endif
            // L2 <- -a(21)*L1 + L2
            // L3 <- -a(31)*L1 + L3
            // Ln <- -a(3n)*L1 + Ln
        } else if(valorDoPivo == -1){
            #ifdef DEBUG_elimGauss
            cout << "\n[DEBUG_elimGauss] Pivo igual a '-1'\n";
            #endif
            // L2 <- a(21)*L1 + L2
            // L3 <- a(31)*L1 + L3
            // Ln <- a(3n)*L1 + Ln
        } else {
            #ifdef DEBUG_elimGauss
            cout << "\n[DEBUG_elimGauss] Pivo diferente de '1' ou '-1'\n";
            #endif
        }
    }
    
    // // TESTES PIVO
    // unsigned int colunaPivo, valorPivo, linha;
    // cout << "\nInsira o valor da Linha a se procurar o pivo: ";
    // cin >> linha;
    // colunaPivo = pivo(linha, "encontrarColuna");
    // cout << "\nColuna do Pivo: " << colunaPivo;
    // valorPivo = pivo(linha, "valor");
    // cout << "\nValor do Pivo: " << valorPivo;

    // matEscalonamento.imprimeFormatada();
}

float Matrizes::pivo(unsigned int linhaPivo, string valor){    // Estudar se há a possibilidade de uma chamada retornar dois valores
    unsigned int colunaPivo;

    for(colunaPivo=1; colunaPivo<=numColunas; colunaPivo++){
        if(mat[linhaPivo-1][colunaPivo-1] != 0){
            break;
        }
        if(colunaPivo == numColunas){
            #ifdef DEBUG_pivo
            cout << "\n\n[DEBUG_Pivo] Linha zerada, nao possui Pivo";
            #endif
            return NULL;
        }
    }

    if(valor == "encontrarColuna"){
        return colunaPivo;
    }

    if(valor == "valor"){
        return mat[linhaPivo-1][colunaPivo-1];
    }
}