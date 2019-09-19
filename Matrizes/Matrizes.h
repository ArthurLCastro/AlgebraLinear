#ifndef Matrizes_h
#define Matrizes_h

// #pragma once

#include <iostream>
using namespace std;

class Matrizes{
	private:
        float** mat = NULL;
        unsigned int numLinhas = 0, numColunas = 0;
        unsigned int ordemMatQuad = 0;
        // void diminuirMatriz(unsigned int, unsigned int);
        // float calcCofator(unsigned int, unsigned int);
 
 	public:
        Matrizes();
        Matrizes(unsigned int ordem);
		Matrizes(unsigned int, unsigned int);
        void dimensoes(unsigned int, unsigned int);
        unsigned int getQtdLinhas();
        unsigned int getQtdColunas();
        bool quadrada();
        void setMatriz(unsigned int, unsigned int, float);
        float detLaplace();
        void imprime();
        void imprimeFormatada();
        void diminuirMatriz(unsigned int, unsigned int);
        float calcCofator(unsigned int, unsigned int);
};

#endif