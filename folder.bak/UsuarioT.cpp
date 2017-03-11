#include "UsuarioT.h"

UsuarioT::UsuarioT()
{
	horaEntrada = time(0);
}

UsuarioT::UsuarioT(string nNombre) : Usuario(nNombre)
{
	articulosVendidos = 0;
	dineroGenerado = 0;
	horaEntrada = time(0);
}


//Getters
int UsuarioT::getArticulosVendidos()
{
	return articulosVendidos;
}

double UsuarioT::getDineroGenerado()
{
	return dineroGenerado;
}

string UsuarioT::getEntrada()
{
	//TODO: to_string in c++11 for times 
	//		add zeros to time
	tm *ltm = localtime(&horaEntrada);
	string time = to_string(1 + ltm->tm_hour) + ":" + to_string(1 + ltm->tm_min) + ":" + to_string(1 + ltm->tm_sec);

	return time;
}

string UsuarioT::getSalida()
{	
	time_t horaSalida = time(0);
	tm *ltm = localtime(&horaSalida);
	string time = to_string(1 + ltm->tm_hour) + ":" + to_string(1 + ltm->tm_min) + ":" + to_string(1 + ltm->tm_sec);

	return time;
}

//Setters
void UsuarioT::addArticulosVendidos(int nArticulos)
{
	articulosVendidos += nArticulos;
}

void UsuarioT::addDineroGenerado(double nDineroGenerado)
{
	dineroGenerado += nDineroGenerado;
}

void UsuarioT::setArticulosVendidos(int nArticulos)
{
	articulosVendidos += nArticulos;
}

void UsuarioT::setDineroGenerado(double nDineroGenerado)
{
	dineroGenerado += nDineroGenerado;
}
