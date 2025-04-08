#include "MinCut.h"
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>

int main()
{
	MinCut<string> M1;
	vector<string> ListaInsertar;
	string elem;
	ifstream archivo;
	int n = 0, formula, min, res;
	/*char opc;
	do
	{
		cout << "----MENU---" << endl;
		cout << "a.Insertar:" << endl;
		cout << "b.Corte Minimo:" << endl;
		cout << "c.MostrarCiudades:" << endl;
		cout << "d.MostrarGrafo:" << endl;
		cout << "q.Salir:" << endl;
		cin >> opc;
		switch (opc)
		{
		case 'a':
			archivo.open("Ciudades.txt", ios::in);
			if (archivo.fail())
			{
				cout << "no se pudo abrir" << endl;
				exit(1);
			}
			else
			{
				while (!archivo.eof())
				{
					archivo >> elem;
					if (elem != "-1")
					{
						ListaInsertar.push_back(elem);
					}
					else
					{
						for (int i = 1; i < ListaInsertar.size(); i++)
						{
							M1.insertar(ListaInsertar[0], ListaInsertar[i]);
						}
						ListaInsertar.clear();
					}
				}
			}
			archivo.close();
			break;
		case 'b':
			cout << M1.CorteMinimo() << endl;
			break;
		case 'c':
			M1.mostrarCiudades();
			break;
		case 'd':
			M1.mostrarGrafo();
			break;
		case 'q':
			cout << "Bueno, chau!" << endl; break;
		default:
			cout << "Operacion no disponible" << endl; break;
		}
	} while (opc != 'q');*/
	archivo.open("Ciudades.txt", ios::in);
	if (archivo.fail())
	{
		cout << "no se pudo abrir" << endl;
		exit(1);
	}
	else
	{
		while (!archivo.eof())
		{
			archivo >> elem;
			if (elem != "-1")
			{
				n = n + 1;
			}
		}
	}
	archivo.close();
	formula = (pow(n, 2)) * (log10(n));
	cout << "-------------MinCut-----------" << endl;
	for (int i = 0; i < formula; i++)
	{
		cout << "-------------" << endl;
		archivo.open("Ciudades.txt", ios::in);
		if (archivo.fail())
		{
			cout << "no se pudo abrir" << endl;
			exit(1);
		}
		else
		{
			while (!archivo.eof())
			{
				archivo >> elem;
				if (elem != "-1")
				{
					ListaInsertar.push_back(elem);
				}
				else
				{
					for (int i = 1; i < ListaInsertar.size(); i++)
					{
						M1.insertar(ListaInsertar[0], ListaInsertar[i]);
					}
					ListaInsertar.clear();
				}
			}
		}
		archivo.close();
		res = M1.CorteMinimo();
		if (i == 0)
			min = res;
		else
		{
			if (res < min)
				min = res;
		}
		cout << min << endl;
		cout << "-------------" << endl;
	}
	return 0;
}