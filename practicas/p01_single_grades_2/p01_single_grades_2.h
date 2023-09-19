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
#ifndef p01_single_grades_2_h
#define p01_single_grades_2_h

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <map>
#include <vector>

void lectura2(std::map<std::string,std::vector<float>>&, std::string); // Definicion de la funcion lectura que se encarga de leer los datos y meterlos en el map
void escritura2(std::map<std::string,std::vector<float>>&); // Definición de la funcion escritura que se encarga de imprimir la notas y los alus


#endif  // p01_single_grades_2_h
