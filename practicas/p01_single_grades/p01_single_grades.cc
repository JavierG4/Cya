// Universidad de La Laguna
// Escuela Superior de Ingenier´ıa y Tecnolog´ıa
// Grado en Ingenier´ıa Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 1: Contenedores asociativos
// Autor: Nombre y Apellidos
// Correo: aluXXXXX@ull.edu.es
// Fecha: 12/09/2023
// Archivo cya-P01-single-grades.cc: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de inter´es
/
// Historial de revisiones
// 12/09/2023 - Creaci´on (primera versi´on) del c´odigo
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <map>
void lectura(){
  std::ifstream archivo{argv 1};
  std::string texto;
  archivo.open()
  if (archivo.fail()) {
    std::cout << "No se puedo abrir el archivo";
    exit(1);
  }
  while(std::getline(archivo,texto)){
    std::istringstream fluejo_entrada(texto);
    std::map<char,int> mymap;

  }

}