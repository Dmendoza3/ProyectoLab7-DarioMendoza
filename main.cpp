//Padres
#include "Consola.h"
#include "VideoJuego.h"

//Hijas de Consola
#include "Microsoft.h"
#include "Sony.h"
#include "Nintendo.h"

//Hijas de VideoJuego
#include "MicrosoftJuego.h"
#include "SonyJuego.h"
#include "NintendoJuego.h"
#include "Bandai.h"
#include "ElectronicArts.h"
#include "Konami.h"
#include "Sega.h"
#include "SquareEnix.h"
#include "Ubisoft.h"

//Padre
#include "Usuario.h"

//Hija de Usuario
#include "UsuarioA.h"
#include "UsuarioT.h"

//
#include "Venta.h"

//
#include "DataBase.h"

//
#include <iostream>
#include <fstream>
#include <exception>
#include <regex>

void sesionAdmin(DataBase*, UsuarioA*);
void sesionTemporal(DataBase*, UsuarioT*);

int main()
{
	DataBase db;
	UsuarioA admin("admin", "password");
	UsuarioT temp("temp");

	bool sesion = true;

	//TODO:Cargar base de datos
	//FileAdmin.cargar(db);

	//TODO:Inicio de sesion administrador o temporal


	int op = 1;

	while(sesion)
	{
		cout << "1. Iniciar como administrador\n"
		<<		"2. Iniciar como vendedor\n"
		<<		"0. Salir\n"
		<<		"->";

		cin >> op;

		switch(op)
		{
			case 1:{
				string user, pass;
				cout << "Ingrese el nombre de usuario: ";
				cin >> user;
				
				cout << "Ingrese la contraseña: ";
				cin >> pass;

				if(user == admin.getNombre() && pass == admin.getPassword())
					sesionAdmin(&db, &admin);
				else
					cout << "Error: Usuario o Contrasena erronea.\n";
				break;}

			case 2:{
				string name;
				cout << "Ingrese su nombre: ";
				cin >> name;

				temp.setNombre(name);
				temp.setArticulosVendidos(0);
				temp.setDineroGenerado(0);

				sesionTemporal(&db, &temp);
			break;}
			
			case 0:{
				sesion = false;
			break;}
		}

		//TODO:Guardar en base de datos
	}
	//string consolas[] = {"",""};

	return 0;
}


//Pedir
void pedirModelo(int* mo, int max)
{
	int op;	

	do{
		cout << "->";
		cin >> op;
	}while(op < 1 || op > max);

	*mo = op;
}

void pedirYear(int* ye)
{
	cout << "Ingrese año:";
	do{
		cin >> (*ye);
	}while((*ye) < 1950);
}

void pedirEstado(char* st)
{
	cout << "Ingrese estado del juego\n";

	do{
		cout <<	"*[N]uevo\n"
		<<		"*[U]sado\n"
		<<		"->";

		cin >> (*st);
	}while(*st != 'U' && *st != 'N');
}

void pedirSerie(string* se, DataBase* db, bool isConsola)
{
	bool found = true;

	regex reg("[1-9]+");

	while(found){
		cout << "Ingrese la serie:\n";
		do{
			cout << "[Cinco digitos]\n->";
			cin >> (*se);
		}while((*se).size() != 5 || !(regex_match(*se, reg))); //Si no son 5 digitos y no son numeros

		found = false;

		if(isConsola)
		{
			//Revisar si no hay serie en lista de Consola
			for(Consola* con : db->consolas)
				if((*se) == (*con).getSerie())
				{
					found = true;
					cout << "Error: Serie ya existe.\n";
					break;
				}
				else
					found = false;
		}
		else
		{
			//Revisar si no hay serie en lista de Juegos
			for(VideoJuego* gam : db->juegos)
				if((*se) == (*gam).getSerie())
				{
					found = true;
					cout << "Error: Serie ya existe.\n";
					break;
				}
				else
					found = false;
		}
	}
}

void pedirPrecio(double* pri)
{
	cout << "Ingrese el precio del producto: ";
	do{
		cin >> (*pri);
	}while(*pri < 0);
}

