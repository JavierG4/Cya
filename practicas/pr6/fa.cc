#include "fa.h"
 
int Automata::get_n_estados(){
    return n_estados_;
}

void Automata::set_n_estados(int estado_n){
    n_estados_ = estado_n;
}

int Automata::get_estado_inicial(){
    return estado_inicial_;
}

void Automata::set_estado_inicial(int inicial){
    estado_inicial_ = inicial;
}

Alfabeto Automata::get_alfabeto(){
    return alfabeto_;
}

void Automata::set_alfabeto(Alfabeto alfabeto){
    alfabeto_ = alfabeto;
}
   
std::vector<Estado> Automata::get_conjunto_de_estados() {
    return conjunto_de_estados_;
}

void Automata::Add_estado(Estado estado){
    conjunto_de_estados_.emplace_back(estado);
}

void Automata::print(){
    std::cout << "El numero de estados es de " << n_estados_ << std::endl;
    std::cout << "El estado inicial es " << estado_inicial_ << std::endl;
    std::cout << "\n  Transiciones:\n\n";
    for(int i = 0; i < conjunto_de_estados_.size(); i++){
        std::cout << " El estado " << i << " tiene aceptacion " << conjunto_de_estados_[i].get_aceptacion() << std::endl;
        std::cout << " El estado " << i << " tiene estas transiciones -" << std::endl;
        for (const auto& par : conjunto_de_estados_.at(i).get_siguiente_estado()) { 
            std::cout << "    Simbolo necesario para producirse la transición: "; 
            std::cout << par.first << "\n    Estado destino: " << par.second << "\n\n"; 
        } 
    }
}

void Automata::epsilon_transicones(std::vector<Estado>& estados){
  bool added = 1;
  int indice = 0;
  while(added) {
    added = 0;
    if(!estados[indice].Visitado() && indice < estados.size() && indice < conjunto_de_estados_.size()) {
      std::multimap<char, int> map = estados[indice].get_siguiente_estado();
      conjunto_de_estados_[indice].set_visitado(1);
      auto rango = map.find('&');
      if(rango != map.end()) {
        auto rango_ = map.equal_range('&'); // rango contiene la epsilontransicion
        for(auto it = rango_.first; it != rango_.second; ++it) {
          estados.push_back(conjunto_de_estados_[it -> second]);
        }
        added = true;
      } 
    }
    ++indice;
  }
  for(int i = 0; i < conjunto_de_estados_.size(); ++i) {
    conjunto_de_estados_[i].set_visitado(0);
  }
  for(int i = 0; i < estados.size(); ++i) {
    estados[i].set_visitado(0);
  }
}

std::vector<Estado> Automata::delta_transiciones(char simbol, std::vector<Estado>& actuales){
  int p = actuales.size();
  std::vector<Estado> siguientes;
  for(int n = 0; n < p; n++){
    std::multimap <char, int> map = actuales[n].get_siguiente_estado();  // Apartir de aquí recorremos los estados actuales uno por uno y vemos sus transiciones      
    auto rango = map.equal_range(simbol);
    for (auto it = rango.first; it != rango.second; ++it) {
      siguientes.emplace_back(conjunto_de_estados_[it -> second]); 
    }
  }
  return siguientes;
}
