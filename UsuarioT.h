#include <ctime>

#include "Usuario.h"

#ifndef USUARIOT_H
#define USUARIOT_H

class UsuarioT : public Usuario
{
	private:
		int articulosVendidos;
		double dineroGenerado;
		time_t horaEntrada;

		//Hora entrada, hora salida

	public:
		//Constructor
		UsuarioT();
		UsuarioT(string);

		//Getter
		int getArticulosVendidos();
		double getDineroGenerado();
		string getEntrada();
		string getSalida();

		//Setter
		void setArticulosVendidos(int);
		void setDineroGenerado(double);
};

#endif