void agregarConsola(DataBase* db)
{
	int op = 0;

	cout << "Ingrese la compañia: \n"
	<<		"1. Microsoft\n"
	<<		"2. Sony\n"
	<<		"3. Nintendo\n";
	
	do{
		cout << "->";
		cin >> op;
	}while(op < 1 || op > 3);

	
	int nConsolas;
	cout << "Ingrese el numero de consolas a agregar: ";
	cin >> nConsolas;

	int year;
	int modelo;
	char estado;
	string serie;
	double precio;
	
	//Pedir año
	pedirYear(&year);

	//Pedir estado
	pedirEstado(&estado);

	//Pedir precio
	pedirPrecio(&precio);

	switch(op)
	{
		case 1:{//Microsoft
			//Pedir modelo
			cout << "Ingrese el modelo de la consola\n"
			<<		"1. Xbox\n"
			<<		"2. Xbox 360\n"
			<<		"3. Xbox One\n";
			
			pedirModelo(&modelo, 3);
			break;
		}

		case 2:{//Sony
			//Pedir modelo
			cout << "Ingrese el modelo de la consola:\n"
			<<		"1. Playstation 1\n"
        	<<		"2. Playstation 2\n"
        	<<		"3. Playstation 3\n"
        	<<		"4. Playstation 4\n"
        	<<		"5. PSP\n"
        	<<		"6. PS Vita\n";

			pedirModelo(&modelo, 6);
			break;
		}

		case 3:{//Nintendo
			//Pedir modelo
			cout << "Ingrese el modelo de la consola:\n"
			<<		"1. Nintendo Entertainment System\n"
			<<		"2. Super Nintendo Entertainment System\n"
			<<		"3. Nintendo 64\n"
			<<		"4. Nintendo Gamecube\n"
			<<		"5. Nintento Wii\n"
			<<		"6. Nintento Wii U\n"
			<<		"7. Nintendo Switch\n"
			<<		"8. Gameboy\n"
			<<		"9. Gameboy Colors\n"
			<<		"10. Gameboy Advance\n"
			<<		"11. Nintendo DS\n"
			<<		"12. Nintendo DSi\n"
			<<		"13. Nintendo 3DS\n"
			<<		"14. Nintendo New 3DS\n";

			pedirModelo(&modelo, 14);
			break;
		}
	}

	for(int i = 0; i < nConsolas; i++)
	{
		cout << "Consola [" << (i + 1) << "/"<< nConsolas <<"]\n";
		//Pedir serie
		pedirSerie(&serie, db, true);

		switch(op)
		{
			case 1:{
				db->addConsola(new Microsoft(year, modelo, estado, serie, precio));
				break;
			}
			case 2:{
				db->addConsola(new Sony(year, modelo, estado, serie, precio));
				break;
			}
			case 3:{
				db->addConsola(new Nintendo(year, modelo, estado, serie, precio));
				break;
			}
		}
	}
}

