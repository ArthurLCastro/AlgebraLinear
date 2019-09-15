#include <iostream>
using namespace std;

//===================================== CLASSES =====================================
class Matrizes{
	private:
        float** mat = NULL;
        unsigned int numLinhas = 0;
        unsigned int numColunas = 0;
 
 	public:
        Matrizes();
		Matrizes(unsigned int, unsigned int);
        void dimensoes(unsigned int, unsigned int);
        bool quadrada();
        void setMatriz();
        float determinante();
        void imprime();
        void imprimeFormatada();
};

//===================================== MÉTODOS =====================================
Matrizes::Matrizes(){
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

bool Matrizes::quadrada(){
    if(numLinhas == numColunas){
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

float Matrizes::determinante(){
    return 3;
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
    
        // Calcula e imprime o determinante e a matriz
        cabecalho();
        cout << "\n";
        minhaMatriz.imprimeFormatada();
        cout << "\n\t\xAF A matriz possui determinante\n\t det(M) = " << minhaMatriz.determinante() << "\n\n\t";
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