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
// @brief Transition.cc : This is the implementation of the header file
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

#ifndef PRACTICA_9_TRANSITION_CC_
#define PRACTICA_9_TRANSITION_CC_
#include <iostream>

#include "/home/usuario/cya/Practica_9/Transition.h"

Transition::Transition() {}

Transition::~Transition() {}

std::string Transition::GetFinalNode(std::string initstate, std::string symbol) {
  std::string result;
  for (unsigned i = 0; i < set_transitions_.size(); ++i) {
    if ((set_transitions_[i]->init_state_ == initstate) && 
        (set_transitions_[i]->symbol_ == symbol)) {
          result = set_transitions_[i]->final_state_;
    }
  }
  return result;
}

void Transition::Insert(std::string& initstate, std::string& symbol,
                                                std::string& finalstate) {
  Node* temp = new Node {initstate, symbol, finalstate};
  set_transitions_.push_back(temp);
}

#endif  // PRACTICA_9_TRANSITION_CC_
