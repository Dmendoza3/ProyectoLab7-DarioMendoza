#include <string>

#ifndef JUEGO_H
#define JUEGO_H

class VideoJuego
{
	protected:
		string nombre;
		int year;
		string consola;
		int jugadores;
		string genero;
		char estado; //'N' nuevo 'U' usado
		string serie;
		double precio;

	public:
		//Constructor
		VideoJuego();
		VideoJuego(string, int, string, int, string, char, string, double);

		//Getters	
		string getNombre();
		int getYear();
		string getConsola();
		int getJugadores();
		string getGenero();
		char getEstado();
		virtual string getSerie();
		double getPrecio();

		//Setters
		void getNombre(string);
		void getYear(int);
		void getConsola(string);
		void getJugadores(int);
		void getGenero(string);
		void getEstado(string);
		void getSerie(char);
		void getPrecio(double);
};

#endif
