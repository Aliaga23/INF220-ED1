//---------------------------------------------------------------------------

#pragma hdrstop

#include "Poli_Pun.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PoliP::PoliP()
{
    ptr_poli = NULL;
    nt = 0;
}

NodoP* PoliP::buscar_exponente(int exp)
{
    NodoP* dir = ptr_poli;
    if (dir != NULL) {
        NodoP* dir_ex = NULL;
        while (dir != NULL && dir_ex == NULL) {
            if (dir->exp == exp)
                dir_ex = dir;
            dir = dir->sig;
        }
        return dir_ex;
    } else {
        return NULL;
    }
}

NodoP* PoliP::buscar_termino_n(int i)
{
    NodoP* dir = ptr_poli;
    if (dir != NULL) {
        NodoP* dir_ter = NULL;
        int nt = 0;
        while (dir != NULL && dir_ter == NULL) {
            nt++;
            if (nt == i)
                dir_ter = dir;
            dir = dir->sig;
        }
        return dir_ter;
    } else {
        return NULL;
    }
}

bool PoliP::es_cero()
{
    return nt == 0;
}

int PoliP::grado()
{
    NodoP* dir = ptr_poli;
    if (dir != NULL) {
        int max_grado = dir->exp;
        while (dir != NULL) {
            if (dir->exp > max_grado)
                max_grado = dir->exp;
            dir = dir->sig;
        }
        return max_grado;
    } else
        cout << "POLINOMIO NO TIENE TERMINOS\n";
}

int PoliP::coeficiente(int exp)
{
    NodoP* dir = buscar_exponente(exp);
    if (dir != NULL)
        return dir->coef;
    else
        cout << "POLINOMO NO TIENE ESTE TERMINO\n";
}

/*
 NodoP* PoliP::anterior(NodoP* dir) {
 NodoP* x = ptr_poli; ;
 NodoP* ant = NULL;
 while (x != NULL) {
 if (x == dir)
 return ant;
 ant = x;
 x = x->sig;
 }
 return NULL;
 }
 */

void PoliP::asignar_coeficiente(int coef, int exp)
{
    NodoP* dir = buscar_exponente(exp);
    if (dir != NULL) {
        dir->coef = coef;
        if (coef == 0) {
            if (dir == ptr_poli) { // Se elimina el primero
                ptr_poli = ptr_poli->sig;
            } else {
                NodoP* x = ptr_poli;
                ;
                NodoP* ant = NULL;
                while (x != NULL) {
                    if (x == dir)
                        break;
                    ant = x;
                    x = x->sig;
                }
                // --
                ant->sig = dir->sig;
            }
            delete (dir);
            nt--;
        }
    } else
        cout << "POLINOMO NO TIENE ESTE TERMINO\n";
}

/*
 void PoliP::asignar_coeficiente(int coef, int exp) {
 NodoP* dir = buscar_exponente(exp);
 if (dir != NULL) {
 dir->coef = coef;
 if (coef == 0) {
 if (dir == ptr_poli) { // Se elimina el primero
 ptr_poli = ptr_poli->sig;
 }
 else {
 //-----------------
 NodoP* x = ptr_poli; ;
 NodoP* ant = NULL;
 while (x != NULL) {
 if (x == dir)
 break;
 ant = x;
 x = x->sig;
 }
 //-----------------
 ant->sig = dir->sig;
 }
 delete(dir);
 nt--;
 }
 }
 else
 cout << "POLINOMO NO TIENE ESTE TERMINO\n";
 } */

void PoliP::poner_termino(int coef, int exp)
{
    if (coef != 0 && exp >= 0) {
        NodoP* existe = buscar_exponente(exp);
        if (existe == NULL) { // Nueva Inserci�n
            NodoP* aux = new NodoP();
            if (aux != NULL) {
                aux->coef = coef;
                aux->exp = exp;

                // Agregar l�gica para mantener el polinomio ordenado de mayor a menor
                if (ptr_poli == NULL || exp > ptr_poli->exp) {
                    aux->sig = ptr_poli;
                    ptr_poli = aux;
                } else {
                    NodoP* actual = ptr_poli;
                    while (actual->sig != NULL && exp < actual->sig->exp) {
                        actual = actual->sig;
                    }
                    aux->sig = actual->sig;
                    actual->sig = aux;
                }

                nt++;
            }
        } else { // Modificar
            int nuevo_coef = existe->coef + coef;
            existe->coef = nuevo_coef;
            if (nuevo_coef == 0) {
                if (existe == ptr_poli) { // Se elimina el primero
                    ptr_poli = ptr_poli->sig;
                } else {
                    NodoP* x = ptr_poli;
                    NodoP* ant = NULL;
                    while (x != NULL) {
                        if (x == existe)
                            break;
                        ant = x;
                        x = x->sig;
                    }
                    // --
                    ant->sig = existe->sig;
                }
                delete (existe);
                nt--;
            }
        }
    }
}
//void PoliP::poner_termino(int coef, int exp)
//{
//	if (coef != 0 && exp >= 0) {
//		NodoP* existe = buscar_exponente(exp);
//		if (existe == NULL) { // Nueva Inserci�n
//			NodoP* aux = new NodoP();
//			if (aux != NULL) {
//				aux->coef = coef;
//				aux->exp = exp;
//				aux->sig = ptr_poli;
//				ptr_poli = aux;
//				nt++;
//			}
//		} else { // Modificar
//			int nuevo_coef = existe->coef + coef;
//			existe->coef = nuevo_coef;
//			if (nuevo_coef == 0) {
//				if (existe == ptr_poli) { // Se elimina el primero
//					ptr_poli = ptr_poli->sig;
//				} else {
//					NodoP* x = ptr_poli;
//					NodoP* ant = NULL;
//					while (x != NULL) {
//						if (x == existe)
//							break;
//						ant = x;
//						x = x->sig;
//					}
//					ant->sig = existe->sig;
//				}
//				delete (existe);
//				nt--;
//			}
//		}
//	}
//}


