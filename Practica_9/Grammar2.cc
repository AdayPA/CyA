// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º
// @praxis: Number 7 CyA - "DFA"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 04/11/2020
// @brief DFA.cc :  This is the implementation of .h
// @compile: $ make
// References:
// References:
// https://en.wikipedia.org/wiki/Deterministic_finite_automaton
// Lab exercise:
// (private link)
// Others links:
//  https://stackoverflow.com/questions/14975737/regular-expression-to-remove-comment
//  https://regexr.com/5gecl
// Version Control:
// 23/11/2020 - First version of the code

#ifndef PRACTICA_9_GRAMMAR2_CC_
#define PRACTICA_9_GRAMMAR2_CC_

#include "Grammar2.h"

#include <iostream>
#include <fstream>

Grammar2::Grammar2() {  
  /// @brief we set the bools to false as init
}

Grammar2::Grammar2(DFA dfa) {  
  /// @brief we set the bools to false as init
  alphabet_2 = dfa.GetAlphabet();
  states_2 = dfa.GetStates();
  accept_states_2 = dfa.GetAcceptStates();
  start_2 = dfa.GetStart();
  transitions_2 = dfa.GetTransitions();
  Convert();
}

Grammar2::~Grammar2() {}


void Grammar2::Test(void) {
}

// P = {q → ap | δ(q, a) = p} ∪ {q → ε | q ∈ F}

void Grammar2::Convert(void) {
  std::cout << "size antes de copia: " << produccion_.GetSize() << std::endl;
  for (int i = 0; i < transitions_2.GetSize(); ++i) {
    std::string temp = transitions_2.GetNode(i)->final_state_;
    const bool is_in_accept = accept_states_2.find(temp) != accept_states_2.end();
    if (is_in_accept) {
      produccion_.Insert(transitions_2.GetNode(i)->init_state_,
                         transitions_2.GetNode(i)->symbol_,
                         transitions_2.GetNode(i)->final_state_);
      produccion_.Insert(transitions_2.GetNode(i)->final_state_,
                         "", "e");
    } else {
      produccion_.Insert(transitions_2.GetNode(i)->init_state_,
                         transitions_2.GetNode(i)->symbol_,
                         transitions_2.GetNode(i)->final_state_);
    }
  }
  std::cout << "size despues de copia: " << produccion_.GetSize() << std::endl;
  for (int i = 0; i < produccion_.GetSize(); ++i) {
    std::cout << produccion_.GetNode(i)->init_state_ << " -> " <<
    produccion_.GetNode(i)->symbol_ << produccion_.GetNode(i)->final_state_
    << std::endl;
  }
}

void Grammar2::Print(void) {
  std::cout << "Tamaño : " << alphabet_2.size()  << std::endl;
  for (auto it = alphabet_2.begin(); it != alphabet_2.end(); ++it)
        std::cout << ' ' << *it;
}

#endif  // PRACTICA_9_GRAMMAR2_CC_
