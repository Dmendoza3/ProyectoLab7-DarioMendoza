#include "VideoJuego.h"

#ifndef SONYGAME_H
#define SONYGAME_H

class SonyJuego : public VideoJuego
{
	//Serializacion
    friend class boost::serialization::access;

	public:
	SonyJuego(){}
    SonyJuego(string, int, string, int, string, char, string, double);

	string getSerie(); 
    string getConsola();
	
	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
		ar & boost::serialization::base_object<VideoJuego>(*this);
    }

};
#endif
