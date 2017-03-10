#include "Nintendo.h"

Nintendo::Nintendo(){}

Nintendo::Nintendo(int nYear, int nModelo, char nEstado, string nSerie, double nPrecio) : Consola(nYear, nModelo, nEstado, nSerie, nPrecio)
{}

string Nintendo::getModelo()
{
	switch(modelo)
	{
		case 1:{return "Nintendo Entertainment System";}
		case 2:{return "Super Nintendo Entertainment System";}
		case 3:{return "Nintendo 64";}
		case 4:{return "Nintendo Gamecube";}
		case 5:{return "Nintento Wii";}
		case 6:{return "Nintento Wii U";}
		case 7:{return "Nintendo Switch";}
		case 8:{return "Gameboy";}
		case 9:{return "Gameboy Colors";}
		case 10:{return "Gameboy Advance";}
		case 11:{return "Nintendo DS";}
		case 12:{return "Nintendo DSi";}
		case 13:{return "Nintendo 3DS";}
		case 14:{return "Nintendo New 3DS";}
	}
	return "Codigo de modelo invalido";
}
