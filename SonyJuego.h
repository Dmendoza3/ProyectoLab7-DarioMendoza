#include "VideoJuego.h"

#ifndef SONYGAME_H
#define SONYGAME_H

class SonyJuego : public VideoJuego
{
	public:
	SonyJuego();
    SonyJuego(string, int, string, int, string, char, string, double);

	string getSerie(); 
    string getConsola();
};
#endif
