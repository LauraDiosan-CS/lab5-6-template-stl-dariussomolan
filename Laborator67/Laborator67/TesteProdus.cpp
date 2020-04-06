#include "pch.h"
#include <assert.h>
#include "TesteProdus.h"
#include "Produs.h"

void TesteProdus::test_nume_isSet() {
	Produs p1 = Produs();
	p1.setNume("Lays");
	assert(p1.getNume() == "Lays");
}
void TesteProdus::test_nume_isNotSet() {
	Produs p1 = Produs();
	p1.setNume("Lays");
	assert(p1.getNume() != "Snickers");
}
void TesteProdus::test_cod_isSet() {
	Produs p1 = Produs();
	p1.setCod(1);
	assert(p1.getCod() == 1);

}
void TesteProdus::test_cod_isNotSet() {
	Produs p1 = Produs();
	p1.setCod(1);
	assert(p1.getCod() != 2);
}
void TesteProdus::test_pret_isSet() {
	Produs p1 = Produs();
	p1.setPret(2.5);
	assert(p1.getPret() == 2.5);
}
void TesteProdus::test_pret_isNotSet() {
	Produs p1 = Produs();
	p1.setPret(2.5);
	assert(p1.getPret() != 3.5);
}

void TesteProdus::run() {
	test_nume_isSet();
	test_nume_isNotSet();
	test_cod_isSet();
	test_cod_isNotSet();
	test_pret_isSet();
	test_pret_isNotSet();
}