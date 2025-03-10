﻿//---------------------------------------------------------------------------

#ifndef LisPoli_Vec_MemH
#define LisPoli_Vec_MemH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "Lista_SM.h"
#include "UListaV.h"

using namespace std;

class PoliL {
private:
	ListaV* pol;//ListaS* pol;

	int buscar_exponente(int exp);
	int buscar_termino_n(int i);

public:
	PoliL();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro);
	void sumar(PoliL* p1, PoliL* p2, PoliL* &pr);
	void restar(PoliL* p1, PoliL* p2, PoliL* &pr);
	void multiplicar(PoliL* p1, PoliL* p2, PoliL* &pr);
	void derivar();
	string to_str();
    float evalua(float x);

};
#endif
