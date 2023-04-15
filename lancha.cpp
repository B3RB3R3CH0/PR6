#include "lancha.h"
#include <windows.h>

//CONSTRUCTOR
Lancha::Lancha() {
}

Lancha::Lancha(string pNombre, string pColor, int pVelocidad, int pDistancia, bool pNitro) {
	nombre = pNombre;
	color = pColor;
	velocidad = pVelocidad;
	distancia = pDistancia;
	nitro = pNitro;
}

//GETTERS
string Lancha::getNombre() {
	return nombre;
}
string Lancha::getColor() {
	return color;
}
int Lancha::getVelocidad() {
	return velocidad;
}
int Lancha::getDistancia() {
	return distancia;
}
bool Lancha::getNitro() {
	return nitro;
}

//SETTERS
void Lancha::setNombre(string pNombre) {
	nombre = pNombre;
}
void Lancha::setColor(string pColor) {
	color = pColor;
}
void Lancha::setVelocidad(int pVelocidad) {
	velocidad = pVelocidad;
}
void Lancha::setDistancia(int pDistancia) {
	distancia = pDistancia;
}
void Lancha::setNitro(bool pNitro) {
	nitro = pNitro;
}

//METHODS

void Lancha::printStats() {
	if (nitro) {
		cout << "La lancha " << nombre << ", de color " << color << ", tiene "
			<< velocidad << " de velocidad, ha recorrido " << distancia << " metros y tiene nitro." << endl;
	}
	else {
		cout << "La lancha " << nombre << ", de color " << color << ", tiene "
			<< velocidad << " de velocidad, ha recorrido " << distancia << " metros y no tiene nitro." << endl;
	}
}
void Lancha::usarNitro() {
	srand(time(NULL));
	int random = rand() % 2;
	if (random == 0) {
		cout << "Mala suerte, el nitro no ha hecho efecto y se te ha reducido la velocidad a la mitad." << endl;
		Lancha::setVelocidad((velocidad / 2));
	}
	else {
		cout << "El nitro ha hecho efecto y se te ha duplicado la velocidad." << endl;
		Lancha::setVelocidad((velocidad * 2));
	}
	cout << "Ahora tienes " << velocidad << " de velocidad." << endl;
}
void Lancha::printDistancia() {
	Lancha::setDistancia((distancia + velocidad * 100));
	cout << "La lancha " << nombre << " ha recorrido " << distancia << " metros de distancia" << endl;
}