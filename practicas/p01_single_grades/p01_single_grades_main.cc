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
#include <map>
#include "p01_single_grades.h"

int main(int argc, char *argv[]) { 
  std::map<std::string,float> students;
  std::string parametro = argv[1];
  lectura(students, parametro); // Parametro 1 Map / Parametro 2 Texto
  escritura(students); // Parametro 1 Map
  bool seguir = true;
  while (seguir == true) { // While para añadir alumnos y notas
    std::cout << "Quieres añadir alumnos y notas ? Pulse 1 para si 2 para no" << std::endl;
    int eleccion;
    std::string alumno;
    float nota;
    std::cin >> eleccion;
    if (eleccion == 1) {
      std::cout << "Escriba el alu y despues su nota" << std::endl;
      std::cin >> alumno >> nota;
      if (students[alumno] > nota) {
        continue;
      }
      students[alumno] = nota;
    }
    else {
      seguir = false;
      escritura(students);
    }
  }
}