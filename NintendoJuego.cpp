#include "NintendoJuego.h"

NintendoJuego::NintendoJuego(string nNombre, int nYear, string nConsola, int nJugadores, string nGenero, char nEstado, string nSerie, double nPrecio): VideoJuego(nNombre, nYear, nConsola, nJugadores, nGenero, nEstado, nSerie, nPrecio) 
{}

string NintendoJuego::getSerie()
{
	return "NJ" + serie + estado;
}

string NintendoJuego::getConsola()
{
	return consola;
}
