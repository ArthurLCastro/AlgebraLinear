#ifndef Vetores_h
#define Vetores_h

#include <iostream>
using namespace std;

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

#endif