void agregarVideoJuego(DataBase* db)
{
	int op = 0;

	cout << "Ingrese la compañia del juego: \n"
	<< 		"1. Microsoft\n"
	<<		"2. Sony\n"
	<<		"3. Nintendo\n"
	<<		"4. Bandai\n"
	<<		"5. Electronic Arts\n"
	<<		"6. Konami\n"
	<<		"7. Sega\n"
	<<		"8. SquareEnix\n"
	<<		"9. Ubisoft\n";
	
	do{
		cout << "->";
		cin >> op;
	}while(op < 1 || op > 9);
	
	//Pedir lo que se repite
	string nombre;
	int year;
	string consola;
	int jugadores;
	string genero;
	char estado;
	string serie;
	double precio;
	
	//Pedir Nombre
	cout << "Ingrese el nombre del juego: ";
	cin.ignore();
	getline(cin, nombre);

	//Pedir año
	pedirYear(&year);

	//Pedir consola
	int c;
	cout << "Ingrese el modelo de la consola:\n"
	<<		"1. Xbox\n"
	<<		"2. Xbox 360\n"
	<<		"3. Xbox One\n"
	<<      "4. Playstation 1\n"
	<<      "5. Playstation 2\n"
	<<      "6. Playstation 3\n"
	<<      "7. Playstation 4\n"
	<<      "8. PSP\n"
	<<      "9. PS Vita\n"
	<<      "10. Nintendo Entertainment System\n"
	<<      "11. Super Nintendo Entertainment System\n"
	<<      "12. Nintendo 64\n"
	<<      "13. Nintendo Gamecube\n"
	<<      "14. Nintento Wii\n"
	<<      "15. Nintento Wii U\n"
	<<      "16. Nintendo Switch\n"
	<<      "17. Gameboy\n"
	<<      "18. Gameboy Colors\n"
	<<      "19. Gameboy Advance\n"
	<<      "20. Nintendo DS\n"
	<<      "21. Nintendo DSi\n"
	<<      "22. Nintendo 3DS\n"
	<<      "23. Nintendo New 3DS\n";

	pedirModelo(&c, 23);

	consola = (string[23]){"Xbox", "Xbox 360", "Xbox One", "Playstation 1", "Playstation 2", "Playstation 3", "Playstation 4", "PSP", "PS Vita", "Nintendo Entertainment System", "Super Nintendo Entertainment System", "Nintendo 64", "Nintendo Gamecube", "Nintento Wii", "Nintento Wii U", "Nintendo Switch", "Gameboy", "Gameboy Colors", "Gameboy Advance", "Nintendo DS", "Nintendo DSi", "Nintendo 3DS", "Nintendo New 3DS"}[c - 1];


	//Pedir jugadores
	cout << "Ingrese el numero de jugadores [1-8]: ";
	pedirModelo(&jugadores, 8);

	//Pedir genero
	cout << "Ingrese el genero del juego: ";
	cin >> genero;
	
	//Pedir estado
	pedirEstado(&estado);

	//Pedir serie
	pedirSerie(&serie, db, false);

	//Pedir precio
	pedirPrecio(&precio);


	switch(op)
	{
		case 1:{
			db->addJuego(new MicrosoftJuego(nombre, year, consola, jugadores, genero, estado, serie, precio));
		break;}
		
		case 2:{
			db->addJuego(new SonyJuego(nombre, year, consola, jugadores, genero, estado, serie, precio));
		break;}

		case 3:{
			db->addJuego(new NintendoJuego(nombre, year, consola, jugadores, genero, estado, serie, precio));
		break;}

		case 4:{
			db->addJuego(new Bandai(nombre, year, consola, jugadores, genero, estado, serie, precio));
		break;}

		case 5:{
			db->addJuego(new ElectronicArts(nombre, year, consola, jugadores, genero, estado, serie, precio));
		break;}

		case 6:{
			db->addJuego(new Konami(nombre, year, consola, jugadores, genero, estado, serie, precio));
		break;}

		case 7:{
			db->addJuego(new Sega(nombre, year, consola, jugadores, genero, estado, serie, precio));
		break;}

		case 8:{
			db->addJuego(new SquareEnix(nombre, year, consola, jugadores, genero, estado, serie, precio));
		break;}

		case 9:{
			db->addJuego(new Ubisoft(nombre, year, consola, jugadores, genero, estado, serie, precio));
		break;}
	}

}

void contarConsolas(DataBase* db, int* microsoft, int* nintendo, int* sony)
{
	for(Consola* con : db->consolas)
	{	
		if(typeid(*con) == typeid(Microsoft))
			(*microsoft)++;
		if(typeid(*con) == typeid(Nintendo))
			(*nintendo)++;
		if(typeid(*con) == typeid(Sony))
			(*sony)++;
	}
}

