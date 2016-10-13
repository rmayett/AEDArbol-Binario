/*Rodrigo Mayett Guzman
se definen los metodos del arbol*/
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
void Arbol::Crear(){
	Arbol ar(6);
	ar.AddNodo(9);
	ar.AddNodo(10);
	ar.AddNodo(2);
	ar.AddNodo(5);
	ar.AddNodo(8);
	ar.AddNodo(12);
	ar.AddNodo(7);
	ar.AddNodo(11);	
	ar.AddNodo(20);
	ar.AddNodo(19);
	ar.AddNodo(18);
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
bool Arbol::Elim(int ref){
	Nodo* aux=Buscar(ref);
	if (aux==NULL)
	{
		return false;
	}
	if (aux->Hizq==NULL&&aux->Hder==NULL)
	{
		if (aux->Padre->Hizq==aux)
		{
			aux->Padre->Hizq=NULL;
		}
		else{
			aux->Padre->Hder=NULL;
		}
		aux->Padre=NULL;
	}
	if (aux->Hizq!=NULL)
	{
		if (aux->Hizq->Hder==NULL)
		{
			aux->Padre->Hder=aux->Hizq;
			aux->Hizq->Padre=aux->Padre;
			aux->Padre=NULL;
			aux->Hizq->Hder=aux->Hder;
			aux->Hder->Padre=aux->Hizq;
			aux->Hder=NULL;
			aux->Hizq=NULL;
		}
	}
	else{
		Nodo* a=aux->Hizq->Hder;
		while(a->Hder!=NULL){
			a=a->Hder;
		}
		if (a->Hizq!=NULL)
		{
			a->Hizq->Padre=a->Padre;
			a->Padre->Hder=a->Hizq;
			a->Hizq=NULL;
		}
		intercambiar(a,aux);
	}
}
void Arbol::intercambiar(Nodo* a,Nodo* aux){
	a->Padre->Hder=NULL;
	a->Padre=aux->Padre;
	a->Hder=aux->Hder;
	a->Hizq=aux->Hizq;
	aux->Hizq->Padre=a;
	aux->Hder->Padre=a;
	aux->Padre=a;
	aux->Hder=NULL;
	aux->Hizq=NULL;
	aux->Padre=NULL;
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
