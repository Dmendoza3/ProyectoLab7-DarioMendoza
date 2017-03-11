#include "VideoJuego.h"

#ifndef SQUAREENIX_H
#define SQUAREENIX_H

class SquareEnix : public VideoJuego
{
	//Serializacion
    friend class boost::serialization::access;

	public:
	SquareEnix(){}
    SquareEnix(string, int, string, int, string, char, string, double);
	
	string getSerie(); 
    string getConsola();	

	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
		ar & boost::serialization::base_object<VideoJuego>(*this);
    }
};
#endif
