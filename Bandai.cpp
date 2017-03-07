#include "Bandai.h"

Bandai::Bandai(string nNombre, int nYear, string nConsola, int nJugadores, string nGenero, char nEstado, string nSerie, double nPrecio): VideoJuego(nNombre, nYear, nConsola, nJugadores, nGenero, nEstado, nSerie, nPrecio) 
{}

string Bandai::getSerie()
{
	return "BA" + serie + estado;
}

string Bandai::getConsola()
{
	return consola;
}
