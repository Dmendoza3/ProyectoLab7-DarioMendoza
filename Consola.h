#include <string>

#ifndef CONSOLA_H
#define CONSOLA_H

class Consola
{
	protected:
		int year;
		int modelo; //Depende de la clase hija
		char estado; //'N' Nuevo; 'U' Usado
		string serie; //Depende e la clase hija
		double precio;

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
		
};

#endif
