#include "VideoJuego.h"

#ifndef SQUAREENIX_H
#define SQUAREENIX_H

class SquareEnix : public VideoJuego
{
	public:
	SquareEnix();
    SquareEnix(string, int, string, int, string, char, string, double);
	
	string getSerie(); 
    string getConsola();	
};
#endif
