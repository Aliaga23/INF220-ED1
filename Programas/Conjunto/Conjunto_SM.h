//---------------------------------------------------------------------------

#ifndef Conjunto_SMH
#define Conjunto_SMH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "CSMemoria.h"

using namespace std;

const string datos = "dato,sig";
const string dato = "->dato";
const string c_sig = "->sig";

class ConjuntoSm {
private:
	CsMemoria* mem;
	int ptrConj;
	int cant;

	int localiza(int e);
	int anterior(int p);

public:
	ConjuntoSm();
	ConjuntoSm(CsMemoria* m);
	bool vacio();
	int cardinal();
	int ordinal(int e);
	void inserta(int e);
	void suprime(int e);
	bool pertenece(int e);
	int muestrea();
	int elemento(int pos);
	void reiniciar();
	string to_str();
	///string toStr();
	void unir(ConjuntoSm *b, ConjuntoSm *c);
	// ConjuntoPtr* unir(ConjuntoPtr* B);
	void intersectar(ConjuntoSm *b, ConjuntoSm *c);
	   void complementoAnB(ConjuntoSm* b, ConjuntoSm* c);
	   ConjuntoSm* diferenciaSimetrica(ConjuntoSm* b) ;
	 	 void ConjuntoSm::ordenarConjunto();
};
#endif
