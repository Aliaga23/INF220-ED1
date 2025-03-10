//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matriz_SMDoble.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MatrizSmDb::MatrizSmDb()
{
    mem = new CsMemoria();
    ptrMat = NULO;
    df = 0;
    dc = 0;
    rep = 0;
}

MatrizSmDb::MatrizSmDb(CsMemoria* m)
{
    mem = m;
    ptrMat = NULO;
    df = 0;
    dc = 0;
    rep = 0;
}

void MatrizSmDb::dimensionar(int f, int c)
{
    df = f;
    dc = c;
}

int MatrizSmDb::dimension_fila()
{
    return df;
}

int MatrizSmDb::dimension_columna()
{
    return dc;
}

int MatrizSmDb::existe_fil(int f)
{
    int aux = ptrMat;
    while (aux != NULO) {
        int aux_fil = mem->obtener_dato(aux, filSm);
        if (aux_fil == f)
            return aux;
        aux = mem->obtener_dato(aux, sigF); // aux->sigF;
    }
    return NULO;
}

int MatrizSmDb::existe_col(int f, int c)
{
    if (f == NULO)
        return NULO;
    int f_ptrCol = mem->obtener_dato(f, ptrCol);
    int aux = f_ptrCol;
    while (aux != NULO) {
        int aux_col = mem->obtener_dato(aux, colSm);
        if (aux_col == c)
            return aux;
        aux = mem->obtener_dato(aux, sigC); // aux->sigC;
    }
    return NULO;
}

void MatrizSmDb::insertar_fila(int nf)
{
    if (ptrMat == NULO) {
        ptrMat = nf;
    } else {
        int aux = ptrMat;
        int antSiFinaliza;
        while (aux != NULO) {
            antSiFinaliza = aux;
            int nf_fil = mem->obtener_dato(nf, filSm);
            int aux_fil = mem->obtener_dato(aux, filSm);
            if (nf_fil < aux_fil) {
                if (aux == ptrMat) {
                    ptrMat = nf;
                    mem->poner_dato(nf, antF, NULO); // nf->antF = NULO;
                    mem->poner_dato(nf, sigF, aux); // nf->sigF = aux;
                    mem->poner_dato(aux, antF, nf); // aux->antF = nf;
                } else {
                    int aux_antF = mem->obtener_dato(aux, antF);
                    int ant = aux_antF;
                    mem->poner_dato(ant, sigF, nf); // ant->sigF = nf;
                    mem->poner_dato(aux, antF, nf); // aux->antF = nf;
                    mem->poner_dato(nf, antF, ant); // nf->antF = ant;
                    mem->poner_dato(nf, sigF, aux); // nf->sigF = aux;
                }
                return;
            }
            aux = mem->obtener_dato(aux, sigF); // aux->sigF;
        }
        // Inserta al final
        mem->poner_dato(antSiFinaliza, sigF, nf); // antSiFinaliza->sigF = nf;
        mem->poner_dato(nf, antF, antSiFinaliza); // nf->antF = antSiFinaliza;
        mem->poner_dato(nf, sigF, NULO); // nf->sigF = NULO;
    }
}

void MatrizSmDb::insertar_col(int nf, int nc)
{
    int nf_ptrCol = mem->obtener_dato(nf, ptrCol);
    if (nf_ptrCol == NULO) {
        mem->poner_dato(nf, ptrCol, nc); // nf->ptrCol = nc;
    } else {
        mem->poner_dato(nc, sigC, nf_ptrCol); // nc->sigC = nf->ptrCol;
        mem->poner_dato(nf, ptrCol, nc); // nf->ptrCol = nc;
    }
}

int MatrizSmDb::anterior(int nf, int p)
{
    int nf_ptrCol = mem->obtener_dato(nf, ptrCol);
    if (p == nf_ptrCol) {
        return NULO;
    } else {
        int x = nf_ptrCol;
        int ant = NULO;
        while (x != NULO) {
            if (x == p) {
                return ant;
            }
            ant = x;
            x = mem->obtener_dato(x, sigC); // x->sigC;
        }
    }
}

