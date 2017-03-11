#include "VideoJuego.h"

#ifndef SEGA_H
#define SEGA_H

class Sega : public VideoJuego
{
	//Serializacion
    friend class boost::serialization::access;

	public:
	Sega(){}
    Sega(string, int, string, int, string, char, string, double);

	string getSerie(); 
    string getConsola();

	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
	    ar & boost::serialization::base_object<VideoJuego>(*this);	
	}
	
};
#endif
