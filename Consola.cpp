#include "Consola.h"

//Constructor
Consola::Consola(){}

Consola(int nYear, int nModelo, char nEstado, string nSerie, double nPrecio)
{
	year = nYear;
	modelo = nModelo;
	estado = nEstado;
	serie = nSerie;
	precio = nPrecio;
}

//Getters
int Consola::getYear()
{
	return year;
}

string Consola::getModelo()
{
	return "";
}

char Consola::getEstado()
{
	return estado;
}

string Consola::getSerie()
{
	return serie;
}

double Consola::getPrecio()
{
	return precio;
}

//Setters
void Consola::setYear(int nYear)
{
	year = nYear;
}

void Consola::setModelo(int nModelo)
{
	modelo = nModelo;
}

void Consola::setEstado(char nEstado)
{
	estado = nEstado;
}

void Consola::setSerie(string nSerie)
{
	serie = nSerie;
}

void Consola::setPrecio(double nPrecio)
{
	precio = nPrecio;
}
