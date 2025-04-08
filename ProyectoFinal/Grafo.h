#pragma once
#include "Lista8.h"
#define TAM 409

template<class T>
class Grafo
{
private:
	Lista8<T>* hash[TAM];
public:
	Grafo();
	int funcionHash(T elem);
	void insertar(T elem, T elem2,vector<T>& ciudades);
	Tripla<T>* buscar(T elem);
	bool eliminar(T elem);
	void SacarAdyacente(T elem, T& elem2);
	void Mostrar();
	~Grafo();
};

template<class T>
inline Grafo<T>::Grafo() {
	for (int i = 0; i < TAM; i++)
		hash[i] = new Lista8<T>();
};

template<class T>
inline int Grafo<T>::funcionHash(T elem) {
	int pos = 0;
	int var = 0;
	int numASCII;
	for (int i = 0; i < elem.size(); i++) {
		numASCII = elem[i];
		var = pow(2, 1);
		pos = pos + (var * numASCII);
	}
	if (pos < 0) {
		pos = pos * -1;
	}
	return pos % TAM;
};

template<class T>
inline void Grafo<T>::insertar(T elem, T elem2, vector<T>& ciudades) {
	Tripla<T>* aux;
	aux = buscar(elem);
	if (aux == NULL)
	{
		hash[funcionHash(elem)]->insertar_Final(elem, elem2);
		ciudades.push_back(elem);
	}
	else
		aux->pushLista(elem2);
};

template<class T>
inline Tripla<T>* Grafo<T>::buscar(T elem) {
	Tripla<T>* resp = NULL;
	resp = hash[funcionHash(elem)]->buscar_No_Recursivo(elem);
	return resp;
};

template<class T>
inline bool Grafo<T>::eliminar(T elem) {
	bool resp;
	resp = hash[funcionHash(elem)]->eliminar_elem_dado(elem);
	return resp;
}

template<class T>
inline void Grafo<T>::SacarAdyacente(T elem, T& elem2)
{
	Tripla<T>* resp = NULL;
	resp = hash[funcionHash(elem)]->buscar_No_Recursivo(elem);
	resp->SacarUnElemLista(elem2);
}

template<class T>
inline void Grafo<T>::Mostrar()
{
	for (int i = 0; i < TAM; i++)
	{
		if (hash[i]->getPrimer() != NULL)
		{
			hash[i]->mostrar();
		}
	}
};

template<class T>
inline Grafo<T>::~Grafo() {
	for (int i = 0; i < TAM; i++)
		delete hash[i];
};


