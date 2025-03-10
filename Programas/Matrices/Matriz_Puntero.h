//---------------------------------------------------------------------------

#ifndef Matriz_PunteroH
#define Matriz_PunteroH
//---------------------------------------------------------------------------
 #include <iostream>
#include <string>

using namespace std;

struct NodoMC{
    int fil;
    int col;
    int dato;
    NodoMC* sig;
};

class MatrizPC{
    private:
        NodoMC* ptrMatD;
		int repe, df, dc;
		int nt;

        NodoMC* buscar(int f, int c);
    public:
        MatrizPC();
        void dimensionar(int f,int c);
        int dimension_fila();
        int dimension_columna();
        void poner(int f, int c, int valor);
        int elemento(int f, int c);
        void definir_valor_repetido(int valor);
		string to_str();
		int sumarElementosValidos();
                       void transponer()  ;
};

#endif
