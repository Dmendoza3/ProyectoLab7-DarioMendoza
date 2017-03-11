#include "VideoJuego.h"

#ifndef NINGAME_H
#define NINGAME_H

class NintendoJuego : public VideoJuego
{
	//Serializacion
    friend class boost::serialization::access;

	public:
		NintendoJuego(){}
   		NintendoJuego(string, int, string, int, string, char, string, double);

		string getSerie();
		string getConsola();	

	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
    	ar & boost::serialization::base_object<VideoJuego>(*this);
	}

};
#endif
