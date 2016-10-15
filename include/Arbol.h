/*Rodrigo Mayett Guzman
se definen los metodos de la clase*/
#include "Nodo.h"
class Arbol
{
public:
	Nodo* Raiz;
	Arbol(int Dato);
	bool AddNodo(int Dato);
	void Crear();
	bool AddRec(int Dato,Nodo* aux);
	bool Elim(int ref);
	void intercambiar(Nodo* a,Nodo* aux);
	Nodo* Buscar(int ref);
	Nodo* BusqRec(int ref,Nodo* aux);
	void imprimir();

private: 
	int imprimirRec(Nodo* aux);
	//~Arbol();
};