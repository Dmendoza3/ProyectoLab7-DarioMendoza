#include "VideoJuego.h"

//Constructor
VideoJuego::VideoJuego(){}

VideoJuego::VideoJuego(string nNombre, int nYear, string nConsola, int nJugadores, string nGenero, char nEstado, string nSerie, double nPrecio)
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
string VideoJuego::getNombre(){return nombre;}
int VideoJuego::getYear(){return year;}
string VideoJuego::getConsola(){return consola;}
int VideoJuego::getJugadores(){return jugadores;}
string VideoJuego::getGenero(){return genero;}
char VideoJuego::getEstado(){return estado;}
string VideoJuego::getSerie(){return serie;}
double VideoJuego::getPrecio(){return precio;}

//Setters
void VideoJuego::setNombre(string nNombre){nombre = nNombre;}
void VideoJuego::setYear(int nYear){year = nYear;}
void VideoJuego::setConsola(string nConsola){consola = nConsola;}
void VideoJuego::setJugadores(int nJugadores){jugadores = nJugadores;}
void VideoJuego::setGenero(string nGenero){genero = nGenero;}
void VideoJuego::setEstado(char nEstado){estado = nEstado;}
void VideoJuego::setSerie(string nSerie){serie = nSerie;}
void VideoJuego::setPrecio(double nPrecio){precio = nPrecio;}

//Destructor
VideoJuego::~VideoJuego(){};
