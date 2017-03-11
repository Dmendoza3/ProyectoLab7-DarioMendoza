#include "VideoJuego.h"

#ifndef BANDAI_H
#define BANDAI_H

class Bandai : public VideoJuego
{
	public:
	Bandai();
    Bandai(string, int, string, int, string, char, string, double);

	string getSerie();
    string getConsola();
};
#endif
