#include "VideoJuego.h"

#ifndef MICROGAME_H
#define MICROGAME_H

class MicrosoftJuego : public VideoJuego
{
	//Serializacion
    friend class boost::serialization::access;	

	public:
		MicrosoftJuego(){}
    	MicrosoftJuego(string, int, string, int, string, char, string, double);

		string getSerie(); 
    	string getConsola();

	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
		ar & boost::serialization::base_object<VideoJuego>(*this);
    }
};
#endif
