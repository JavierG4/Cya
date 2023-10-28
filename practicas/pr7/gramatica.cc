#include "gramatica.h"

Gramatica::Gramatica(char arranque ,Alfabeto alfabeto ,std::set<char> terminales,std::multimap<char, std::string> transiciones){
    estado_arranque_ = arranque;
    alfabeto_ = alfabeto;
    terminales_ = terminales;
    producciones_ = transiciones;
}

char Gramatica::get_estado_arranque(){
    return estado_arranque_;
}
void Gramatica::set_estado_arranque(char arranque){
    estado_arranque_ = arranque;
}

Alfabeto Gramatica::get_alfabeto(){
    return alfabeto_;
}   
void Gramatica::set_alfabeto(Alfabeto alfabeto){
    alfabeto_ = alfabeto;
}

std::set<char> Gramatica::get_terminales(){
    return terminales_;
}
void Gramatica::set_terminales(std::set<char> noterminales){
    terminales_ = noterminales;
}

std::multimap<char, std::string> Gramatica::get_producciones(){
    return producciones_;
}
void Gramatica::set_producciones(std::multimap<char, std::string> transiciones){
    producciones_ = transiciones;
}

void Gramatica::print(){
  std::cout << "El estado de arranque es " << estado_arranque_ << std::endl;
  auto aux = alfabeto_.get_set();
  std::cout << "Estos son los no terminales" << std::endl;
  for ( char terminales: aux){
    std::cout << terminales << " ";
  }
  std::cout << " " << std::endl;
  std::cout << "Estos son los terminales " << std::endl;
  for(char notermin : terminales_){
    std::cout << notermin << " ";
  }
  std::cout << "\n";
  for (auto it = producciones_.begin(); it != producciones_.end(); ++it) {
    std::cout << it->first << " -> " << it->second << std::endl;
  }
}
// A ++ B ++ C ++ 
char Gramatica::buscar_identificador() {
  char identificador = 'A';
  for (auto alfabeto : alfabeto_.get_set()) {
    if ( identificador != alfabeto ){
      return identificador;
    }
    else {
      identificador++;
    }
  }
  return identificador;
}

void Gramatica::transoformacion_a_chomksy(){
  for (auto it = producciones_.begin(); it != producciones_.end(); ++it) {
    if (it->second == "&") {
      std::cout << "La gramática contiene & transiciones "<< it->first << " -> " << it->second << std::endl;
      return;
    }
    if (it->second.size() == 1) {
      for (auto termin: alfabeto_.get_set()) {
        for(auto aux2 : it -> second) {
          if ( aux2 == termin ){
            std::cout << "Tiene producciones unitarias en " << it->first << " -> " << termin << std::endl;
            return;
          }
        }
      }
    }
  }
  for (auto it1 = producciones_.begin(); it1 != producciones_.end(); ++it1) {
    int tam = it1->second.size(); // Tamaño string
    std::cout << it1->second << std::endl;
    std::cout << "pre if" << std::endl;
    if ( tam >= 2 ) {
      for (auto iterador: it1->second ) { // Compruebo los char de la string para ver si hay terminales
        std::cout << "post if" << std::endl;
        for (auto termin : terminales_) { // Compruebo el set de los terminales
          if (iterador == termin) { // Si es un terminal lo que hay en la string 
          std::cout << "pre comprobar" << std::endl;
            for (auto it2 = producciones_.begin(); it2 != producciones_.end(); ++it2) { // Compruebo si hay alguna clave que genere ese terminal solo
              auto string = it2->second;
              if(string[0] == iterador && string.size() == 1 ) { 
                char identi = buscar_identificador();
                std::string aux4;
                aux4 += iterador;
                producciones_.emplace(identi, aux4);
                //std::cout << iterador << std::endl;
              }
            }
          }
        }
      }
    }
  }
}

