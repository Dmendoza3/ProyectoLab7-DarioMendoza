#include "Ubisoft.h"

Ubisoft::Ubisoft(string nNombre, int nYear, string nConsola, int nJugadores, string nGenero, char nEstado, string nSerie, double nPrecio): VideoJuego(nNombre, nYear, nConsola, nJugadores, nGenero, nEstado, nSerie, nPrecio) 
{}

string Ubisoft::getSerie()
{
	return "UB" + serie + estado;
}

string Ubisoft::getConsola()
{
	//TODO:Solo consolas microsoft
	return consola;
}
