#include "UsuarioA.h"

//Constructor
UsuarioA::UsuarioA(){}

UsuarioA::UsuarioA(string nNombre, string nPassword) : Usuario(nNombre)
{
	pass = nPassword;
}


//Getters
string UsuarioA::getPassword()
{
	return pass;
}

//Setters
void UsuarioA::setPassword(string nPassword)
{
	pass = nPassword;
}
