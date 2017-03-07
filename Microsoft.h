#include "Consola.h"

#ifndef MICROSOFT_H
#define MICROSOFT_H

class Microsoft : public Consola
{
	public:
		virtual string getModelo();
        virtual string getSerie();

};

#endif
