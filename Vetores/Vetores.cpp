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

void apresentacao();
void cabecalho();

Vetores vetorU;
Vetores vetorV;

// Função Principal
int main() {
    apresentacao();

    cabecalho();
    cout << "\n\t\xAF Insira a quantidade de elementos dos Vetores \"u\" e \"v\": ";
    cin >> elementos; 
    vetorU.dimensao(elementos);
    vetorV.dimensao(elementos);
    cout << "\n\t";
    system("pause");

    cabecalho();
    cout << "\n\t\xAF Atribua valores ao vetor \"u\": \n";
    for (int indice=0; indice<elementos; indice++){
        float valor;

        cout << "\t\t> u(" << indice+1 << "): ";
        cin >> valor;
        vetorU.setVetor(indice, valor);
    }
    cout << "\n\t\xAF Atribua valores ao vetor \"v\": \n";
    for (int indice=0; indice<elementos; indice++){
        float valor;

        cout << "\t\t> v(" << indice+1 << "): ";
        cin >> valor;
        vetorV.setVetor(indice, valor);
    }

    cabecalho();
    cout << "\n\t\xAF Os vetores\n\n";
    for(int indice=0; indice<elementos; indice++){
        cout << "\t\tu(" << indice+1 << "): " << vetorU.getValor(indice) << "\n";
    }
    cout << "\n";
    for(int indice=0; indice<elementos; indice++){
        cout << "\t\tv(" << indice+1 << "): " << vetorV.getValor(indice) << "\n";
    }

    cout << "\n\t   sao " << "dependencia\n\n\t";

    system("pause");
    return 0;
}

// Funções Auxiliares
void apresentacao(){
    system("cls");
    cout << "================================================================================\n";
    cout << "|                                                                              |\n";
    cout << "|                                                                              |\n";
    cout << "|                        PROJETO RELACAO DE DEPENDENCIA                        |\n";
    cout << "|                                                                              |\n";
    cout << "|                     Verifica se dois vetores sao LI ou LD                    |\n";
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
    cout << "|                        PROJETO RELACAO DE DEPENDENCIA                        |\n";
    cout << "================================================================================\n\n";
}
