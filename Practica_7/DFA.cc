// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 6 CyA - "Sets"
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
#include <fstream>

DFA::DFA() {
  alpha_ok_ = true;
  complete_ = false;
  alphabet_.resize(0);
  accept_states_.resize(0);
}

DFA::~DFA() {}

void DFA::SetAlphabet (std::string character) {
  //FILTRAR
  alphabet_.push_back(character);

}

void DFA::SetStates (std::string states) {
  //FILTRAR
  states_.push_back(states);
}

void DFA::SetStart (std::string start) {
  //FILTRAR
  start_ = start;
}

void DFA::SetAcceptStates (std::string state) {
  accept_states_.push_back(state);
}

void DFA::SetTransition (std::vector<std::string> transition) {
  Node* a = new Node {transition[0],transition[1],transition[2]};
  transitions_.push_back(a);
}

void DFA::Complete(void) {
  std::vector<Node*> temp_;
  if (transitions_.size() == (states_.size() * alphabet_.size())) {
    complete_ = true;
  } else {
    for (int state_loop = 0; state_loop < states_.size(); ++state_loop ) {
      for (int alpha_loop = 0; alpha_loop < alphabet_.size(); ++alpha_loop) {
        Node* a = new Node {states_.at(state_loop),
                            alphabet_.at(alpha_loop),
                            "Death"};
        temp_.push_back(a);
      }
    }
    int iterator = 0;
    while (iterator < temp_.size() ) {
      for (int i = 0; i < transitions_.size(); ++i) {
        if ((temp_.at(iterator)->init_ == transitions_.at(i)->init_) && 
            (temp_.at(iterator)->alpha_ == transitions_.at(i)->alpha_) ) {
              temp_.erase(temp_.begin() + iterator);
              iterator = 0;
        }
      }
      ++iterator;
    }
    for (int i = 0; i < temp_.size(); ++i) {
      Node* a = new Node {temp_.at(i)->init_,
                          temp_.at(i)->alpha_,
                          "Death"};
      transitions_.push_back(a);
    }
    complete_ =  true;
  }
}

bool DFA::Recon(std::string pattern) {
  //busco transiciones del inicio
  Complete();
  std::vector<int> init;
  for (int i = 0; i < transitions_.size(); ++i) {
    if (start_ == transitions_[i]->init_) {
      init.push_back(i);
    }
  }
  int temp = 0;
  int ptn_position = 0;
  std::string actual_state = start_;
  
  /**
   * 
   *  empiezo por el inicio y veo si se puede iniciar
   * 
  **/

  while (ptn_position < pattern.size()) {
    for (int i = 0; i < transitions_.size(); ++i) {
      std::string temp;
      temp.push_back(pattern.at(ptn_position));
      if ((actual_state == transitions_[i]->init_) && 
          ( temp == transitions_[i]->alpha_ )) {
        actual_state = transitions_[i]->end_;
        break;
      }
    }
    ++ptn_position;
  } // while

  bool trigger = false;

  for (int j = 0; j < accept_states_.size(); ++j) {
    if (actual_state == accept_states_[j]) {
      trigger = true;
    }
  }
  if (trigger) {
    std::cout << "acepta: " << pattern << std::endl;
  } else {
    std::cout << "no acepta: " << pattern << std::endl;
  }
  return trigger;
}

#endif