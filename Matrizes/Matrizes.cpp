#include <iostream>
using namespace std;

//===================================== CLASSES =====================================
class Matrizes{
	private:
        float** mat = NULL;
        unsigned int numLinhas = 0, numColunas = 0;
        unsigned int ordemMatQuad = 0;
        // void diminuirMatriz(unsigned int, unsigned int);
        float calcCofator(unsigned int, unsigned int);
 
 	public:
        Matrizes();
        Matrizes(unsigned int ordem);
		Matrizes(unsigned int, unsigned int);
        void dimensoes(unsigned int, unsigned int);
        unsigned int getQtdLinhas();
        unsigned int getQtdColunas();
        bool quadrada();
        void setMatriz();
        float detLaplace();
        void imprime();
        void imprimeFormatada();
        void diminuirMatriz(unsigned int, unsigned int);
};

//===================================== MÉTODOS =====================================
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

//===================================== MAIN() =====================================
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