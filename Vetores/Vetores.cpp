#include <iostream>
using namespace std;

// #define DEBUG

//===================================== CLASSES =====================================
class Vetores{
	private:
        float* vet = NULL;
        unsigned int numElem = 0;
 
 	public:
        Vetores();
		Vetores(unsigned int);
        void dimensao(unsigned int);
        void setVetor(unsigned int, float);
        float getValor(unsigned int);
};

//===================================== MÉTODOS =====================================
Vetores::Vetores(){
}

Vetores::Vetores(unsigned int qtdElem){
    dimensao(qtdElem);
}

void Vetores::dimensao(unsigned int qtdElem){
    numElem = qtdElem;

    #ifdef DEBUG
    cout << "\nQuantidade de elementos: " << qtdElem << "\n";
    #endif

    // Aloca Dinamicamente o Espaço de Memória necessário para o Vetor "vet"
    vet = (float*)malloc(qtdElem * sizeof(float));
}

void Vetores::setVetor(unsigned int indice, float valor){         // Inserir dados do Vetor
    vet[indice] = valor;
}

float Vetores::getValor(unsigned int indice){
    return vet[indice];
}

//===================================== MAIN() =====================================
unsigned int elementos;

Vetores meuVetor;

int main() {
    cout << "\n\xAF Insira a quantidade de elementos do Vetor: ";
    cin >> elementos; 
    meuVetor.dimensao(elementos);

    for (int indice=0; indice<elementos; indice++){
        float valor;

        cout << "\t> a(" << indice+1 << "): ";
        cin >> valor;
        meuVetor.setVetor(indice, valor);
    }

    for(int indice=0; indice<elementos; indice++){
        cout << "a(" << indice+1 << "): " << meuVetor.getValor(indice) << "\n";
    }

    system("pause");
    return 0;
}
