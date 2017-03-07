#include "VideoJuego.h"

//Constructor
VideoJuego(){}

VideoJuego(string nNombre, int nYear, string nConsola, int nJugadores, string nGenero, char nEstado, string nSerie, double nPrecio)
{
	nombre = nNombre;
	year = nYear;
	consola = nConsola;
	jugadores = nJugadores;
	genero = nGenero;
	estado = nEstado;
	serie = nSerie;
	precio = nPrecio;
}

//Getters   
string getNombre(){return nombre;}
int getYear(){return year;}
string getConsola(){return consola;}
int getJugadores(){return jugadores;}
string getGenero(){return genero;}
char getEstado(){return estado;}
string getSerie(){return serie;}
double getPrecio(){return precio;}

//Setters
void getNombre(string nNombre){nombre = nNombre;}
void getYear(int nYear){year = nYear;}
void getConsola(string nConsola){consola = nConsola;}
void getJugadores(int nJugadores){jugadores = nJugadores;}
void getGenero(string nGenero){genero = nGenero;}
void getEstado(string nEstado){estado = nEstado;}
void getSerie(char nSerie){serie = nSerie;}
void getPrecio(double nPrecio){precio = nPrecio;}
