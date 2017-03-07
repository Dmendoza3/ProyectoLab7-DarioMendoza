#include "Microsoft.h"

string Microsoft::getModelo()
{
	switch(modelo)
	{
		case 1:{return "XBOX";}
		case 2:{return "XBOX 360";}
		case 3:{return "XBOX ONE";}
	}
	return "Codigo de modelo invalido";
}

string Microsoft::getSerie()
{
	//TODO:getModeloChar
	return "MS0"+ modelo  + serie;
}

