#include "Consola.h"

#ifndef NINTENDO_H
#define NINTENDO_H

class Nintendo: public Consola
{
	//Serializacion
    friend class boost::serialization::access;	

	public:
		Nintendo();
        Nintendo(int, int, char, string, double);


		virtual string getModelo();

	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
        ar & boost::serialization::base_object<Consola>(*this);
    }
};

#endif
