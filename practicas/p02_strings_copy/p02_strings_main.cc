// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 1: Contenedores asociativos
// Autor: Javier González Brito
// Correo: alu0101548197@ull.edu.es
// Fecha: 26/09/2023
// Archivo p02_stings.cc
// Contiene la funci´on main del proyecto que usa las clases X e Y
// Programa que le envias 3 parametros por línea de comando
// El primero es la entrada.txt, el segundo la salida.txt y el 3 sirve para decidir que tripo de operacion qieires realizar
// Enlaces de inter´es
// Historial de revisiones
// 20/09/2023 - Creaci´on (primera versi´on) del c´odigo

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#include "p02_strings.h"
#include "p02_alfabeto.h"

int main(int argc, char* argv[]) {

	std::string entrada = argv[1];
	std::string salida = argv[2];

	if((argc == 2 && entrada != "--help") || argc == 3 ) { // comprobar que se especifican los archivos por linea de comandos
		std::cout << "Error. Se debe especificar el nombre de un archivo de linea de entrada y otro de salido en el comando, ademas de la operacion deseada" << std::endl;
		std::cout << "A continuacion, estas son las diferentes operaciones: " << std::endl;
		std::cout << "1: escribir en el fichero de salida el alfabeto asociado a cada una de las cadenas de entrada " << std::endl;
		std::cout << "2: escribir en el fichero de salida la longitud de cada cadena de entrada" << std::endl;
		std::cout << "3: escribir en el fichero de salida la inversa de cada cadena de entrada" << std::endl;
		std::cout << "4: escribir en el fichero de salida el conjunto de cadenas que son prefijos de la cadena de entrada correspondiente" << std::endl;
		std::cout << "5: escribir en el fichero de salida el conjunto de cadenas que son sufijos de la cadena de entrada correspondiente" << std::endl;
		return 0;
	}
	if(argc < 3 && argv[2] != "--help" ) {  // comprobar que se especifica los archivos por linea de comandos
		std::cout << "Error. Se debe especificar el nombre de un archivo de linea de entrada y otro de salida en el comando, ademas de la operacion deseada" << std::endl;
		std::cout << "A continuacion, estas son las diferentes operaciones: " << std::endl;
		std::cout << "1: escribir en el fichero de salida el alfabeto asociado a cada una de las cadenas de entrada " << std::endl;
		std::cout << "2: escribir en el fichero de salida la longitud de cada cadena de entrada" << std::endl;
		std::cout << "3: escribir en el fichero de salida la inversa de cada cadena de entrada" << std::endl;
		std::cout << "4: escribir en el fichero de salida el conjunto de cadenas que son prefijos de la cadena de entrada correspondiente" << std::endl;
		std::cout << "5: escribir en el fichero de salida el conjunto de cadenas que son sufijos de la cadena de entrada correspondiente" << std::endl;
		return 0;
	}
	std::string opcion = argv[3];
	if (opcion != "1" && opcion != "2" && opcion != "3" && opcion != "4" && opcion != "5") {
		std::cout << "Error, las operaciones solo pueden ser 1,2,3,4 o 5 para saber más utilice --help" << std::endl;
		return 0;
	}
	
	Cadena cadenas;
	Alfabeto alphabet(entrada);
	if (opcion == "1"){
		alphabet.print_set(entrada,salida);
	}
	if (opcion == "2"){ 
		cadenas.longitud(entrada,salida);
	}
	
	if (opcion == "3") { 
		cadenas.inversa(entrada,salida);
	}
	
	if (opcion == "4") { 
		cadenas.prefijos(entrada,salida);
	}
	
	if (opcion == "5"){ 
		cadenas.sufijos(entrada,salida);
	}
	if (opcion == "6"){
	  Cadena cadenas1;
	  std::ofstream archivo_salida{salida};
	  cadenas1.concatenar(entrada);
	  // archivo_salida << resultado;
	  Alfabeto alphabet1 (entrada);
	  alphabet1.print_set(entrada,salida);
	  /*
	  cadenas.longitud (entrada,salida);
  	  cadenas.inversa (entrada,salida);
	  cadenas.prefijos (entrada,salida);
  	  cadenas.sufijos (entrada,salida);
	  */

	}
}