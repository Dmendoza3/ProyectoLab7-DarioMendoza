#include "Microsoft.h"

Microsoft::Microsoft(){}

Microsoft::Microsoft(int nYear, int nModelo, char nEstado, string nSerie, double nPrecio) : Consola(nYear, nModelo, nEstado, nSerie, nPrecio)
{}

string Microsoft::getModelo()
{
	switch(modelo)
	{
		case 1:{return "Xbox";}
		case 2:{return "Xbox 360";}
		case 3:{return "Xbox One";}
	}
	return "Codigo de modelo invalido";
}
