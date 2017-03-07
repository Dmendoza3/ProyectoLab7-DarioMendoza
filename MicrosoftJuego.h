#include "VideoJuego.h"

#ifndef MICROGAME_H
#define MICROGAME_H

class MicrosoftJuego : public VideoJuego
{
	public:
	MicrosoftJuego();
    MicrosoftJuego(string, int, string, int, string, char, string, double);

	string getSerie(); 
    string getConsola();
};
#endif
