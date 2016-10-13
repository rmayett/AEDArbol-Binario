#include "Arbol.h"

Arbol::Arbol(Nodo* Raiz){
	this->Raiz=Raiz;
}
bool Arbol::AddNodo(int Dato){
	if (Buscar(Dato)!=NULL)
	{
		return true;
	}
	return AddRec(Dato,Raiz);
}
bool Arbol::AddRec(int Dato,Nodo* aux){
	bool Res;
	if (Dato<aux->getDato())
	{
		if (aux->Hizq!=NULL)
		{
			Res=AddRec(Dato,aux->Hizq);
		}
		else{
			Nodo* n= new Nodo(Dato,aux);
			aux->Hizq=n;
			return true;
		}
	}
	else{
		if (aux->Hder!=NULL)
		{
			Res=AddRec(Dato,aux->Hder);
		}
		else{
			Nodo* n= new Nodo(Dato,aux);
			aux->Hder=n;
			return true;
		}
	}
	return Res;
}
Nodo* Arbol::Buscar(int ref){
		if (Raiz==NULL)
		{
			return NULL;
		}
		return BusqRec(ref,Raiz);
}
Nodo* Arbol::BusqRec(int ref,Nodo* aux){
	Nodo* Busqueda=aux;
	Nodo* Res;
	if (Busqueda->getDato()==ref)
	{
		return Busqueda;
	}
	if (Busqueda->Hder==NULL&&Busqueda->Hizq==NULL)
	{
		return NULL;
	}
	if (ref<Busqueda->getDato()&&Busqueda->Hizq!=NULL)
	{
		Res=BusqRec(ref,Busqueda->Hizq);
	}
	else{if (ref>Busqueda->getDato()&&Busqueda->Hder!=NULL)
	{
		Res=BusqRec(ref,Busqueda->Hder);
	}
	}
	if (Res!=NULL)
	{
		return Res;
	}
	return NULL;
}
