#include <string>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/assume_abstract.hpp>

using namespace std;

#ifndef CONSOLA_H
#define CONSOLA_H

class Consola
{
	//Serializacion
	friend class boost::serialization::access;

	protected:
		int year;
		int modelo; //Depende de la clase hija
		char estado; //'N' Nuevo; 'U' Usado
		string serie; //Depende e la clase hija
		double precio;

	//Serializacion para atributos
	template<class Archive>
	void serialize(Archive & ar, const unsigned int /* file_version */){
		ar & year & modelo & estado & serie & precio;
	}
	

	public:
		//Constructor
		Consola();
		Consola(int, int, char, string, double);
		
		//Getters
		int getYear();
		virtual string getModelo();
		char getEstado();
		virtual string getSerie();
		double getPrecio();
		
		//Setters
		void setYear(int);
		void setModelo(int);
		void setEstado(char);
		void setSerie(string);
		void setPrecio(double);
		
		//Destructor
		virtual ~Consola();	
};

#endif
