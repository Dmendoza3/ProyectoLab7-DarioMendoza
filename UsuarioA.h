#include "Usuario.h"


#ifndef USUARIOA_H
#define USUARIOA_H

class UsuarioA : public Usuario
{
	private:
		string pass;

	public:
		//Constructor
		UsuarioA();
		UsuarioA(string, string);

		//Getter
		string getPassword();

		//Setter
		void setPassword(string);
};

#endif
