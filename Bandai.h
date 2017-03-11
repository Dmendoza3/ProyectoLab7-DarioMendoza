#include "VideoJuego.h"

#ifndef BANDAI_H
#define BANDAI_H

class Bandai : public VideoJuego
{
	//Serializacion
    friend class boost::serialization::access;

	public:
	Bandai(){}
    Bandai(string, int, string, int, string, char, string, double);

	string getSerie();
    string getConsola();
	
	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
        ar & boost::serialization::base_object<VideoJuego>(*this);
    }

};
#endif
