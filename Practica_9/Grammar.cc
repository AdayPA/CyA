// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º
// @praxis: Number 7 CyA - "DFA"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 04/11/2020
// @brief Grammar.cc :  This is the implementation of .h
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

#ifndef PRACTICA_9_GRAMMAR_CC_
#define PRACTICA_9_GRAMMAR_CC_

#include "Grammar.h"

#include <iostream>
#include <fstream>

const char kEpsilon[] = "~";

Grammar::Grammar() {
  /// @brief we set the bools to false as init
}

/*
Grammar::Grammar(DFA dfa) {  
  /// @brief we set the bools to false as init
  alphabet_2 = dfa.GetAlphabet();
  states_2 = dfa.GetStates();
  accept_states_2 = dfa.GetAcceptStates();
  start_2 = dfa.GetStart();
  transitions_2 = dfa.GetTransitions();
  Convert();
}*/

Grammar::~Grammar() {}

void Grammar::SetAlphabet(std::set<std::string> set_alpha) {
  alphabet_2 = set_alpha;
}

void Grammar::SetStates(std::set<std::string> set_states) {
  states_2 = set_states;
}

void Grammar::SetStart(std::string start) {
  /// @brief if start state belong to state, we add it
  const bool is_in = states_2.find(start) != states_2.end();
  if (is_in) {
    start_2 = start;
    start_ok_ = true;
  } else {
    start_ok_ = false;
    failed_ = true;
  }
}

void Grammar::SetAcceptStates(std::set<std::string> set_state) {
  /// @brief if start state belong to the set of states, we add it
  accept_states_2 = set_state;
}

void Grammar::SetProduccion(std::string init_state, std::string symbol,
                                              std::string final_state) {
  produccion_.Insert(init_state, symbol, final_state);
}



void Grammar::PrintFile(std::string output_file) {
  /// @brief we open the output file and write the result in it
  Generadores();
  produccion_.ClearProduccion();
  std::ofstream output_stream;
  output_stream.open(output_file);
  if (output_stream.is_open()) {
    output_stream << alphabet_2.size();
    for (auto it = alphabet_2.begin(); it != alphabet_2.end(); ++it) {
      output_stream << std::endl << *it;
    }
    output_stream << std::endl << states_2.size();
    for (auto it = states_2.begin(); it != states_2.end(); ++it) {
      output_stream << std::endl << *it;
    }
    output_stream << std::endl << start_2;
    output_stream << std::endl << produccion_.GetSize();
    for (int i = 0; i < produccion_.GetSize(); ++i) {
      output_stream << std::endl << produccion_.GetNode(i)->init_state_ <<
      " -> " << produccion_.GetNode(i)->symbol_ <<
      produccion_.GetNode(i)->final_state_;
    }
  }
}

void Grammar::Generadores(void) {
  std::set<std::string> generadores;
  bool trigger = true;
  for (int i = 0; i < produccion_.GetSize(); ++i) {
    if (produccion_.GetNode(i)->final_state_ == kEpsilon) {
      generadores.insert(produccion_.GetNode(i)->init_state_);
    }
  }
  while (trigger == true) {
    trigger = false;
    unsigned int size = generadores.size();
    for (auto it = generadores.begin(); it != generadores.end(); ++it) {
        for (int i = 0; i < produccion_.GetSize(); ++i) {
          if (produccion_.GetNode(i)->final_state_ == *it) {
            generadores.insert(produccion_.GetNode(i)->init_state_);
          }
        }
    }
    if (size != generadores.size()) {
      trigger = true;
    }
  }
  for (auto it = generadores.begin(); it != generadores.end(); ++it) {
    std::cout << *it << " es generador" << std::endl;
  }
}


#endif  // PRACTICA_9_GRAMMAR_CC_
