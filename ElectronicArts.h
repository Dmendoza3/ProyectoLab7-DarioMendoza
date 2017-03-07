#include "VideoJuego.h"

#ifndef EA_H
#define EA_H

class ElectronicArts : public VideoJuego
{
	public:
	ElectronicArts();
	ElectronicArts(string, int, string, int, string, char, string, double);

	string getSerie(); 
    string getConsola();	
};
#endif
