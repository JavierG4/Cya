// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 1: Contenedores asociativos
// Autor: Javier González Brito
// Correo: alu0101548197@ull.edu.es
// Fecha: 17/09/2023
// Archivo cya-P01-single-grades_main.cc: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases X e Y
// Programa que le envias por parametros un txt
// y te escribe las notas de los alumnos y además te da la opcion de añadir notas
// Enlaces de inter´es
// Historial de revisiones
// 12/09/2023 - Creaci´on (primera versi´on) del c´odigo
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#include "p02_strings.h"

int main(int argc, char* argv[]) {

	std::string entrada = argv[1];
	std::string salida = argv[2];
	if(entrada == "--help") {  //mostrar ayuda del programa por pantalla
		std::cout << "Este programa sirve para realizar operaciones entre cadenas.Para que funcione correctamente se debe especificar un archivo " << std::endl;
		std::cout << "de entrada y otro de salida" << std::endl;
		std::cout << "Error. Se debe especificar el nombre de un archivo de linea de entrada y otro de salida en el comando, ademas de la operacion deseada" << std::endl;
		std::cout << "Este es el menu de opciones disponible " << std::endl;
		std::cout << "1: mostrar en el fichero de salida el alfabeto asociado a cada una de las cadenas de entrada " << std::endl;
		std::cout << "2: mostrar en el fichero de salida la longitud de cada cadena de entrada" << std::endl;
		std::cout << "3: mostrar en el fichero de salida la inversa de cada cadena de entrada" << std::endl;
		std::cout << "4: mostrar en el fichero de salida el conjunto de cadenas que son prefijos de la cadena de entrada correspondiente" << std::endl;
		std::cout << "5: mostrar en el fichero de salida el conjunto de cadenas que son sufijos de la cadena de entrada correspondiente" << std::endl;
		return 0;
	}
	
	std::string opcion = argv[3];
	if(opcion != "1" && opcion != "2" && opcion != "3" && opcion != "4" && opcion != "5") {
		std::cout << "Error, las operaciones solo pueden ser 1,2,3,4 o 5 para saber más utilice --help" << std::endl;
		return 0;
	}
	
	Cadena cadenas;
	if (opcion == "1"){
		cadenas.alfabeto(entrada,salida);
	}
	if (opcion == "2"){ 
		cadenas.longitud(entrada,salida);
	}
	
	if (opcion == "3"){ 
		cadenas.inversa(entrada,salida);
	}
	
	if (opcion == "4"){ 
		cadenas.prefijos(entrada,salida);
	}
	
	if (opcion == "5"){ 
		cadenas.sufijos(entrada,salida);
	}
 

}