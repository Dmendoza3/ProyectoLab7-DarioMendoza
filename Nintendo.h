#include "Consola.h"

#ifndef NINTENDO_H
#define NINTENDO_H

class Nintendo: public Consola
{
	public:
		virtual string getModelo();
        virtual string getSerie();

};

#endif
