#include "pch.h"
#include "UI.h"


UI::UI()
{
	this->c = new Controller();
}


UI::~UI()
{
	delete this->c;
	this->c = NULL;
}

void UI::run() {
	int opt;
	getAll();
	cout << endl;;
	cout << "//////////////////////////////////" << endl;
	do {
		printMeniu();
		cin >> opt;
		switch (opt) {
		case 1:
		{
			addProdus();
			break;
		}
		case 2:
		{
			buyProdus();
			break;
		}
		case 3:
		{
			getAll();
			break;
		}
		}
		cout << endl;;
		cout << "//////////////////////////////////" << endl;
	} while (opt != 0);
}
void UI::printMeniu() {
	cout << "0-> Iesire\n";
	cout << "1-> Adauga produs\n";
	cout << "2-> Cumpara produs\n";
	cout << "3-> Afiseaza produse\n";

}
void UI::addProdus() {
	Produs p;
	cout << "Introduceti informatiile sub forma Cod/Denumire/Pret" << endl;
	cin >> p;
	this->c->addProdus(&p);
}
void UI::buyProdus() {
	int cod;
	int suma;
	cout << "Alegeti produsul (cod) ";
	cin >> cod;
	cout << "Introducetii banii ";
	cin >> suma;
	this->c->buyProdus(cod, suma);
}
void UI::getAll() {
	vector<Produs> produse = this->c->getAll();
	cout << "Cod/Denumire/Pret" << endl;
	for (unsigned int i = 0; i < produse.size(); i++) {
		cout << produse[i];
	}
}