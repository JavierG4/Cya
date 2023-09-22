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
#include "p02_strings.h"
#include <set>

  void Cadena::alfabeto(std::string entrada, std::string salida) {
    std::ifstream archivo_entrada{entrada};
    std::ofstream archivo_salida{salida};
    std::string linea;
    while (getline(archivo_entrada, linea)){
      archivo_salida << "{";
      std::set<char> alfabet;
      for (int i = 0; i < linea.length(); i++){
        alfabet.insert(linea.at(i));
      }
      std::set<char>::iterator contador=alfabet.begin();
      contador++;
      for (std::set<char>::iterator it=alfabet.begin(); it!=alfabet.end(); ++it) {
        if(contador != alfabet.end()) { 
          archivo_salida << *it << ",";
        }
        else {
          archivo_salida << *it;

        }
        contador++;
      }
      archivo_salida << "}" << std::endl;
    }

  }
  void Cadena::longitud(std::string entrada, std::string salida) {
    std::ifstream archivo_entrada{entrada};
    std::ofstream archivo_salida{salida};
    std::string linea;
    while (getline(archivo_entrada, linea)){
      int longitud = linea.length();
      archivo_salida << longitud << std::endl;
    }
  }
  //void Cadena::inversa(std::string entrada, std::string salida);
  //void Cadena::prefijos(std::string entrada, std::string salida);
  //void Cadena::sufijos(std::string entrada, std::string salida);

