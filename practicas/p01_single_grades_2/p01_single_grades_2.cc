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
#include "p01_single_grades_2.h"
#include<vector>

void lectura2(std::map<std::string,std::vector<float>>& mapa, std::string param){ // Definicion de la funcion lectura
  std::ifstream archivo{param};
  std::string texto;
  std::string alu;
  float nota;
  if (archivo.fail()) { // Si falla el archivo se imprime
    std::cout << "No se puedo abrir el archivo";
    exit(1);
  }
  while(archivo >> alu >> nota) { // Se añaden en el map las notas y los alus     
    mapa[alu].emplace_back(nota);
  }
}
void escritura2(std::map<std::string,std::vector<float>>& mapa) { // Imprime en pantalla en los alumnos y sus notas con dos for
  for (std::map<std::string,std::vector<float>>::iterator it=mapa.begin(); it!=mapa.end(); ++it) {
    std::cout << it->first << " ";
    for(int j = 0;j < mapa[it->first].size();j++){
      std::cout << it->second.at(j) << " ";
    }
    std::cout << '\n';
  }
 }
