//---------------------------------------------------------------------------

#pragma hdrstop

#include "DicolaV2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

DicolaV2::DicolaV2()
{
    ini = fin = 0;
    v = new int[MAXVD2];
}

bool DicolaV2::vacia()
{
    return ini == fin;
}

void DicolaV2::poner(int e)
{
    if (fin < MAXVD2) {
        v[fin] = e;
        fin++;
    }
}

void DicolaV2::sacar(int &e)
{
    if (!vacia()) {
        e = v[0];
        for (int i = 0; i < fin; i++)
            v[i] = v[i + 1];
        fin--;
    }
}

int DicolaV2::primero()
{
    if (!vacia())
        return v[0];
}

int DicolaV2::ultimo()
{
    if (!vacia())
        return v[fin];
}

void DicolaV2::poner_frente(int e)
{
    if (fin < MAXVD2) {
        for (int i = fin; i > 0; i--)
            v[i] = v[i - 1];
        v[0] = e;
        fin++;
    }
}

void DicolaV2::sacar_final(int &e)
{
    if (!vacia()) {
        e = v[fin];
        fin--;
    }
}

string DicolaV2::to_str()
{
    string s = "<<";
    int e;
    DicolaV2* aux = new DicolaV2();
    while (!vacia()) {
        sacar(e);
        aux->poner(e);
        s += to_string(e);
        if (!vacia())
            s += ",";
    }
    while (!aux->vacia()) {
        aux->sacar(e);
        poner(e);
    }
    return s + "<<";
}
