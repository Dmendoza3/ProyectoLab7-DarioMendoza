#include "VideoJuego.h"

#ifndef UBISOFT_H
#define UBISOFT_H

class Ubisoft : public VideoJuego
{
	//Serializacion
    friend class boost::serialization::access;

	public:
	Ubisoft(){}
    Ubisoft(string, int, string, int, string, char, string, double);
	
	string getSerie(); 
    string getConsola();	

	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
		ar & boost::serialization::base_object<VideoJuego>(*this);
    }
};
#endif
