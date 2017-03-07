#include "ElectronicArts.h"

ElectronicArts::ElectronicArts(string nNombre, int nYear, string nConsola, int nJugadores, string nGenero, char nEstado, string nSerie, double nPrecio): VideoJuego(nNombre, nYear, nConsola, nJugadores, nGenero, nEstado, nSerie, nPrecio) 
{}

string ElectronicArts::getSerie()
{
	return "EA" + serie + estado;
}

string ElectronicArts::getConsola()
{
	return consola;
}
