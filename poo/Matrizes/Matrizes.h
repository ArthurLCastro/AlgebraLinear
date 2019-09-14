#pragma once

// #include <stdio.h>
#include <iostream>
using namespace std;

class Matrizes{
	private:
		float **matriz = NULL;
 
 	public:
		Matrizes();
		Matrizes(unsigned int ,unsigned int);
        void defMatriz(unsigned int, unsigned int);
};