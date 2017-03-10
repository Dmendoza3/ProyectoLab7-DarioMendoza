#include "Consola.h"

#ifndef SONY_H
#define SONY_H

class Sony : public Consola
{
	public:
		Sony();
        Sony(int, int, char, string, double);

		virtual string getModelo();
};

#endif
