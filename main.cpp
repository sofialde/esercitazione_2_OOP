#include <iostream>
#include "complessi.hpp"


int main() {
	complex num1(5.0 , 3.0);
	complex num2 (-1.0 , 2.0);
	double num3 (1.13);

	complex somma = num1 + num2;
	complex prodotto = num1 * num2;
	complex somma_misto = num3 + num2;
	complex prodotto_misto = num3*num1;

	std::cout<<somma<<std::endl;
	std::cout<<prodotto<<std::endl;
	std::cout<<somma_misto<<std::endl;
	std::cout<<prodotto_misto<<std::endl;

}