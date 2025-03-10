﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaPuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iomanip>
PilaP::PilaP()
{
    tope = NULL;
}

bool PilaP::vacia()
{
    return tope == NULL;
}

void PilaP::meter(int e)
{
    NodoPun* aux = new NodoPun;
    if (aux != NULL) {
		aux->elemento = e;
		aux->sig = tope;
		tope = aux;
    } else
        cout << "ERROR NO HAY MEMORIA\n" << endl;
}

void PilaP::sacar(int &e)
{
    if (!vacia()) {
		NodoPun* x = tope;
        e = tope->elemento;
        tope = tope->sig;
        delete (x);
    }
}

int PilaP::cima()
{
    if (!vacia()) {
        return tope->elemento;
    }
}

string PilaP::to_str()
{
	string r = "";
	PilaP* aux = new PilaP();
	while (!vacia()) {
		int e;
		sacar(e);
		r += "| " + to_string(e) + " |\n";
		aux->meter(e);
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		meter(e);
	}
	r += "+---+\n";
	return r;
}
//string PilaP::to_str()
//{
//	string r = "+";
////	for (int i = 2; i <= 4+ 4; i++) {
////		r += "-";
////	}
////	r += "+\n";
//	PilaP* aux = new PilaP();
//	while (!vacia()) {
//		int e;
//		sacar(e);
//		cout<< "| " << setw(5)<<to_string(e) << " |\n";
//		aux->meter(e);
//	}
//	while (!aux->vacia()) {
//		int e;
//		aux->sacar(e);
//		meter(e);
//	}
////	r += "+";
////	for (int i = 2; i <= 4 + 4; i++) {
////		r += "-";
////	}
////	r += "+\n";
//	return r;
//}
