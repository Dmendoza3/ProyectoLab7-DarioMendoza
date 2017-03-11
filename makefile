main:	UsuarioA.o UsuarioT.o NintendoJuego.o SonyJuego.o MicrosoftJuego.o Bandai.o ElectronicArts.o Konami.o Sega.o SquareEnix.o Ubisoft.o Sony.o Nintendo.o Microsoft.o Usuario.o Consola.o VideoJuego.o DataBase.o Venta.o main.o
	g++ UsuarioA.o UsuarioT.o NintendoJuego.o SonyJuego.o MicrosoftJuego.o Bandai.o ElectronicArts.o Konami.o Sega.o SquareEnix.o Ubisoft.o Sony.o Nintendo.o Microsoft.o Usuario.o Consola.o VideoJuego.o DataBase.o Venta.o main.o -o main -std=c++11 -lboost_serialization

main.o:	UsuarioA.h UsuarioT.h NintendoJuego.h SonyJuego.h MicrosoftJuego.h Bandai.h ElectronicArts.h Konami.h Sega.h SquareEnix.h Ubisoft.h Sony.h Nintendo.h Microsoft.h Usuario.h Consola.h VideoJuego.h DataBase.h Venta.h main.cpp
	g++ UsuarioA.h UsuarioT.h NintendoJuego.h SonyJuego.h MicrosoftJuego.h Bandai.h ElectronicArts.h Konami.h Sega.h SquareEnix.h Ubisoft.h Sony.h Nintendo.h Microsoft.h Usuario.h Consola.h VideoJuego.h DataBase.h Venta.h  main.cpp -c -std=c++11 -lboost_serialization


UsuarioA.o: UsuarioA.cpp UsuarioA.h Usuario.h
	g++  UsuarioA.cpp Usuario.cpp -c -std=c++11 -lboost_serialization

UsuarioT.o:	UsuarioT.cpp UsuarioT.h Usuario.h
	g++ UsuarioT.cpp Usuario.cpp -c -std=c++11 -lboost_serialization


NintendoJuego.o:	NintendoJuego.cpp NintendoJuego.h VideoJuego.h
	g++ NintendoJuego.cpp VideoJuego.cpp -c -std=c++11 -lboost_serialization

SonyJuego.o:	SonyJuego.cpp SonyJuego.h VideoJuego.h
	g++ SonyJuego.cpp VideoJuego.cpp -c -std=c++11 -lboost_serialization

MicrosoftJuego.o:	MicrosoftJuego.cpp MicrosoftJuego.h VideoJuego.h
	g++ MicrosoftJuego.cpp VideoJuego.cpp -c -std=c++11 -lboost_serialization

Bandai.o:	Bandai.cpp Bandai.h VideoJuego.h
	g++ Bandai.cpp VideoJuego.cpp -c -std=c++11 -lboost_serialization

ElectronicArts.o:	ElectronicArts.cpp ElectronicArts.h VideoJuego.h
	g++ ElectronicArts.cpp VideoJuego.cpp -c -std=c++11 -lboost_serialization

Konami.o:	Konami.cpp Konami.h VideoJuego.h
	g++ Konami.cpp VideoJuego.cpp -c -std=c++11 -lboost_serialization

Sega.o:	Sega.cpp Sega.h VideoJuego.h
	g++ Sega.cpp VideoJuego.cpp -c -std=c++11 -lboost_serialization

SquareEnix.o:	SquareEnix.cpp SquareEnix.h VideoJuego.h
	g++ SquareEnix.cpp VideoJuego.cpp -c -std=c++11 -lboost_serialization

Ubisoft.o:	Ubisoft.cpp Ubisoft.h VideoJuego.h
	g++ Ubisoft.cpp VideoJuego.cpp -c -std=c++11 -lboost_serialization


Sony.o:	Sony.h Sony.cpp Consola.h
	g++ Sony.cpp Consola.cpp -c -std=c++11 -lboost_serialization

Nintendo.o:	Nintendo.h Nintendo.cpp Consola.h
	g++ Nintendo.cpp Consola.cpp -c -std=c++11 -lboost_serialization

Microsoft.o:	Microsoft.h Microsoft.cpp Consola.h
	g++ Microsoft.cpp Consola.cpp -c -std=c++11 -lboost_serialization


Usuario.o:	Usuario.h Usuario.cpp
	g++ Usuario.cpp -c -std=c++11

Consola.o:	Consola.h Consola.cpp
	g++ Consola.cpp -c -std=c++11 -lboost_serialization

VideoJuego.o:	VideoJuego.h VideoJuego.cpp
	g++ VideoJuego.cpp -c -std=c++11 -lboost_serialization

DataBase.o:	DataBase.h DataBase.cpp
	g++ DataBase.cpp -c -std=c++11 -lboost_serialization

Venta.o:	Venta.h Venta.cpp
	g++ Venta.cpp -c -std=c++11

clean:
	rm *.o *.h.gch main
