#include <iostream>
#include "UCPolinomio.h"

using namespace std;
bool SonOpuestos(Cpolinomio* A, Cpolinomio* B);

int main() {
	Cpolinomio* a = new Cpolinomio();
	Cpolinomio* b = new Cpolinomio();

	/*b->poner_termino(2, 2);
	b->poner_termino(3, 5);
	b->poner_termino(-2, 3);
	//cout << "\nLa a es: "<<a->to_str()<<endl;
	cout << "\n P(X)= "<<b->to_str()<<endl;
	//cout << "\n---------------------------------------------\n";

	float fx=b->evaluar(2.5);
		cout << "\n fx es: "<<fx<<endl; */
    a->poner_termino(2, 2);
	b->poner_termino(2, 2);
	//b->poner_termino(-3, 7);
	cout << "\nLa a es: "<<a->to_str()<<endl;
	cout << "\n P(X)= "<<b->to_str()<<endl;
	cout << "\n---------------------------------------------\n";

	if (SonOpuestos(a,b))
		cout << "Son opuestos" << endl;
	else
		cout << "No son opuestos" << endl;
	system("PAUSE");
	return 0;
}

bool SonOpuestos(Cpolinomio* A, Cpolinomio* B){
	 if (A->numero_terminos() == B->numero_terminos())
	{
		int contr = 0;
		for (int i = 1; i <=A->numero_terminos(); i++) {
				int exp = A->exponente(i);
				int coef = A->coeficiente(exp);
				int cont = 0;
				int expB = B->exponente(i);
				int coefB = B->coeficiente(expB);
			if ((expB == exp) && (-coefB == coef)){
					contr++;
			}
			if (contr == 0)
			{
				return false;
			}
		}
		if (contr == A->numero_terminos())
		{
			return true;
		}
	}else{
		return false;
	}
}

