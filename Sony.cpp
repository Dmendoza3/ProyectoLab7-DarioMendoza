#include "Sony.h"

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

string Sony::getSerie()
{
	return "SN0" + modelo  + serie;
}

