#include "Consola.h"

#ifndef NINTENDO_H
#define NINTENDO_H

class Nintendo: public Consola
{
	public:
		Nintendo();
        Nintendo(int, int, char, string, double);


		virtual string getModelo();
};

#endif
