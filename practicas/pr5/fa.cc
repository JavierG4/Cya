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