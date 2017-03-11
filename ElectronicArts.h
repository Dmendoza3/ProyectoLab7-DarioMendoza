#include "VideoJuego.h"

#ifndef EA_H
#define EA_H

class ElectronicArts : public VideoJuego
{
	//Serializacion
    friend class boost::serialization::access;		

	public:
	ElectronicArts(){}
	ElectronicArts(string, int, string, int, string, char, string, double);

	string getSerie(); 
    string getConsola();	

	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
		ar & boost::serialization::base_object<VideoJuego>(*this);
    }

};
#endif
