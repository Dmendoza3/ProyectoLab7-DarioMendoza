		#include "Usuario.h"


#ifndef USUARIOA_H
#define USUARIOA_H

class UsuarioT : public Usuario
{
	private:
		string pass;
		//Hora entrada, hora salida, dinero generado, articulos vendidos|

	public:
		//Constructor
		UsuarioT();
		UsuarioT(string, );

		//Getter
		string getPassword();

		//Setter
		void setPassword(string);
};

#endif
