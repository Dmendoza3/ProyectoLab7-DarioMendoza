#include <string>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/assume_abstract.hpp>

using namespace std;

#ifndef JUEGO_H
#define JUEGO_H

class VideoJuego
{
	//Serializacion
    friend class boost::serialization::access;

	protected:
		string nombre;
		int year;
		string consola;
		int jugadores;
		string genero;
		char estado; //'N' nuevo 'U' usado
		string serie;
		double precio;

	//Serializacion para atributos
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* file_version */){
		ar & nombre & year & consola & jugadores & genero & estado & serie & precio;
    }



	public:
		//Constructor
		VideoJuego();
		VideoJuego(string, int, string, int, string, char, string, double);

		//Getters	
		string getNombre();
		int getYear();
		string getConsola();
		int getJugadores();
		string getGenero();
		char getEstado();
		virtual string getSerie();
		string getserie(){return serie;}
		double getPrecio();

		//Setters
		void setNombre(string);
		void setYear(int);
		virtual void setConsola(string);
		void setJugadores(int);
		void setGenero(string);
		void setEstado(char);
		virtual void setSerie(string);
		void setPrecio(double);
		
		//Destructor
		virtual ~VideoJuego();
};

#endif
