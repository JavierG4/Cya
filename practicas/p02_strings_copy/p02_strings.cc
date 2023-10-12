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
#include "p02_strings.h"
#include <set>
#include "p02_alfabeto.h"

  void Cadena::longitud(std::string entrada, std::string salida) {
    std::ifstream archivo_entrada{entrada};
    std::ofstream archivo_salida{salida};
    std::string linea;
    while (getline(archivo_entrada, linea)){
      int longitud = linea.length();
      archivo_salida << longitud << std::endl;
    }
  }

  void Cadena::inversa(std::string entrada, std::string salida) {
    std::ifstream archivo_entrada{entrada};
    std::ofstream archivo_salida{salida};
    std::string linea;
    while (getline(archivo_entrada, linea)){
      for(std::string::reverse_iterator rit=linea.rbegin(); rit!=linea.rend(); ++rit) {
        archivo_salida << *rit;
      }
      archivo_salida << std::endl;
    }
  }

  void Cadena::prefijos(std::string entrada, std::string salida){
    std::ifstream archivo_entrada{entrada};
    std::ofstream archivo_salida{salida};
    std::string linea;
    while (getline(archivo_entrada, linea)){
      archivo_salida << "{&,";
      std::string auxiliar;
      int contador = 1;
      for (int i = 0; i < linea.length(); i++){
        if(contador == linea.length()) {
          auxiliar += linea.at(i);
          archivo_salida << auxiliar;
        }
        else {
          auxiliar += linea.at(i);
          archivo_salida << auxiliar << ",";
        }
        contador++;
      }
      archivo_salida << "}" << std::endl;
    }
  }

  void Cadena::sufijos(std::string entrada, std::string salida) {
    std::ifstream archivo_entrada{entrada};
    std::ofstream archivo_salida{salida};
    std::string linea;
    while (getline(archivo_entrada, linea)){
      archivo_salida << "{&, ";
      for(int i = 0; i < linea.length(); ++i) {
        int contador = i;
        for(int j = linea.length() -1; j - contador < linea.length(); --contador) { 
				if((j - contador != linea.length() -1) || (j - contador == linea.length() -1 && i == linea.length() - 1)) { 
					archivo_salida << linea[j - contador];
				}
				else {
					archivo_salida << linea[j - contador] << ", ";
				}

			}
		}
		archivo_salida << "}" << std::endl;
  }
}

void Cadena::concatenar(std::string entrada) {
  std::ifstream archivo_entrada{entrada};
  std::string linea;
  std::string resultado;
  while (getline(archivo_entrada, linea)){ 
    for (int i = 0; i < linea.length(); i++){
      resultado += linea.at(i);
    }
  }
  std::ofstream archivo_salida{entrada};
  archivo_salida << resultado << std::endl;
}

/*
std::string Cadena::concatenar(std::string entrada) {
  std::ifstream archivo_entrada{entrada};
  std::string linea;
  std::string resultado;
  while (getline(archivo_entrada, linea)){ 
    for (int i = 0; i < linea.length(); i++){
      resultado += linea.at(i);
    }
  }
  return resultado;
}
*/
/*void Cadena::todo(std::string entrada, std::string salida) {
  Cadena resultado;
   std::ofstream archivo_salida{salida};
  resultado.longitud(entrada,salida);
  archivo_salida << "-----------------------" << std::endl;
  resultado.inversa(entrada,salida);
  archivo_salida << "-----------------------" << std::endl;
  resultado.prefijos(entrada,salida);
  archivo_salida << "-----------------------" << std::endl;
  resultado.sufijos(entrada,salida);
  archivo_salida << "-----------------------" << std::endl;
}
*/
