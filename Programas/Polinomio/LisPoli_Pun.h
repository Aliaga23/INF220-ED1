//---------------------------------------------------------------------------

#ifndef LisPoli_PunH
#define LisPoli_PunH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "Listas.h"

using namespace std;

class PoliLP
{
  private:
    ListaP* pol;
    direccionP buscar_exponente(int exp);
    direccionP buscar_termino_n(int i);
  public:
    PoliLP();
    bool es_cero();
    int grado();
    int coeficiente(int exp);
    void asignar_coeficiente(int coef, int exp);
    void poner_termino(int coef, int exp);
    int numero_terminos();
    int exponente(int nro);
    void sumar(PoliLP* p1, PoliLP* p2, PoliLP*&pr);
    void restar(PoliLP* p1, PoliLP* p2, PoliLP*&pr);
    void multiplicar(PoliLP* p1, PoliLP* p2, PoliLP*&pr);
    void derivar();
    string to_str();
    float evalua(float x);
};
#endif

