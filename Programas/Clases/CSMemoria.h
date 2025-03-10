//---------------------------------------------------------------------------

#ifndef CSMemoriaH
#define CSMemoriaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAX = 20;
const int NULO = -1;

struct NodoMem
{
	int dato;
	string id;
	int link;
};

class CsMemoria
{
  private:
	NodoMem* mem; //NodoMem mem[MAX] Nodo mem fila de dato , cadena y link
	int libre;
	int numero_ids(string id);
  public:
	CsMemoria();
	int new_espacio(string cadena);
	void delete_espacio(int dir);
	void poner_dato(int dir, string cadena_id, int valor);

	int obtener_dato(int dir, string cadena_id);
	int espacio_disponible();
	int espacio_ocupado();
	bool dir_libre(int dir);
	void mostrar();
};

#endif

