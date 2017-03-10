#include "Consola.h"
#include "VideoJuego.h"

#include <string>
#include <vector>
#include <ctime>

#ifndef VENTA_H
#define VENTA_H

class Venta
{
	private:
		string nombreCliente;
		vector<Consola*> listaConsolas;
		vector<VideoJuego*> listaJuegos;
		time_t horaVenta;
		string nombreVendedor;
		double subtotal;
		
	public:
		//Constructor
		Venta();
		Venta(string, string); //Nombre cliente, Nombre Vendedor

		//Getters
		string getNombreCliente();
		Consola* getConsola(int);
		VideoJuego* getJuego(int);
		string getHora();
		string getNombreVendedor();
		double getSubtotal();

		//Setters
		void setNombreCliente(string);
		void addConsola(Consola*);
		void addJuego(VideoJuego*);
		void setNombreVendedor(string);

};

#endif
