//---------------------------------------------------------------------------

#ifndef Poli_VecH
#define Poli_VecH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>


using namespace std;

const int MAXP = 100;

class PoliV {
private:
	int* vc; // int vc[MAXP];
	int* ve; // int ve[MAXP];
	int nt;

public:
	PoliV();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro);
	void sumar(PoliV* p1, PoliV* p2, PoliV* &pr);
	void restar(PoliV* p1, PoliV* p2, PoliV* &pr);
	void multiplicar(PoliV* p1, PoliV* p2, PoliV* &pr);
	void derivar();
	string to_str();
    float evalua(float x);
};

#endif
