#pragma once
#include "Grafo.h"

template<class T>
class MinCut
{
private:
	vector<T> Ciudades;
	Grafo<T> Grafo1;
public:
	MinCut();
	void insertar(T elem, T elem2);
	void SacarAletorios(T& V1, T& V2);
	void Contraer(T& V1, T& V2);
	int CorteMinimo();
	void ReiniciarGrafoyLista();
	void mostrarCiudades();
	void mostrarGrafo();
};

template<class T>
inline MinCut<T>::MinCut()
{

}

template<class T>
inline void MinCut<T>::insertar(T elem, T elem2)
{
	Grafo1.insertar(elem, elem2, Ciudades);
}

template<class T>
inline void MinCut<T>::SacarAletorios(T& V1,T& V2)
{
	srand(time(NULL));
	int num;
	num = rand() % (Ciudades.size());
	V2 = Ciudades[num];
	Grafo1.SacarAdyacente(Ciudades[num], V1);
	swap(Ciudades.back(), Ciudades[num]);
	Ciudades.pop_back();
}

template<class T>
inline void MinCut<T>::Contraer(T& V1, T& V2)
{
	SacarAletorios(V1, V2);
	T caminante;
	bool rep;
	Grafo1.buscar(V2)->EliminarUnElementoLista(V1);
	Grafo1.buscar(V1)->EliminarUnElementoLista(V2);
	while (Grafo1.buscar(V2)->getLista().size() != 0)
	{
		caminante = Grafo1.buscar(V2)->PrimerElemLista();
		Grafo1.buscar(V1)->pushLista(caminante);
		Grafo1.buscar(caminante)->EliminarUnElementoLista(V2);
		Grafo1.buscar(caminante)->pushLista(V1);
		Grafo1.buscar(V2)->EliminarCaminate();
	}
	rep = Grafo1.eliminar(V2);
}

template<class T>
inline int MinCut<T>::CorteMinimo()
{
	int min;
	T V1, V2;
	while (Ciudades.size() > 2)
	{
		Contraer(V1, V2);
	}
	min = Grafo1.buscar(V1)->getLista().size();
	//Grafo1.Mostrar();
	ReiniciarGrafoyLista();
	return min;
}

template<class T>
inline void MinCut<T>::ReiniciarGrafoyLista()
{
	bool res;
	for (int i = 0; i < Ciudades.size(); i++)
	{
		res = Grafo1.eliminar(Ciudades[i]);
	}
	Ciudades.clear();
}

template<class T>
inline void MinCut<T>::mostrarCiudades()
{
	for (int i = 0; i < Ciudades.size(); i++)
		cout << Ciudades[i] << endl;
	cout << Ciudades.size() << endl;
}

template<class T>
inline void MinCut<T>::mostrarGrafo()
{
	Grafo1.Mostrar();
}
