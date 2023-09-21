// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 1: Contenedores asociativos
// Autor: Javier González Brito
// Correo: alu0101548197@ull.edu.es
// Fecha: 19/09/2023
// Archivo cya-P01-single-grades_main.cc: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases X e Y
// Programa que le envias por parametros un txt
// y te escribe las notas de los alumnos y además te da la opcion de añadir notas
// Referencias:
// Enlaces de inter´es
// Historial de revisiones
// 12/09/2023 - Creaci´on (primera versi´on) del c´odigo
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <map>
#include "p01_single_grades.h"

void lectura(std::map<std::string,float>& mapa, std::string param){
  std::ifstream archivo{param};
  std::string texto;
  std::string alu;
  float nota;
  if (archivo.fail()) { // Si falla el archivo se imprime
    std::cout << "No se puedo abrir el archivo";
    exit(1);
  }
  while (archivo >> alu >> nota) {   // Se añaden en el map las notas y los alus       
    if(mapa[alu] > nota) { // si la nota es mayor se cambia por la anterior, sino se queda la anterior
      continue;
    }
    mapa[alu] = nota;
  }
}

void escritura (std::map<std::string,float>& mapa) { // Imprime en pantalla en los alumnos y sus notas
  for (std::map<std::string,float>::iterator it=mapa.begin(); it!=mapa.end(); ++it) {   
    std::cout << it->first << " " << it->second << '\n';
  }
 }
