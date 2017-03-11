#include "Sony.h"

Sony::Sony(){}

Sony::Sony(int nYear, int nModelo, char nEstado, string nSerie, double nPrecio) : Consola(nYear, nModelo, nEstado, nSerie, nPrecio)
{}

string Sony::getModelo()
{
	switch(modelo)
	{
		case 1: {return "Playstation 1";}
		case 2: {return "Playstation 2";}
		case 3: {return "Playstation 3";}
		case 4: {return "Playstation 4";}
		case 5: {return "PSP";}
		case 6: {return "PS Vita";}
	}
	return "Codigo de modelo invalido";
}
