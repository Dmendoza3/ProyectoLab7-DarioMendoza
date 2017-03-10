#include <vector>

#include "Consola.h"
#include "VideoJuego.h"

using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

class DataBase
{
	public:
		vector<Consola*> consolas;
		vector<VideoJuego*> juegos;

		//Constructor
		DataBase();

		//Getters
		Consola* getConsola(int);
		VideoJuego* getJuegos(int);

		//Setters
		void addConsola(Consola*);
		void addJuego(VideoJuego*);

		//Destructor
		~DataBase();
};

#endif
