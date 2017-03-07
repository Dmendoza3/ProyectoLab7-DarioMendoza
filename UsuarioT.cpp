#include "UsuarioA.h"

Usuario::UsuarioA(){}

Usuario::UsuarioA(string nNombre, string nPassword) : Usuario(nNombre)
{
	pass = nPassword;
}

string UsuarioA::getPassword()
{
	reutn pass;
}

void UsuarioA::setPassword(string nPassword)
{
	pass = nPassword;
}
