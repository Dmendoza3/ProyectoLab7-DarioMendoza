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
#include <algorithm>
#include <random>
#include <iostream>
#include <fstream>
#include <boost/archive/polymorphic_binary_iarchive.hpp>
#include <boost/archive/polymorphic_binary_oarchive.hpp>

/////////////////////////
void save(const DataBase &s, const char* filename)
{
    // make an archive
    std::ofstream ofs(filename, std::ios::binary);
    boost::archive::polymorphic_binary_oarchive oa(ofs);
    oa << s;
}

void restore(DataBase &s, const char* filename)
{
    // open the archive
    std::ifstream ifs(filename, std::ios::binary);
    boost::archive::polymorphic_binary_iarchive ia(ifs);

    // restore the schedule from the archive
    ia >> s;
}
/////////////////////

void agregarVideoJuego(DataBase* db)
{
	for(int i = 1; i < 5; i++){
		int op = 6;

		cout << "Ingrese la compañia del juego: \n"
		<<      "1. Microsoft\n"
		<<      "2. Sony\n"
		<<      "3. Nintendo\n"
		<<      "4. Bandai\n"
		<<      "5. Electronic Arts\n"
		<<      "6. Konami\n"
		<<      "7. Sega\n"
		<<      "8. SquareEnix\n"
		<<      "9. Ubisoft\n";

		//Pedir lo que se repite
		string nombre = "Battle Field " + to_string(i);
		int year = 2016;
		string consola;
		int jugadores;
		string genero;
		char estado;
		string serie;
		double precio;

		//Pedir consola
		int c;
		cout << "Ingrese el modelo de la consola:\n"
		<<      "1. Xbox\n"
		<<      "2. Xbox 360\n"
		<<      "3. Xbox One\n"
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

		consola = (string[23]){"Xbox", "Xbox 360", "Xbox One", "Playstation 1", "Playstation 2", "Playstation 3", "Playstation 4", "PSP", "PS Vita", "Nintendo Entertainment System", "Super Nintendo Entertainment System", "Nintendo 64", "Nintendo Gamecube", "Nintento Wii", "Nintento Wii U", "Nintendo Switch", "Gameboy", "Gameboy Colors", "Gameboy Advance", "Nintendo DS", "Nintendo DSi", "Nintendo 3DS", "Nintendo New 3DS"}[2-1];


		jugadores = 2;
		estado = 'U';

		genero = "Accion";
		
		serie = "15" + to_string(i) + "99";
		precio = 700;

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

}

int main()
{
	DataBase db;
    restore(db, "DataBase.bin");

	auto engine = std::default_random_engine{};
	std::shuffle(std::begin(db.juegos), std::end(db.juegos), engine);
//	agregarVideoJuego(&db);

	save(db, "DataBase.bin");
	return 0;
}