void contarJuegos(DataBase* db, int* juegos)
{
	for(VideoJuego* con : db->juegos)
	{	
		if(typeid(*con) == typeid(MicrosoftJuego))
			juegos[0]++;
		if(typeid(*con) == typeid(SonyJuego))
			juegos[1]++;
		if(typeid(*con) == typeid(NintendoJuego))
			juegos[2]++;
		if(typeid(*con) == typeid(Bandai))
			juegos[3]++;
		if(typeid(*con) == typeid(ElectronicArts))
			juegos[4]++;
		if(typeid(*con) == typeid(Konami))
			juegos[5]++;
		if(typeid(*con) == typeid(Sega))
			juegos[6]++;
		if(typeid(*con) == typeid(SquareEnix))
			juegos[7]++;
		if(typeid(*con) == typeid(Ubisoft))
			juegos[8]++;
	}
}

void imprimirConsolas(DataBase* db)
{
	int micro = 0, nin = 0, sony = 0;
	contarConsolas(db, &micro, &nin, &sony);

	cout << "Consolas Microsoft: " << micro << endl
	<<		 "Consolas Sony: " << sony << endl
	<<		 "Consolas Nintendo: " << nin << endl;

	cout << "|In|\t|Serie|\t|Modelo|\t|Año|\t|Precio|\n";	

	int i = 0;
	for(Consola* con : db->consolas)
	{
		cout << i << ")\t|" << con->getSerie() << "|\t|" << con->getModelo() 
		<< "|\t|" << con->getYear() << "|\t|" << con->getPrecio() << "|\n";

		i++;
	}
}

void imprimirVideoJuegos(DataBase* db)
{
	int juegos[9];
	contarJuegos(db, juegos);

	cout << "Juegos de Microsoft: " << juegos[0] << endl
	<<		"Juegos de Sony: " << juegos[1] << endl
	<<		"Juegos de Nintendo: " << juegos[2] << endl
	<<		"Juegos de Bandai: " << juegos[3] << endl
	<<		"Juegos de Electronic Arts: " << juegos[4] << endl
	<<		"Juegos de Konami: " << juegos[5] << endl
	<<		"Juegos de Sega: " << juegos[6] << endl
	<<		"Juegos de Square Enix: " << juegos[7] << endl
	<<		"Juegos de Ubisoft: " << juegos[8] << endl;


	cout << "|In|\t|Serie|\t|Nombre|\t|Consola|\t|Jugadores|\t|Genero|\t|Año|\t|Precio|\n";	

	int i = 0;
	for(VideoJuego* con : db->juegos)
	{
		cout << i << ")\t|" << con->getSerie() << "|\t|" << con->getNombre() << "|\t|" 
		<< con->getConsola() << "|\t|" << con->getJugadores() << "|\t|" << con->getGenero() 
		<< "|\t|" << con->getYear() << "|\t|" << con->getPrecio() << "|\n";

		i++;
	}
}

void modificarConsola(DataBase* db)
{	
	//Salir si no hay consolas
	if(db->consolas.size() <= 0)
	{
		cout << "No hay consolas.\n";
		return;
	}

	imprimirConsolas(db);

	int index;
	cout << "Ingrese el indice de la consola a modificar: ";
	cin >> index;

	if(index < 0 || index > db->consolas.size() - 1)
		cout << "No se ha modificado nada.\n";
	else
	{
		//Comenzar modificacion
		Consola* con = db->consolas[index];
		
		int year;
		int modelo;
		char estado;
		double precio;

		//Pedir año
		pedirYear(&year);

		//Pedir estado
		pedirEstado(&estado);

		//Pedir precio
		pedirPrecio(&precio);

		int op = 0;
		if(typeid(*con) == typeid(Microsoft))
			op = 1;
		if(typeid(*con) == typeid(Sony))
			op = 2;
		if(typeid(*con) == typeid(Nintendo))
			op = 3;

		switch(op)
		{
			case 1:{//Microsoft
				//Pedir modelo
				cout << "Ingrese el modelo de la consola\n"
				<<		"1. Xbox\n"
				<<		"2. Xbox 360\n"
				<<		"3. Xbox One\n";
				
				pedirModelo(&modelo, 3);
				break;
			}

			case 2:{//Sony
				//Pedir modelo
				cout << "Ingrese el modelo de la consola:\n"
				<<		"1. Playstation 1\n"
				<<		"2. Playstation 2\n"
				<<		"3. Playstation 3\n"
				<<		"4. Playstation 4\n"
				<<		"5. PSP\n"
				<<		"6. PS Vita\n";

				pedirModelo(&modelo, 6);
				break;
			}

			case 3:{//Nintendo
				//Pedir modelo
				cout << "Ingrese el modelo de la consola:\n"
				<<		"1. Nintendo Entertainment System\n"
				<<		"2. Super Nintendo Entertainment System\n"
				<<		"3. Nintendo 64\n"
				<<		"4. Nintendo Gamecube\n"
				<<		"5. Nintento Wii\n"
				<<		"6. Nintento Wii U\n"
				<<		"7. Nintendo Switch\n"
				<<		"8. Gameboy\n"
				<<		"9. Gameboy Colors\n"
				<<		"10. Gameboy Advance\n"
				<<		"11. Nintendo DS\n"
				<<		"12. Nintendo DSi\n"
				<<		"13. Nintendo 3DS\n"
				<<		"14. Nintendo New 3DS\n";

				pedirModelo(&modelo, 14);
				break;
			}
		}

		//Modificando
		con->setYear(year);
		con->setModelo(modelo);
		con->setEstado(estado);
		con->setPrecio(precio);
		
		cout << "Consola modificada.\n";
	}
}

