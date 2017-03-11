#include "MicrosoftJuego.h"

MicrosoftJuego::MicrosoftJuego(string nNombre, int nYear, string nConsola, int nJugadores, string nGenero, char nEstado, string nSerie, double nPrecio): VideoJuego(nNombre, nYear, nConsola, nJugadores, nGenero, nEstado, nSerie, nPrecio) 
{}

string MicrosoftJuego::getSerie()
{
	return "MJ" + serie + estado;
}

string MicrosoftJuego::getConsola()
{
	return consola;
}
