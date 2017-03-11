#include "Consola.h"

#ifndef MICROSOFT_H
#define MICROSOFT_H

class Microsoft : public Consola
{
	//Serializacion
    friend class boost::serialization::access;
	
	public:
		Microsoft();
		Microsoft(int, int, char, string, double);

		virtual string getModelo();
    
	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
        ar & boost::serialization::base_object<Consola>(*this);
    }
};

#endif
