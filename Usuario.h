#include <string>

#ifndef USUARIO_H
#define USUARIO_H

class Usuario
{
	prodtected:
		string nombre;

	public:
		//Constructor
		Usuario();
		Usuario(string);

		//Getter
		string getNombre();

		//Setter
		void setNombre(string);
};

#endif
