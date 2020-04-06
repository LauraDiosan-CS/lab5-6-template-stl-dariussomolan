#pragma once;
#include <vector>
#include <iostream>
#include <cmath> 
#include "Monede.h"
using namespace std;

template<class T> class Repo
{
protected:
	vector<T> itemList;
	Monede cincizeci, zece;
	T findItemByCod(int cod) {
		for (unsigned int i = 0; i < this->itemList.size(); i++) {
			if (this->itemList[i].getCod() == cod) {
				return this->itemList[i];
				break;
			}
		}
		return T();
	}
	int calcNumarmonede(double suma, double valoareMoneda) {
		return (int)(suma / valoareMoneda);
	}
public:

	Repo()
	{
		cincizeci = Monede(0.5, 30);
		zece = Monede(0.1, 100);
	}
	~Repo()
	{
		this->itemList.~vector();
	}

	void addItem(T* item) {
		this->itemList.push_back(*item);
	}
	void buyItem(int cod, int insertedMoney) {
		int nr_monede_cincizeci = 0;
		int nr_monede_zece = 0;
		int disp_50 = -1;
		int disp_10 = -1;
		T item = findItemByCod(cod);

		double rest = insertedMoney - item.getPret();
		if (rest < 0) {
			cout << "Nu au fost introdusi destui bani!\n";
			return;
		}

		nr_monede_cincizeci = calcNumarmonede(rest, 0.5);
		disp_50 = cincizeci.getNumar() - nr_monede_cincizeci;

		if (disp_50 < 0) {
			nr_monede_zece += nr_monede_cincizeci * 5;
		}
		else {
			cincizeci.setNumar(cincizeci.getNumar() - nr_monede_cincizeci);
		}

		if (rest - nr_monede_cincizeci * 0.5 > 0)
		{
			nr_monede_zece += calcNumarmonede(rest - nr_monede_cincizeci * 0.5, 0.1);
			disp_10 = zece.getNumar() - nr_monede_zece;
			if (disp_10 < 0) {
				cout << "Aparatul nu poate da rest!\n";
				return;
			}
			else {
				zece.setNumar(zece.getNumar() - nr_monede_cincizeci);
			}
		}
		if (disp_50 >= 0 && disp_10 >= 0) {
			cout << "Aparatul da rest " << nr_monede_cincizeci << " monede de 50 bani si " << nr_monede_zece << " monede de 10 bani.\n";
		}
		else if (disp_50 >= 0 && disp_10 < 0) {
			cout << "Aparatul da rest " << nr_monede_cincizeci << " monede de 50 bani.\n";
		}
		else if (disp_10 >= 0 && disp_50 < 0) {
			cout << "Aparatul da rest " << nr_monede_zece << " monede de 10 bani.\n";
		}
	}
	vector<T> getAll() {
		return this->itemList;
	}
	int getSize() {
		return this->itemList.size();
	}
};