void MatrizSmDb::suprime(int nf, int p)
{
    int nf_ptrCol = mem->obtener_dato(nf, ptrCol);
    if (p == nf_ptrCol) {
        int x = nf_ptrCol;
        int nf_ptrCol_sigC = mem->obtener_dato(nf_ptrCol, sigC);
        mem->poner_dato(nf, ptrCol, nf_ptrCol_sigC);
        // nf->ptrCol = nf->ptrCol->sigC;
        mem->delete_espacio(x); // delete(x);
    } else {
        int ant = anterior(nf, p);
        int p_sigC = mem->obtener_dato(p, sigC);
        mem->poner_dato(ant, sigC, p_sigC); // ant->sigC = p->sigC;
        mem->delete_espacio(p); // delete(p);
    }
    int nt_ptrCol = mem->obtener_dato(nf, ptrCol);
    if (nt_ptrCol == NULO) {
        if (nf == ptrMat) {
            ptrMat = mem->obtener_dato(ptrMat, sigF); // ptrMat->sigF;
            mem->poner_dato(ptrMat, antF, NULO); // ptrMat->antF = NULL;
            mem->delete_espacio(nf); // delete(nf);
        } else {
            int ant = mem->obtener_dato(nf, antF); // nf->antF;
            int sig = mem->obtener_dato(nf, sigF); // nf->sigF;
            mem->poner_dato(ant, sigF, sig); // ant->sigF = sig;
            if (sig != NULO)
                mem->poner_dato(sig, antF, ant); // sig->antF = ant;
            mem->delete_espacio(nf); // delete(nf);
        }
    }
}

void MatrizSmDb::poner(int f, int c, int valor)
{
    if (f > 0 && f <= df && c > 0 && c <= dc) {
        int fila = existe_fil(f);
        if (fila != NULO) {
            int col = existe_col(fila, c);
            if (col == NULO) {
                // Si la columna no existe, la creamos
                int nuevaCol = mem->new_espacio(dataCol);
                mem->poner_dato(nuevaCol, colSm, c);
                mem->poner_dato(nuevaCol, datoSm, valor);
                mem->poner_dato(nuevaCol, sigC, mem->obtener_dato(fila, ptrCol));  // Apunta al primer elemento de la fila
                mem->poner_dato(fila, ptrCol, nuevaCol);  // La fila ahora apunta a la nueva columna
                nt++;
            } else {
                // La columna ya existe, actualizamos su valor
                mem->poner_dato(col, datoSm, valor);
            }
        } else {
            // Si la fila no existe, la creamos junto con la columna
            int nuevaFil = mem->new_espacio(dataFil);
            mem->poner_dato(nuevaFil, filSm, f);
            mem->poner_dato(nuevaFil, sigF, NULO);
            mem->poner_dato(nuevaFil, ptrCol, NULO);

            int nuevaCol = mem->new_espacio(dataCol);
            mem->poner_dato(nuevaCol, colSm, c);
            mem->poner_dato(nuevaCol, datoSm, valor);
            mem->poner_dato(nuevaCol, sigC, NULO);

            mem->poner_dato(nuevaFil, ptrCol, nuevaCol);  // La fila apunta a la nueva columna

            insertar_fila(nuevaFil);
            nt++;
        }
        return;
    }
    cout << "ERROR DE RANGO\n";
}


int MatrizSmDb::elemento(int f, int c)
{
	if (f > 0 && f <= df) {
		if (c > 0 && c <= dc) {
			int fila = existe_fil(f);
			int col = existe_col(fila, c);
			if (fila != NULO && col != NULO) {
                return mem->obtener_dato(col, datoSm); // col->dato;
            } else {
                return rep;
            }
        }
    }
    cout << "ERROR DE RANGO\n";
}

void MatrizSmDb::definir_valor_repetido(int r)
{
    rep = r;
}

string MatrizSmDb::toStr()
{
    string r = "";
    for (int i = 0; i < df; i++) {
		r += "|";
		for (int j = 0; j < dc; j++) {
			r += to_string(elemento(i + 1, j + 1));
			if (j < dc - 1)
				r += "	";
		}
		r += "|\n";
	}
	return r;
}
void MatrizSmDb::transponer() {
    // Intercambiar dimensiones antes de la transposici�n
    std::swap(df, dc);

    for (int i = 1; i <= df; i++) {
        int fila = existe_fil(i);
        while (fila != NULO) {
            int col = mem->obtener_dato(fila, ptrCol);
            int valor = mem->obtener_dato(fila, datoSm);

            // No eliminar la columna original, solo insertar la fila como columna en la matriz transpuesta
            poner(col, i, valor);

            fila = mem->obtener_dato(fila, sigF);
        }
    }
}



//
//bool MatrizSmDb::esSimetrica() {
//	if (df != dc) {
//		return false; // Una matriz no cuadrada no puede ser sim�trica
//	}
//
//	MatrizSmDb transpuestaMatriz = transpuesta();
//
//	for (int i = 1; i <= df; i++) {
//		for (int j = 1; j <= dc; j++) {
//			if (elemento(i, j) != transpuestaMatriz.elemento(i, j)) {
//				return false; // No es sim�trica si alg�n elemento difiere de su correspondiente en la transpuesta
//			}
//		}
//	}
//
//	return true;
//}

