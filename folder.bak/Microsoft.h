#include "Consola.h"

#ifndef MICROSOFT_H
#define MICROSOFT_H

class Microsoft : public Consola
{
	public:
		Microsoft();
		Microsoft(int, int, char, string, double);

		virtual string getModelo();
};

#endif
