// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º
// @praxis: Number 9 CyA - "Gramaticas Regulares y Autómatas Finitos. Gramatica
//                          regular a partir de un DFA"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 23/11/2020
// @brief Transition.cc :
// @compile: $ make
// References:
// https://en.wikipedia.org/wiki/Deterministic_finite_automaton
// Lab exercise:
// (private link)
// Others links:
//  https://stackoverflow.com/questions/14975737/regular-expression-to-remove-comment
//  https://regexr.com/5gecl
// Version Control:
// 23/11/2020 - First version of the code

#ifndef PRACTICA_9_PRODUCCION_CC_
#define PRACTICA_9_PRODUCCION_CC_
#include <iostream>
#include <algorithm>
#include <set>

#include "/home/usuario/cya/Practica_9/Produccion.h"

Produccion::Produccion() {}

Produccion::~Produccion() {}

void Produccion::Insert(std::string initstate, std::string symbol,
                                                std::string finalstate) {
  /// @brief we insert the production in the vector
  Node* temp = new Node {initstate, symbol, finalstate};
  set_produccion_.push_back(temp);
}

void Produccion::ClearProduccion(void) {
  /// @brief we erase the duplicates productions
  unsigned int position = 0;
  while (position < set_produccion_.size()) {
    for (unsigned int i = position + 1; i < set_produccion_.size(); ++i) {
      if ((set_produccion_.at(position)->init_state_ == set_produccion_.at(i)->init_state_) &&
          (set_produccion_.at(position)->symbol_ == set_produccion_.at(i)->symbol_) && 
          (set_produccion_.at(position)->final_state_ == set_produccion_.at(i)->final_state_)) {
            set_produccion_.erase(set_produccion_.begin() + position);
      }
    }
    ++position;
  }
}

#endif  // PRACTICA_9_PRODUCCION_CC_
