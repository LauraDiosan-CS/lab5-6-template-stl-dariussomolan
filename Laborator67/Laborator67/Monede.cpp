#include "pch.h"
#include "Monede.h"
#include <iostream>
using namespace std;

//constr fara parametri
Monede::Monede()
{
	this->numar = 0;
	this->valoare = 0;
}

//constructor cu parametri
Monede::Monede(double valoare, int numar) {
	this->valoare = valoare;
	this->numar = numar;
}

//Destructor
Monede::~Monede() {
}

//getter pentru valoare
double Monede::getValoare() {
	return this->valoare;
}

//getter pentru numar
int Monede::getNumar() {
	return this->numar;
}

//setter pentru numar
void Monede::setNumar(int numar) {
	this->numar = numar;
}

//setter ptr valoare
void Monede::setValoare(double valoare) {
	this->valoare = valoare;
}


//Suprascriere operator de afisare
ostream & operator<<(ostream & os, Monede & c) {
	os << c.valoare << " " << c.numar << endl;
	return os;
}

//Suprascriere operator de intrare
istream& operator>>(istream & is, Monede & c) {
	is >> c.valoare >> c.numar;
	return is;
}