#include "VideoJuego.h"

#ifndef KONAMI_H
#define KONAMI_H

class Konami : public VideoJuego
{
	public:
	Konami();
    Konami(string, int, string, int, string, char, string, double);

	string getSerie(); 
    string getConsola();
};
#endif