void modificarVideoJuego(DataBase* db)
{
	//Salir si no hay juegos
	if(db->juegos.size() <= 0)
	{
		cout << "No hay juegos.\n";
		return;
	}

	imprimirVideoJuegos(db);

	int index;
	cout << "Ingrese el indice del juego a modificar: ";
	cin >> index;

	if(index < 0 || index > db->juegos.size() - 1)
		cout << "No se ha modificado nada.\n";
	else
	{
		//Comenzar modificacion
		VideoJuego* gam = db->juegos[index];
	
		//Pedir lo que se repite
		string nombre;
		int year;
		string consola;
		int jugadores;
		string genero;
		char estado;
		double precio;
		
		//Pedir Nombre
		cout << "Ingrese el nombre del juego: ";
		cin.ignore();
		getline(cin, nombre);

		//Pedir año
		pedirYear(&year);

		//Pedir consola
		int c;
		cout << "Ingrese el modelo de la consola\n"
		<<		"1. Xbox\n"
		<<		"2. Xbox 360\n"
		<<		"3. Xbox One\n"
		<<      "4. Playstation 1\n"
		<<      "5. Playstation 2\n"
		<<      "6. Playstation 3\n"
		<<      "7. Playstation 4\n"
		<<      "8. PSP\n"
		<<      "9. PS Vita\n"
		<<      "10. Nintendo Entertainment System\n"
		<<      "11. Super Nintendo Entertainment System\n"
		<<      "12. Nintendo 64\n"
		<<      "13. Nintendo Gamecube\n"
		<<      "14. Nintento Wii\n"
		<<      "15. Nintento Wii U\n"
		<<      "16. Nintendo Switch\n"
		<<      "17. Gameboy\n"
		<<      "18. Gameboy Colors\n"
		<<      "19. Gameboy Advance\n"
		<<      "20. Nintendo DS\n"
		<<      "21. Nintendo DSi\n"
		<<      "22. Nintendo 3DS\n"
		<<      "23. Nintendo New 3DS\n";

		pedirModelo(&c, 23);

		consola = (string[23]){"Xbox", "Xbox 360", "Xbox One", "Playstation 1", "Playstation 2", "Playstation 3", "Playstation 4", "PSP", "PS Vita", "Nintendo Entertainment System", "Super Nintendo Entertainment System", "Nintendo 64", "Nintendo Gamecube", "Nintento Wii", "Nintento Wii U", "Nintendo Switch", "Gameboy", "Gameboy Colors", "Gameboy Advance", "Nintendo DS", "Nintendo DSi", "Nintendo 3DS", "Nintendo New 3DS"}[c - 1];


		//Pedir jugadores
		cout << "Ingrese el numero de jugadores:[1-8]";
		pedirModelo(&jugadores, 8);

		//Pedir genero
		cout << "Ingrese el genero del juego: ";
		cin >> genero;
		
		//Pedir estado
		pedirEstado(&estado);

		//Pedir precio
		pedirPrecio(&precio);
		cout << "Juego modificado.\n";

		//Modificar
		gam->setNombre(nombre);
		gam->setYear(year);
		gam->setConsola(consola);
		gam->setJugadores(jugadores);
		gam->setGenero(genero);
		gam->setEstado(estado);
		gam->setPrecio(precio);
	}
}


