/*Rodrigo Mayett Guzman
se definen los metodos de la clase*/
#include "Nodo.h"
class Arbol
{
public:
	Nodo* Raiz;
	Arbol(Nodo* Raiz);
	bool AddNodo(int Dato);
	bool AddRec(int Dato,Nodo* aux);
	bool Elim(int ref);
	void Crear(int Raiz);
	void intercambiar(Nodo* a,Nodo* aux);
	Nodo* Buscar(int ref);
	Nodo* BusqRec(int ref,Nodo* aux);
	~Arbol();
};