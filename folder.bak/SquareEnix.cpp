#include "SquareEnix.h"

SquareEnix::SquareEnix(string nNombre, int nYear, string nConsola, int nJugadores, string nGenero, char nEstado, string nSerie, double nPrecio): VideoJuego(nNombre, nYear, nConsola, nJugadores, nGenero, nEstado, nSerie, nPrecio) 
{}

string SquareEnix::getSerie()
{
	return "SQ" + serie + estado;
}

string SquareEnix::getConsola()
{
	//TODO:Solo consolas microsoft
	return consola;
}
