#include "DataBase.h"

//Constructor
DataBase::DataBase(){}

//Getters
Consola* DataBase::getConsola(int iConsola)
{
	return consolas[iConsola];
}

VideoJuego* DataBase::getJuegos(int iJuego)
{
	return juegos[iJuego];
}

//Setters
void DataBase::addConsola(Consola* c)
{
	consolas.push_back(c);
}

void DataBase::addJuego(VideoJuego* v)
{
	juegos.push_back(v);
}

//Destructor
DataBase::~DataBase()
{
	for(int i = 0; i < consolas.size(); i++)
		delete consolas[i];

	for(int i = 0; i < juegos.size(); i++)
		delete juegos[i];

	consolas.clear();
	juegos.clear();
}
