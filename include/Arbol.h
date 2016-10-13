#include "Nodo.h"
class Arbol
{
public:
	Nodo* Raiz;
	Arbol(Nodo* Raiz);
	bool AddNodo(int Dato);
	bool AddRec(int Dato,Nodo* aux);
	bool Elim(int ref);
	Nodo* Buscar(int ref);
	Nodo* BusqRec(int ref,Nodo* aux);
	~Arbol();
};