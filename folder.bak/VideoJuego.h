#include <string>

using namespace std;

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
		void setNombre(string);
		void setYear(int);
		virtual void setConsola(string);
		void setJugadores(int);
		void setGenero(string);
		void setEstado(char);
		virtual void setSerie(string);
		void setPrecio(double);
		
		//Destructor
		~VideoJuego();
};

#endif
