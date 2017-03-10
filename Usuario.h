#include <string>

using namespace std;

#ifndef USUARIO_H
#define USUARIO_H

class Usuario
{
	protected:
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
