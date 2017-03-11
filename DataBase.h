#include <boost/serialization/vector.hpp>

#include "Consola.h"
#include "VideoJuego.h"
#include "Microsoft.h"
#include "Sony.h"
#include "Nintendo.h"
#include "MicrosoftJuego.h"
#include "SonyJuego.h"
#include "NintendoJuego.h"
#include "Bandai.h"
#include "ElectronicArts.h"
#include "Konami.h"
#include "Sega.h"
#include "SquareEnix.h"
#include "Ubisoft.h"


using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

class DataBase
{
	//Serializacion
    friend class boost::serialization::access;

	public:
		vector<Consola*> consolas;
		vector<VideoJuego*> juegos;

		//Constructor
		DataBase();

		//Getters
		Consola* getConsola(int);
		VideoJuego* getJuegos(int);

		//Setters
		void addConsola(Consola*);
		void addJuego(VideoJuego*);

		//Destructor
		~DataBase();

	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
		//Consolas
        ar.register_type(static_cast<Microsoft*>(NULL));
        ar.register_type(static_cast<Nintendo*>(NULL));
        ar.register_type(static_cast<Sony*>(NULL));	
        ar & consolas;

		//VideoJuegos
        ar.register_type(static_cast<MicrosoftJuego*>(NULL));
        ar.register_type(static_cast<NintendoJuego*>(NULL));
        ar.register_type(static_cast<SonyJuego*>(NULL));
        ar.register_type(static_cast<Bandai*>(NULL));
        ar.register_type(static_cast<Konami*>(NULL));
        ar.register_type(static_cast<ElectronicArts*>(NULL));
        ar.register_type(static_cast<Sega*>(NULL));
        ar.register_type(static_cast<SquareEnix*>(NULL));
        ar.register_type(static_cast<Ubisoft*>(NULL));

        ar & juegos;
    }
};

#endif
