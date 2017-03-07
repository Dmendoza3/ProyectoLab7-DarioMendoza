#include "VideoJuego.h"

#ifndef UBISOFT_H
#define UBISOFT_H

class Ubisoft : public VideoJuego
{
	public:
	Ubisoft();
    Ubisoft(string, int, string, int, string, char, string, double);
	
	string getSerie(); 
    string getConsola();	
};
#endif
