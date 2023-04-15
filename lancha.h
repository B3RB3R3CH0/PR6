#pragma once
using namespace std;
#include <iostream>
class Lancha
{
private:
	string nombre;
	string color;
	int velocidad;
	int distancia;
	bool nitro;
public:
	//CONSTRUCTOR
	Lancha();
	Lancha(string pNombre, string pColor, int pVelocidad, int pDistancia, bool pNitro);
	
	//GETTERS
	string getNombre();
	string getColor();
	int getVelocidad();
	int getDistancia();
	bool getNitro();
					 
	//SETTERS
	void setNombre(string pNombre);
	void setColor(string pColor);
	void setVelocidad(int pVelocidad);
	void setDistancia(int pDistancia);
	void setNitro(bool pNitro);

	//METHODS
	void printStats();
	void usarNitro();
	void printDistancia();
};

