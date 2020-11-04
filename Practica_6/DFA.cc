// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 5 CyA - "Sets"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 04/11/2020
// @brief DFA.cc :  This is the main of the praxis
//                 
// @compile: $ make                                                    
// References: 
// https://es.wikipedia.org/wiki/B%C3%BAsqueda_de_patrones
// https://es.wikipedia.org/wiki/ASCII
// Lab exercise:
// https://github.com/garamira/CyA-P06-Patterns
// Version Control:
// 04/11/2020 - First version of the code 
// 

#ifndef DFA_CC_
#define DFA_CC_

#include "DFA.h"

#include <iostream>

DFA::DFA() {}

DFA::~DFA() {}

DFA::DFA(std::string sequence, std::string pattern) {
  SetPattern(pattern);
  SetSequence(sequence);
  BuildMachine();
  FindPattern();
}

void DFA::BuildMachine(void) {
  automaton_.resize(0);
  for(unsigned int nodes = 0; nodes < GetPattern().length(); ++nodes) {
    Node* a = new Node {nodes, pattern_[nodes], false};
    automaton_.push_back(a);
  }
  Node* a = new Node {unsigned(GetPattern().length()), ' ', true};
  automaton_.push_back(a);
}

bool DFA::FindPattern(void) {
  unsigned int pos_node = 0;
  for (unsigned int seq_loop = 0; seq_loop < GetSequence().length(); ++seq_loop) {
    if (GetSequence()[seq_loop] == automaton_[pos_node]->transition) {
      if (pos_node == (automaton_.size() - 2)) {
        return true;
      }
      ++pos_node;
    } else {
      pos_node = 0;
    }
  }
  return false;
}

std::string DFA::GetPattern(void) {
  return pattern_;
}

void DFA::SetPattern(std::string& pattern) {
  pattern_ = pattern;
}

std::string DFA::GetSequence(void) {
  return sequence_;
}

void DFA::SetSequence(std::string& sequence) {
  sequence_ = sequence;
}

#endif