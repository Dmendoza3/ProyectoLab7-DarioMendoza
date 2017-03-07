#include "SonyJuego.h"

SonyJuego::SonyJuego(string nNombre, int nYear, string nConsola, int nJugadores, string nGenero, char nEstado, string nSerie, double nPrecio): VideoJuego(nNombre, nYear, nConsola, nJugadores, nGenero, nEstado, nSerie, nPrecio) 
{}

string SonyJuego::getSerie()
{
	return "SJ" + serie + estado;
}

string SonyJuego::getConsola()
{
	return consola;
}
