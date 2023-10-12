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

#include "p02_alfabeto.h"

Alfabeto::Alfabeto(std::string entrada) {
  std::ifstream archivo_entrada{entrada};
  for (int i = 0; i < entrada.length(); i++){
    alfabeto_.insert(entrada.at(i));
  }
}

void Alfabeto::remove_set() {
  std::set<char> set = alfabeto_;
  for (auto& carcater : set) {
    alfabeto_.erase(carcater);
  }
}

void Alfabeto::print_set(std::string entrada, std::string salida){
  remove_set();
  std::ifstream archivo_entrada{entrada};
  std::ofstream archivo_salida{salida};
  std::string linea;
  while (getline(archivo_entrada, linea)) {
		Alfabeto set(linea);
		archivo_salida << set;
		remove_set();
	}
}

std::ostream& operator<<(std::ostream& out, Alfabeto& a) {
	out << "{";
  auto iterador = a.get_set().rbegin(); 
	for (auto i : a.get_set()) { 
		if (*iterador == i) {
			out << i;
			continue;
		}
		out << i << ", ";
	}
	out << "}" << std::endl;
  return out;
}

std::set<char> Alfabeto::get_set() {
  return alfabeto_;
}
