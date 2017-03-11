#include "VideoJuego.h"

#ifndef SEGA_H
#define SEGA_H

class Sega : public VideoJuego
{
	public:
	Sega();
    Sega(string, int, string, int, string, char, string, double);

	string getSerie(); 
    string getConsola();
};
#endif
