#include "VideoJuego.h"

#ifndef NINGAME_H
#define NINGAME_H

class NintendoJuego : public VideoJuego
{
	public:
	NintendoJuego();
    NintendoJuego(string, int, string, int, string, char, string, double);

	string getSerie();
	string getConsola();	
};
#endif
