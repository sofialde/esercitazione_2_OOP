#include <iostream>
#include "complessi.hpp"


int main() {
	complex num1(5.0 , 3.0);
	complex num2 (-1.0 , 2.0);
	double num3 (1.13);

//verifico il corretto funzionamento dell overload di <<
	std::cout<<"num1="<<num1<<std::endl;
	std::cout<<"num2="<<num2<<std::endl;

// verifico il funzionamento dei metodi realpart, impart e conjugate
std::cout<<"parte reale del complesso num1: "<<num1.realpart()<<std::endl;
std::cout<<"parte immaginaria del complesso num2: "<<num2.impart()<<std::endl;
std::cout<<"coniugato di num1: "<<num1.conjugate()<<std::endl;

//verifico il corretto funzionamento degli operatori di somma e prodotto...
//prima tra due complessi...
	complex somma = num1 + num2;
	complex prodotto = num1 * num2;

//poi tra un complesso e un double
	complex somma_misto0 = num3 + num2;
	complex prodotto_misto0 = num3*num1;

//verifico che funzioni anche scambiando l'ordine degli addendi/fattori
	complex somma_misto1 = num2 + num3;
	complex prodotto_misto1 = num1*num3;

	std::cout<<somma<<std::endl;
	std::cout<<prodotto<<std::endl;
	std::cout<<somma_misto0<<std::endl;
	std::cout<<prodotto_misto0<<std::endl;
	std::cout<<somma_misto1<<std::endl;
	std::cout<<prodotto_misto1<<std::endl;

}