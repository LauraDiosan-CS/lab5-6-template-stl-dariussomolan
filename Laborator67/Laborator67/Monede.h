#pragma once
#include <iostream>
using namespace std;
class Monede
{
private:
	double valoare;
	int numar;
public:
	Monede();
	Monede(double valoare, int numar);
	~Monede();
	double getValoare();
	int getNumar();
	void setNumar(int numar);
	void setValoare(double valoare);
	friend ostream& operator<<(ostream& os, Monede& c);
	friend istream& operator>>(istream& is, Monede& c);
};

