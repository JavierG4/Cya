#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include "gramatica.h"
#include <algorithm>
#include <stack>

int main (int argc, char* argv[]) {
  if(argc < 2) {   // comprobar si escribieron parametros de entrada
    std::cout << "Para ejecutar el programa haga ./automata input.fa cadenas.txt " << std::endl;
    std::cout << "Pruebe ./automata --help para mas informacion. " << std::endl;
    return 0;
  }

  std::string help_1 = argv[1];
  if(help_1 == "--help") {  // opcion para mostrar una breve ayuda sobre el comando
    std::cout << "Para ejecutar este programa necesitas un archivo input.fa en el que tienes definidos los datos de un autómata" << std::endl;
    std::cout << "Además necesitas un cadenas.txt en el que escribas cadenas para ver si pertenecen al autómata " << std::endl;
    std::cout << "Ya sabiendo eso puedes ejecutar el programa asi ./automata input.fa cadenas.txt " << std::endl;
    return 0;
  }
  std::string archivo = argv[1];
  std::ifstream gra{archivo};
  int noterminales = 0;
  gra >> noterminales;
  std::set<char> setterminales;
  for (int i = 0; i < noterminales; i++) {
    char notermin;
    gra >> notermin;
    setterminales.insert(notermin);
  }
  int terminales = 0;
  gra >> terminales;
  std::set<char> alfabeto;
  for (int i = 0; i < terminales; i++){
    char termin;
    gra >> termin;
    alfabeto.insert(termin);
  }
  int producciones;
  gra >> producciones;
  producciones = producciones -1;
  char arranque;
  Alfabeto alfabet;
  std::multimap<char, std::string> produccionesmap;
  std::string arranque_string;
  gra >> arranque;
  gra >> arranque_string;
  alfabeto.insert(arranque);
  produccionesmap.emplace(arranque,arranque_string);
  for (int i = 0; i < producciones; i++){
    char noterminal;
    std::string produccion;
    gra >> noterminal;
    gra >> produccion;
    produccionesmap.emplace(noterminal,produccion);
  }
  bool correcto = 1;
  std::set<char> ambos;
  char ep = '&';
  ambos.insert(ep);
  for (auto aux : setterminales ) {
    ambos.insert(aux);
  }
  for (auto aux :alfabeto) {
    ambos.insert(aux);
  }
  std::set<char> comparacion = ambos;
  for (auto it = produccionesmap.begin(); it != produccionesmap.end(); ++it) {
    comparacion.insert(it->first);
    for (auto aux1 : it->second) {
      comparacion.insert(aux1);
    }
  }
  if ( comparacion != ambos ) {
    //std::cout << ambos.size() << " - " << comparacion.size() << std::endl;
    std::cout << "Hay terminales o no terminales en las producciones que no pertenecen al alfabeto o al conjunto de no terminales" << std::endl;
  }
  else { 
    alfabet.set_set(setterminales);
    Gramatica gramatica(arranque,alfabet,alfabeto,produccionesmap);
  //std::cout << gramatica;
    gramatica.print();
    gramatica.transoformacion_a_chomksy();;
    std::string salida = argv[2];
    gramatica.print_out(salida);
  }
} 
