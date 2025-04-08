#pragma once
#include "Tripla.h"

template<class T>
class Lista8
{
private:
	Tripla<T>* primer;
	Tripla<T>* ultimo;
public:
	Lista8();
	void insertar_Principio(T elem, T elem2);
	void insertar_Final(T elem, T elem2);
	void mostrar();
	void eliminar_Principio();
	void eliminar_Final();
	Tripla<T>* buscar_No_Recursivo(T elem);
	bool eliminar_elem_dado(T elem);
	Tripla<T>* getPrimer();
};
template<class T>
inline Lista8<T>::Lista8()
{
	primer = NULL;
	ultimo = NULL;
}

template<class T>
inline void Lista8<T>::insertar_Principio(T elem, T elem2)
{
	if (primer == NULL)
	{
		primer = new Tripla<T>();
		primer->setElem(elem);
		primer->pushLista(elem2);
		ultimo = primer;
	}
	else
	{
		Tripla<T>* segundo = new Tripla<T>();
		segundo->setElem(elem);
		segundo->pushLista(elem2);
		segundo->setSig(primer);
		primer->setAnt(segundo);
		primer = segundo;

	}
}

template<class T>
inline void Lista8<T>::insertar_Final(T elem, T elem2)
{
	if (primer == NULL)
	{
		primer = new Tripla<T>();
		primer->setElem(elem);
		primer->pushLista(elem2);
		ultimo = primer;
	}
	else
	{
		Tripla<T>* aux = new Tripla<T>();
		aux->setElem(elem);
		aux->pushLista(elem2);
		ultimo->setSig(aux);
		aux->setAnt(ultimo);
		ultimo = aux;
	}
}

template<class T>
inline void Lista8<T>::mostrar()
{
	Tripla<T>* aux = primer;
	while (aux != NULL)
	{
		cout << "----------" << endl;
		cout << aux->getElem() << endl;
		cout << "Conecxion(es):" << endl;
		aux->mostrarLista();
		cout << "----------" << endl;
		aux = aux->getSig();
	}
}

template<class T>
inline void Lista8<T>::eliminar_Principio()
{
	if (primer != NULL)
	{
		if (primer == ultimo)
		{
			delete primer;
			primer = NULL;
			ultimo = NULL;
		}
		else
		{
			Tripla<T>* aux = primer->getSig();
			aux->setAnt(NULL);
			delete primer;
			primer = aux;
		}
	}
}

template<class T>
inline void Lista8<T>::eliminar_Final()
{
	if (primer != NULL)
	{
		if (primer == ultimo)
		{
			delete ultimo;
			primer = NULL;
			ultimo = NULL;
		}
		else
		{
			Tripla<T>* aux = ultimo->getAnt();
			aux->setSig(NULL);
			delete ultimo;
			ultimo = aux;
		}
	}
}

template<class T>
inline Tripla<T>* Lista8<T>::buscar_No_Recursivo(T elem)
{
	Tripla<T>* resp = NULL;
	Tripla<T>* aux = primer;
	while (aux != NULL)
	{
		if (aux->getElem() == elem)
		{
			resp = aux;
			break;
		}
		aux = aux->getSig();
	}
	return resp;
}

template<class T>
inline bool Lista8<T>::eliminar_elem_dado(T elem)
{
	bool resp = false;
	if (primer != NULL)
	{
		Tripla<T>* aux = buscar_No_Recursivo(elem);
		if (aux == primer)
		{
			eliminar_Principio();
			resp = true;
		}
		else {
			if (aux == ultimo)
			{
				eliminar_Final();
				resp = true;
			}
			else
			{
				if (aux != NULL) {
					Tripla<T>* aux2 = aux->getAnt();
					Tripla<T>* aux3 = aux->getSig();
					aux2->setSig(aux->getSig());
					aux3->setAnt(aux->getAnt());
					delete aux;
					resp = true;
				}
			}
		}
	}
	return resp;
}

template<class T>
inline Tripla<T>* Lista8<T>::getPrimer()
{
	return primer;
}


