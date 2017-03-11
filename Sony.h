#include "Consola.h"

#ifndef SONY_H
#define SONY_H

class Sony : public Consola
{
	//Serializacion
    friend class boost::serialization::access;

	public:
		Sony();
        Sony(int, int, char, string, double);

		virtual string getModelo();

	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
        ar & boost::serialization::base_object<Consola>(*this);
    }
};

#endif
