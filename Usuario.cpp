#include "Usuario.h"

Usuario::Usuario(){}

Usuario::Usuario(string nNombre)
{
	nombre = nNombre;
}

string Usuario::getNombre()
{
	return nombre;
}

void Usuario::setNombre(string nNombre)
{
	nombre = nNombre;
}