void eliminarConsola(DataBase* db)
{
	//Salir si no hay consolas
	if(db->consolas.size() <= 0)
	{
		cout << "No hay consolas.\n";
		return;
	}

	imprimirConsolas(db);
		
	int index;
	cout << "Ingrese el indice de la consola a eliminar: ";
	cin >> index;

	if(index < 0 || index > db->consolas.size() - 1)
		cout << "No se ha eliminado nada.\n";
	else
	{
		db->consolas.erase(db->consolas.begin() + index);
		cout << "Consola eliminada.\n";
	}
}

void eliminarVideoJuego(DataBase* db)
{
	//Salir si no hay juegos
	if(db->juegos.size() <= 0)
	{
		cout << "No hay juegos.\n";
		return;
	}

	imprimirVideoJuegos(db);
	
	int index;
	cout << "Ingrese el indice del juego a eliminar: ";
	cin >> index;

	if(index < 0 || index > db->juegos.size() - 1)
		cout << "No se ha eliminado nada.\n";
	else
	{
		db->juegos.erase(db->juegos.begin() + index);
		cout << "Juego eliminado.\n";
	}
}

void sesionAdmin(DataBase* db, UsuarioA* admin)
{
	int op = 1;

	while(op != 0)
	{	
		cout << "Ingrese el numero de la opcion:\n" 
		<< 		"1. Agregar consola.\n"
		<<		"2. Agregar video juego.\n"
		<<		"3. Modificar consola.\n"
		<<		"4. Modificar videojuego.\n"
		<<		"5. Eliminar consola.\n"
		<<		"6. Eliminar video juego.\n"
		<<		"0. Cerrar sesion.\n"
		<<		"->";
		
		cin >> op;

		switch(op)
		{
			case 1:{
				agregarConsola(db);
				break;
			}
			case 2:{
				agregarVideoJuego(db);
				break;
			}

			case 3:{
				modificarConsola(db);
				break;
			}

			case 4:{
				modificarVideoJuego(db);
				break;
			}

			case 5:{
				eliminarConsola(db);
				break;
			}

			case 6:{
				eliminarVideoJuego(db);
				break;
			}
		}
	}
}

void venderConsola(DataBase* db, Venta* sale)
{
	//Salir si no hay consolas
	if(db->consolas.size() <= 0)
	{
		cout << "No hay consolas.\n";
		return;
	}

	imprimirConsolas(db);
		
	int index;
	cout << "Ingrese el indice de la consola que desea vender: ";
	cin >> index;

	if(index < 0 || index > db->consolas.size() - 1)
		cout << "No se ha realizado la venta.\n";
	else
	{
		sale->addConsola(db->consolas[index]);
		db->consolas.erase(db->consolas.begin() + index);
		cout << "Consola vendida.\n";
	}
}

void venderJuego(DataBase* db, Venta* sale)
{
	//Salir si no hay juegos
	if(db->juegos.size() <= 0)
	{
		cout << "No hay juegos.\n";
		return;
	}

	imprimirVideoJuegos(db);
	
	int index;
	cout << "Ingrese el indice del juego a eliminar: ";
	cin >> index;

	if(index < 0 || index > db->juegos.size() - 1)
		cout << "No se ha eliminado nada.\n";
	else
	{
		sale->addJuego(db->juegos[index]);
		db->juegos.erase(db->juegos.begin() + index);
		cout << "Juego eliminado.\n";
	}
}

