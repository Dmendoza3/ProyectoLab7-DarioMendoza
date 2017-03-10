#include "Venta.h"

Venta::Venta()
{
	horaVenta = time(0);
	subtotal = 0;
}

Venta::Venta(string nCliente, string nVendedor)
{
	nombreCliente = nCliente;
	nombreVendedor = nVendedor;
	
	horaVenta = time(0);
	subtotal = 0;
}

//Getters
string Venta::getNombreCliente()
{
	return nombreCliente;
}

Consola* Venta::getConsola(int iConsola)
{
	return listaConsolas[iConsola];
}

VideoJuego* Venta::getJuego(int iJuego)
{
	return listaJuegos[iJuego];
}

string Venta::getHora()
{
	tm *ltm = localtime(&horaVenta);
    string time = to_string(1 + ltm->tm_hour) + ":" + to_string(1 + ltm->tm_min) + ":" + to_string(1 + ltm->tm_sec);

	return time;
}

string Venta::getFecha()
{
	tm *ltm = localtime(&horaVenta);
	string dt =  to_string(ltm->tm_mday) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(1900 + ltm->tm_year);

	return dt;
}

string Venta::getNombreVendedor()
{
	return nombreVendedor;
}

double Venta::getSubtotal()
{
	return subtotal;
}


//Setters
void Venta::setNombreCliente(string nCliente)
{
	nombreCliente = nCliente;
}

void Venta::addConsola(Consola* nConsola)
{
	listaConsolas.push_back(nConsola);
}

void Venta::addJuego(VideoJuego* nJuego)
{
	listaJuegos.push_back(nJuego);
}

void Venta::setNombreVendedor(string nVendedor)
{
	nombreVendedor = nVendedor;
}

void Venta::setSubTotal(double nSub)
{
	subtotal = nSub;
}
