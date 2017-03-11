#include "VideoJuego.h"

#ifndef KONAMI_H
#define KONAMI_H

class Konami : public VideoJuego
{
	//Serializacion
    friend class boost::serialization::access;

	public:
	Konami(){}
    Konami(string, int, string, int, string, char, string, double);

	string getSerie(); 
    string getConsola();

	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
		ar & boost::serialization::base_object<VideoJuego>(*this);
    }
	
};
#endif
