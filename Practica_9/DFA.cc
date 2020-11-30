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

#ifndef PRACTICA_9_DFA_CC_
#define PRACTICA_9_DFA_CC_

#include "DFA.h"

#include <iostream>
#include <fstream>
#include "Iofile.h"

DFA::DFA() {
  /// @brief we set the bools to false as init
  start_ok_ = false;
  accept_states_ok_ = false;
  transitions_ok = false;
  failed_ = false;
  complete_ = false;
}


DFA::DFA(std::string input_dfa) {
  /// @brief we set the bools to false as init
  start_ok_ = false;
  accept_states_ok_ = false;
  transitions_ok = false;
  failed_ = false;
  complete_ = false;
  IOFile test;

  /****************************************************************************
   *
   *        We read the alphabet here and store it in the DFA
   *
  ****************************************************************************/
  int alpha_loop = std::stoi(test.Get_line(input_dfa, 1));
  int current_line = 2;
  for (int i = 0; i < alpha_loop; ++i) {
    SetAlphabet(test.Get_line(input_dfa, i + current_line));
  }
  current_line = current_line + alpha_loop;

  /****************************************************************************
   *
   *        We read the states of the DFA here and store it like before
   *
  ****************************************************************************/
  int states_loop = std::stoi(test.Get_line(input_dfa, current_line));
  ++current_line;
  for (int i = 0; i < states_loop; ++i) {
    SetStates(test.Get_line(input_dfa, i + current_line));
  }
  current_line = current_line + states_loop;

  /****************************************************************************
   *
   *        We read the start node and store it in the DFA
   *
  ****************************************************************************/
  SetStart(test.Get_line(input_dfa, current_line));
  ++current_line;

  /****************************************************************************
   *
   *        We read the accept nodes here
   *
  ****************************************************************************/
  int accept_loop = std::stoi(test.Get_line(input_dfa, current_line));
  ++current_line;
  for (int i = 0; i < accept_loop; ++i) {
    SetAcceptStates(test.Get_line(input_dfa, i + current_line));
  }
  current_line = current_line + accept_loop;

  /****************************************************************************
   * 
   *        We read all the transitions of the DFA here
   * 
  ****************************************************************************/
  int transition_loop = std::stoi(test.Get_line(input_dfa, current_line));
  ++current_line;
  for (int i = 0; i < transition_loop; ++i) {
    std::vector<std::string> temp_ = test.Split(test.Get_line(input_dfa, i + current_line), " ");
    SetTransition(temp_);
  }
}

DFA::~DFA() {}

void DFA::SetAlphabet(std::string character) {
  alphabet_.insert(character);
}

void DFA::SetStates(std::string states) {
  states_.insert(states);
}

void DFA::SetStart(std::string start) {
  /// @brief if start state belong to state, we add it
  const bool is_in = states_.find(start) != states_.end();
  if (is_in) {
    start_ = start;
    start_ok_ = true;
  } else {
    start_ok_ = false;
    failed_ = true;
  }
}

void DFA::SetAcceptStates(std::string state) {
  /// @brief if start state belong to the set of states, we add it
  const bool is_in = states_.find(state) != states_.end();
  if (is_in) {
    accept_states_.insert(state);
    accept_states_ok_ = true;
  } else {
    accept_states_ok_ = false;
    failed_ = true;
  }
}

void DFA::SetTransition(std::vector<std::string> transition) {
  const bool is_in_init_state = states_.find(transition[0]) != states_.end();
  const bool is_in_symbol = alphabet_.find(transition[1]) != alphabet_.end();
  const bool is_in_final_state = states_.find(transition[2]) != states_.end();
  if (is_in_init_state && is_in_symbol && is_in_final_state) {
    transitions_.Insert(transition[0], transition[1], transition[2]);
    transitions_ok = true;
  } else {
    transitions_ok = false;
    failed_ = true;
  }
}

Grammar DFA::ConvertToGrammar(void) {
  Grammar grammar;
  grammar.SetAlphabet(alphabet_);
  grammar.SetStates(states_);
  grammar.SetAcceptStates(accept_states_);
  grammar.SetStart(start_);
  for (int i = 0; i < transitions_.GetSize(); ++i) {
    grammar.SetProduccion(transitions_.GetNode(i)->init_state_,
                         transitions_.GetNode(i)->symbol_,
                         transitions_.GetNode(i)->final_state_);

    std::cout << transitions_.GetNode(i)->init_state_ << " -> " <<
    transitions_.GetNode(i)->symbol_ << transitions_.GetNode(i)->final_state_
    << std::endl;
    std::string temp = transitions_.GetNode(i)->final_state_;
    const bool is_in_accept = accept_states_.find(temp) != accept_states_.end();
    if (is_in_accept) {
      grammar.SetProduccion(transitions_.GetNode(i)->final_state_,
                         "", "ε");
      std::cout << transitions_.GetNode(i)->final_state_ << " -> " <<
    "" << "ε" << std::endl;
    }
  }
  return grammar;
}

#endif  // PRACTICA_9_DFA_CC_
