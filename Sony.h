#include "Consola.h"

#ifndef SONY_H
#define SONY_H

class Sony : public Consola
{
	public:
		virtual string getModelo();
        virtual string getSerie();

};

#endif
