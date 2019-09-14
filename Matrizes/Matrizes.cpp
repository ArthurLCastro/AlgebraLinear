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
        void setMatriz();
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

void Matrizes::setMatriz(){         // Inserir dados da Matriz
    for (int linha=1; linha<=numLinhas; linha++){
        for (int coluna=1; coluna<=numColunas; coluna++){
            cout << "\t> a(" << linha << " " << coluna << "): ";
            cin >> mat[linha-1][coluna-1];
        }        
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

//===================================== MAIN() =====================================
unsigned int line, columns;

Matrizes minhaMatriz;

int main() {
    cout << "\n\xAF Insira a quantidade de Linhas da Matriz: ";
    cin >> line; 
    cout << "\xAF Insira a quantidade de Colunas da Matriz: ";
    cin >> columns; 
    minhaMatriz.dimensoes(line, columns);
    minhaMatriz.setMatriz();
    minhaMatriz.imprimeFormatada();
    
    cout << "\n";
    system("pause");

    return 0;
}
