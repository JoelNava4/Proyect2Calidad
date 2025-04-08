#pragma once
#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>
using namespace std;

template<class T>
class Tripla
{
private:
	Tripla<T>* Sigui;
	Tripla<T>* Anter;
	vector<T> Lista;
	T Elem;
public:
	Tripla();
	void setSig(Tripla<T>* sigui);
	void setAnt(Tripla<T>* anter);
	void setElem(T elem);
	void pushLista(T elem2);
	Tripla<T>* getSig();
	Tripla<T>* getAnt();
	T getElem();
	vector<T> getLista();
	T PrimerElemLista();
	void SacarUnElemLista(T& elem);
	void EliminarUnElementoLista(T elem);
	void EliminarCaminate();
	void mostrarLista();
};
template<class T>
inline Tripla<T>::Tripla()
{
	Sigui = NULL;
	Anter = NULL;
}
template<class T>
inline void Tripla<T>::setSig(Tripla<T>* sigui)
{
	Sigui = sigui;
}

template<class T>
inline void Tripla<T>::setAnt(Tripla<T>* anter)
{
	Anter = anter;
}

template<class T>
inline void Tripla<T>::setElem(T elem)
{
	Elem = elem;
}

template<class T>
inline void Tripla<T>::pushLista(T elem2)
{
	Lista.push_back(elem2);
}

template<class T>
inline Tripla<T>* Tripla<T>::getSig()
{
	return Sigui;
}

template<class T>
inline Tripla<T>* Tripla<T>::getAnt()
{
	return Anter;
}

template<class T>
inline T Tripla<T>::getElem()
{
	return Elem;
}

template<class T>
inline vector<T> Tripla<T>::getLista()
{
	return Lista;
}

template<class T>
inline T Tripla<T>::PrimerElemLista()
{
	return Lista[0];
}

template<class T>
inline void Tripla<T>::SacarUnElemLista(T& elem)
{
	srand(time(NULL));
	int num;
	num = rand() % (Lista.size());
	elem = Lista[num];
}

template<class T>
inline void Tripla<T>::EliminarUnElementoLista(T elem)
{
	int i = 0;
	while (i < Lista.size())
	{
		if (Lista[i] == elem)
		{
			if (Lista[i] == Lista.back())
			{
				Lista.pop_back();
				i = i - 1;
			}
			else
			{
				swap(Lista.back(), Lista[i]);
				Lista.pop_back();
			}
		}
		i = i + 1;
	}
}

template<class T>
inline void Tripla<T>::EliminarCaminate()
{
	swap(Lista.back(), Lista[0]);
	Lista.pop_back();
}

template<class T>
inline void Tripla<T>::mostrarLista()
{
	for (int i = 0; i < Lista.size(); i++)
		cout << Lista[i] << endl;
}

