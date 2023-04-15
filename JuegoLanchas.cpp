// JuegoLanchas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "lancha.h"
#include <iostream>
#include <windows.h>
#include "stdlib.h"
using namespace std;

void startGame(Lancha& lancha1, Lancha& lancha2) {
	cout << "La partida comienza con los siguientes jugadores: " << endl;
	Sleep(1000);
	lancha1.printStats();
	Sleep(2000);
	lancha2.printStats();
	Sleep(1500);
}
void jugar(Lancha& l) {
	int dado = rand() % 6 + 1;
	cout << "La lancha " << l.getNombre() << " ha tirado el dado y ha sacado un " << dado << endl;
	l.setVelocidad((l.getVelocidad() + dado));
	cout << "Ahora tiene " << l.getVelocidad() << " de velocidad." << endl;
	if (l.getNitro()) {
		int option = 0;
		cout << "Tienes la opcion de usar el nitro, quieres usarlo?" << endl;
		while (option != 1 && option != 2) {
			cout << "Elige una de estas 2 opciones: " << endl;
			cout << "[1] Si" << endl;
			cout << "[2] No" << endl;
			cin >> option;
		}
		if (option == 1) {
			l.usarNitro();
			l.setNitro(false);
		}
	}
}
void checkWhoWins(Lancha& lancha1, Lancha& lancha2) {
	if (lancha1.getDistancia() > lancha2.getDistancia()) {
		cout << "El ganador de la carrrera es la lancha " << lancha1.getNombre() << endl;
	}
	else if (lancha1.getDistancia() == lancha2.getDistancia()) {
		cout << "Habeis empatado." << endl;
	}
	else {
		cout << "El ganador de la carrera es la lancha " << lancha2.getNombre() << endl;
	}
}
	
int main()
{

	Lancha lancha1("Eustakio", "azul", 0, 0, 1), lancha2("Rodolfo", "rojo", 0, 0, 1);

	startGame(lancha1, lancha2);
	system("cls");
	for (size_t i = 0; i < 5; i++)
	{
		jugar(lancha1);
		Sleep(1500);
		jugar(lancha2);
		Sleep(3000);
		system("cls");
		cout << "Al final del turno la carrera esta de la siguiente manera: " << endl;
		Sleep(1500);
		lancha1.printDistancia();
		Sleep(1500);
		lancha2.printDistancia();
		Sleep(3000);
		system("cls");
	}
	checkWhoWins(lancha1, lancha2);
}
