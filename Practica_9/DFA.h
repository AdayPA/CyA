// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 7 CyA - "DFA"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 04/11/2020
// @brief DFA.cc :  This class store the tuple needed to describe a DFA 
//                  and works with string to recognize them
//                 
// @compile: $ make                                                    
// References: 
// https://en.wikipedia.org/wiki/Deterministic_finite_automaton
// Lab exercise:
// (private link)
// Others links:
//  https://stackoverflow.com/questions/14975737/regular-expression-to-remove-comment
//  https://regexr.com/5gecl
// Version Control:
// 11/11/2020 - First version of the code 
// 13/11/2020 - core added
// 15/11/2020 - recognition added
//

#ifndef DFA_H_
#define DFA_H_

#include "Set.h"

#include <string>
#include <vector>

class DFA {
  private:
    struct Node {
      std::string init_;
      std::string alpha_;
      std::string end_;
    };

  public:
    DFA();
    ~DFA();
    void SetAlphabet (std::string);
    void SetStates (std::string);
    void SetStart (std::string);
    void SetAcceptStates (std::string);
    void SetTransition (std::vector<std::string>);
    int Recon(std::string);

  private:
    Set dfa_set;
    std::vector<std::string> alphabet_;
    std::vector<std::string> states_;
    bool failed_;
    bool start_ok_;
    std::string start_;
    bool accept_states_ok_;
    std::vector<std::string> accept_states_;
    bool transitions_ok;
    std::vector<Node*> transitions_;
    bool complete_;
    bool CheckStatus(void);
    void Complete(void);
};

#endif //DFA_H_