#include "Sega.h"

Sega::Sega(string nNombre, int nYear, string nConsola, int nJugadores, string nGenero, char nEstado, string nSerie, double nPrecio): VideoJuego(nNombre, nYear, nConsola, nJugadores, nGenero, nEstado, nSerie, nPrecio) 
{}

string Sega::getSerie()
{
	return "SE" + serie + estado;
}

string Sega::getConsola()
{
	return consola;
}
