﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matriz_Lista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
MatrizL::MatrizL() {
	L = new ListaP();
	repe = df = dc = 0;
}

void MatrizL::dimensionar(int f, int c) {
	df = f;
	dc = c;
}

int MatrizL::dimension_fila() {
	return df;
}

int MatrizL::dimension_columna() {
	return dc;
}

int MatrizL::numero_terminos() {
	return L->longitud() / 3;
}

NodoL* MatrizL::buscar(int f, int c) {
	NodoL* aux = L->primero();
	while (aux != NULL) { // aux != NULO
		if (L->recupera(aux) == f && L->recupera(L->siguiente(aux)) == c)
			return aux;
		aux = L->siguiente(L->siguiente(L->siguiente(aux)));
	}
	return NULL; // return NULO
}

void MatrizL::poner(int f, int c, int valor) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		if (numero_terminos() == 0 && valor != repe) {
			L->inserta_ultimo(f);
			L->inserta_ultimo(c);
			L->inserta_ultimo(valor);
		}
		else {
			NodoL* aux = buscar(f, c);
			if (aux == NULL && valor != repe) {
				L->inserta_ultimo(f);
				L->inserta_ultimo(c);
				L->inserta_ultimo(valor);
			}
			else {
				NodoL* nodoDato = L->siguiente(L->siguiente(aux));
				L->modifica(nodoDato, valor);
				if (valor == repe) {
					L->suprime(nodoDato);
					L->suprime(L->siguiente(aux));
					L->suprime(aux);
				}
			}
		}
	}
}

int MatrizL::elemento(int f, int c) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		NodoL* dir = buscar(f, c);
		if (dir != NULL) {
			NodoL* nodoDato = L->siguiente(L->siguiente(dir));
			return L->recupera(nodoDato);
		}
		else
			return repe;
	}
}

void MatrizL::definir_valor_repetido(int valor) {
	bool re = false;
	NodoL* aux = L->primero();
	while (aux != NULL) {
		NodoL* nd = L->siguiente(L->siguiente(aux));
		if (L->recupera(nd) == valor) {
			re = true;
			break;
		}
		aux = L->siguiente(L->siguiente(L->siguiente(aux)));
	}
	if (numero_terminos() == 0 || re == false) {
		repe = valor;
	}
	else {
		int nRep = valor, aRep = repe;
		for (int i = 1; i <= df; i++) {
			for (int j = 1; j <= dc; j++) {
				int e = elemento(i, j);
				if (e == nRep) {
					NodoL* aux = buscar(i, j);
					L->suprime(L->siguiente(L->siguiente(aux)));
					L->suprime(L->siguiente(aux));
					L->suprime(aux);
				}
				else if (e == aRep) {
					L->inserta_ultimo(i);
					L->inserta_ultimo(j);
					L->inserta_ultimo(e);
				}
			}
		}
		repe = valor;
	}
}

string MatrizL::to_str() {
	string r = "";
	for (int i = 1; i <= df; i++) {
		r += "| ";
		for (int j = 1; j <= dc; j++) {
			int e = elemento(i, j);
			r += to_string(e) + "  ";
		}
		r += "|\n";
	}
	r += "NT: " + to_string(numero_terminos()) + "\n";
	r += L->to_str() + "\n";
	return r;
}
