#include "Konami.h"

Konami::Konami(string nNombre, int nYear, string nConsola, int nJugadores, string nGenero, char nEstado, string nSerie, double nPrecio): VideoJuego(nNombre, nYear, nConsola, nJugadores, nGenero, nEstado, nSerie, nPrecio) 
{}

string Konami::getSerie()
{
	return "KO" + serie + estado;
}

string Konami::getConsola()
{
	return consola;
}