void vender(DataBase* db, UsuarioT* temp)
{
	//Revisar si hay algo en inventario
	if(db->consolas.size() <= 0 && db->juegos.size() <= 0)
	{
		cout << "No hay nada en inventario.\nNo se puede realizar una compra.\n";
		return;
	}
	
	string nombreCliente;
	string nombreVendedor = temp->getNombre();

	cout << "Ingrese el nombre del cliente: ";
	cin >> nombreCliente;
	
	//Iniciar venta
	Venta venta(nombreCliente, nombreVendedor);

	int op = 1;
	while(op != 0)
	{
		cout << "Ingrese el numero de la opcion: \n"
		<<		"1. Vender consola\n"
		<<		"2. Vender juego\n"
		<<		"0. Cerrar compra\n"
		<<		"->";
		cin >> op;
		
		switch(op)
		{
			case 1:{
				venderConsola(db, &venta);
				break;
			}
			
			case 2:{
				venderJuego(db, &venta);
				break;
			}
		}
	}

	//Cerrar venta
	int subtotal = 0;
	for(Consola* con : venta.listaConsolas)
		subtotal += con->getPrecio();

	for(VideoJuego* vid : venta.listaJuegos)
		subtotal += vid->getPrecio();

	venta.setSubTotal(subtotal);

	string path = "./log_venta/" + venta.getFecha() + "_" + venta.getHora() + ".log";

	ofstream nlog(path.c_str());
	
	nlog << "\t\tGAMEHUB\n"
	<<		"Fecha:\t" << venta.getFecha() << endl
	<<		"Hora:\t" << venta.getHora() << endl
	<<		"Vendedor:\t" << venta.getNombreVendedor() << endl
	<<		"\nCantidad articulos " << (venta.listaConsolas.size() + venta.listaJuegos.size()) << endl << endl;

	for(Consola* con : venta.listaConsolas)
		nlog << con->getModelo() << "\t" << con->getPrecio() << endl;

	for(VideoJuego* vid : venta.listaJuegos)
		nlog << vid->getNombre() << "\t" << vid->getPrecio() << endl;

	nlog << "Subtotal: L." << venta.getSubtotal() << endl;
	nlog << "Impuesto: L." << ((double)(venta.getSubtotal()) * 0.15) << endl;
	nlog << "Total: L." << ((double)(venta.getSubtotal()) * 1.15) << endl;

	nlog.close();
	cout << "Log guardado.\n";

	//Guardar en usuario
	temp->addArticulosVendidos(venta.listaConsolas.size() + venta.listaJuegos.size());
	temp->addDineroGenerado(((double)(venta.getSubtotal()) * 1.15));
}

void cerrarSesion(UsuarioT* temp)
{
	string path = "./usuarios_log/" + temp->getNombre() + "-" + temp->getSalida() + ".log";

	ofstream nlog(path.c_str());
	
	nlog << "\t\tGAMEHUB\n"
	<<		"Nombre: " << temp->getNombre() << endl
	<<		"Hora Entrada: " << temp->getEntrada() << endl
	<<		"Hora Salida: " << temp->getSalida() << endl << endl
	<<		"Cantidad de articulos vendidos: " << temp->getArticulosVendidos() << endl
	<<		"Dinero generado: " << temp->getDineroGenerado();

	nlog.close();
}

void sesionTemporal(DataBase* db, UsuarioT* temp)
{

	int op = 1;

	while(op != 0)
	{	
		cout << "Ingrese el numero de la opcion:\n" 
		<< 		"1. Agregar consola.\n"
		<<		"2. Agregar video juego.\n"
		<<		"3. Vender.\n"
		<<		"0. Cerrar sesion.\n"
		<<		"->";
		
		cin >> op;

		switch(op)
		{
			case 1:{
				agregarConsola(db);
				break;
			}
			case 2:{
				agregarVideoJuego(db);
				break;
			}

			case 3:{
				vender(db, temp);
				break;
			}

			case 0:{
				cerrarSesion(temp);
				break;
			}
		}
	}
}