int PoliP::numero_terminos()
{
    return nt;
}

int PoliP::exponente(int nro)
{
    NodoP* dir = buscar_termino_n(nro);
    if (dir != NULL)
        return dir->exp;
    else
        cout << "NO EXISTE ESE NUMERO DE TERMINO\n";
}

void PoliP::sumar(PoliP* p1, PoliP* p2, PoliP*&pr)
{
    pr = new PoliP();
    for (int i = 1; i <= p1->numero_terminos(); i++) {
        int ex = p1->exponente(i);
        int co = p1->coeficiente(ex);
        pr->poner_termino(ex, co);
    }
    for (int i = 1; i <= p2->numero_terminos(); i++) {
        int ex = p2->exponente(i);
        int co = p2->coeficiente(ex);
        pr->poner_termino(ex, co);
    }
}

void PoliP::restar(PoliP* p1, PoliP* p2, PoliP*&pr)
{
    pr = new PoliP();
    for (int i = 1; i <= p1->numero_terminos(); i++) {
        int ex = p1->exponente(i);
        int co = p1->coeficiente(ex);
        pr->poner_termino(ex, co);
    }
    for (int i = 1; i <= p2->numero_terminos(); i++) {
        int ex = p2->exponente(i);
        int co = p2->coeficiente(ex);
        pr->poner_termino(-ex, co);
    }
}

void PoliP::multiplicar(PoliP* p1, PoliP* p2, PoliP*&pr)
{
    pr = new PoliP();
    int fil = p2->numero_terminos();
    int term = p1->numero_terminos();
    for (int i = 0; i < fil; i++) {
        int exD = p2->exponente(i + 1);
        int coD = p2->coeficiente(exD);
        for (int j = 0; j < term; j++) {
            int exU = p1->exponente(j + 1);
            int coU = p1->coeficiente(exU);
            int nex = exD + exU;
            int nco = coD * coU;
            pr->poner_termino(nco, nex);
        }
    }
}

float PoliP::evalua(float x)
{
    float sum = 0.0;
    int n = numero_terminos();
    for (int i = 1; i <= n; i++) {
        int ex = exponente(i);
        int co = coeficiente(ex);
        float exp = float(ex);
        float coef = float(co);
        sum += coef * pow(x, exp);
    }
    return sum;
}

float PoliP::area(float a, float b)
{
    if (a > b)
        return area(b, a);
    else {
        float evA = 0, evB = 0;
        for (int i = 0; i < numero_terminos(); i++) {
            int ex = exponente(i + 1);
            int co = coeficiente(ex);
            evA += (float)((co * 1.0) / (ex + 1)) * pow(a, ex + 1);
            evB += (float)((co * 1.0) / (ex + 1)) * pow(b, ex + 1);
        }
        return abs(evB - evA);
    }
}

void PoliP::derivar()
{
    int n = numero_terminos();
    int* exn = new int[n];
    int* con = new int[n];
    int c = 0;
    while (!es_cero()) {
        int ex = exponente(1);
        int co = coeficiente(ex);
        poner_termino(-co, ex);
        exn[c] = ex;
        con[c] = co;
        c++;
    }
    for (int i = 0; i < n; i++) {
        int ex = exn[i];
        int co = con[i];
        poner_termino(co * ex, ex - 1);
    }
}

string PoliP::to_str()
{
    string s = "";
    for (int i = 1; i <= numero_terminos(); i++) {
        int ex = exponente(i);
        int co = coeficiente(ex);
        if (co > 0)
            s += "+";
        s += to_string(co) + "x^" + to_string(ex);
    }
    return s;
}

PoliP* PoliP::integral()
{
    PoliP* integral = new PoliP();
    for (int i = 0; i < numero_terminos(); i++) {
        int exp = exponente(i);
        double coef = coeficiente(exp);
        integral->poner_termino(coef * 1.0 / (exp + 1), exp + 1);
    }
    return integral;
}
double PoliP::area(int a, int b)
{
    PoliP* inte = integral();
    // Integral.evaluamos(b)-Integral.evaluamos(a)
    double diferencia = inte->evalua(b) - inte->evalua(a);
    return abs(diferencia);
}
void PoliP::mostrar_integral()
{
    for (int i = 0; i < numero_terminos(); i++) {
        int exp = exponente(i + 1);
        int coef = coeficiente(exp);
        cout << "(" << coef << "x^" << (exp + 1) << ")/" << (exp + 1);
        if (i < numero_terminos() - 1)
            cout << "+";
    }
    cout << endl;
}

