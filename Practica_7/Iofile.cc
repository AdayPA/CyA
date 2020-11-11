// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 6 CyA - "Sets"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 04/11/2020
// @brief IOFile.cc :  
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

#ifndef IOFILE_CC_
#define IOFILE_CC_

#include "Iofile.h"
#include "Set.h"
#include "DFA.h"

#include <fstream>
#include <iostream>
#include <algorithm>

const std::string kFileExt = ".txt";

IOFile::IOFile() {}

IOFile::IOFile(std::string input, std::string output) {}

IOFile::IOFile(std::string input_dfa, std::string input_txt, std::string output) {
  /// @brief Constructor of P7
  Set_inputDFA(input_dfa);
  Set_inputFile(input_txt);
  Set_outputFile(output);
  OutFileSyntaxName();

  DFA A;

  /****************************************************************************
   * 
   *        We read the alphabet here and store it in the DFA
   * 
  ****************************************************************************/

  int alpha_loop = std::stoi (Get_line(input_dfa,1));
  int current_line = 2;
  for (int i = 0; i < alpha_loop; ++i) {
    A.SetAlphabet(Get_line(Get_inputDFA(),i + current_line));
  }
  current_line = current_line + alpha_loop;

  /****************************************************************************
   * 
   *        We read the states of the DFA here and store it like before
   * 
  ****************************************************************************/
  int states_loop = std::stoi (Get_line(Get_inputDFA(),current_line));
  ++current_line;
  for (int i = 0; i < states_loop; ++i) {
    A.SetStates(Get_line(Get_inputDFA(),i + current_line));
  }
  current_line = current_line + states_loop;
  
  /****************************************************************************
   * 
   *        We read the start node and store it in the DFA
   * 
  ****************************************************************************/
  A.SetStart(Get_line(Get_inputDFA(),current_line));
  ++current_line;

  /****************************************************************************
   * 
   *        We read the accept nodes here
   * 
  ****************************************************************************/
  int accept_loop = std::stoi (Get_line(Get_inputDFA(),current_line));
  ++current_line;
  for (int i = 0; i < accept_loop; ++i) {
    A.SetStates(Get_line(Get_inputDFA(),i + current_line));
  }
  current_line = current_line + accept_loop;

  /****************************************************************************
   * 
   *        We read all the transitions of the DFA here
   * 
  ****************************************************************************/
  int transition_loop = std::stoi (Get_line(Get_inputDFA(),current_line));
  ++current_line;
  for (int i = 0; i < transition_loop; ++i) {
    std::vector<std::string> temp_ = Split(Get_line(Get_inputDFA(),i + current_line), " ");
    A.SetTransition(temp_);
  }


}

IOFile::~IOFile() {}

void IOFile::OutFileSyntaxName(void) {
  std::string temp_name = Get_outputFile();
  if(temp_name.size() <= 4) {
    Set_outputFile(temp_name + kFileExt);
  } else {
    std::string aux;
    for (unsigned int pos = temp_name.size() - 4; pos <= temp_name.size(); ++pos) {
      aux += temp_name[pos];
    }
    aux.resize(4);
    if (!(aux == kFileExt)) {
      Set_outputFile(temp_name + kFileExt);
    }
  }
}

std::string IOFile::Get_line(const std::string& filename, const int& line_number) {
  std::ifstream inputfile(filename);
  auto temp(1);
  std::string line;
  while( (!(inputfile.eof())) && (temp < line_number)) {
    std::getline(inputfile, line);
    ++temp;
  } 
  std::getline(inputfile, line);
  return line;
}

int IOFile::Count_lines(const std::string file) {
  int lines = 0;
  std::ifstream file_to_count(file);
  std::string unused;
  while (std::getline(file_to_count, unused)) {
    ++lines;
  }
  return lines;
}

const bool IOFile::IsDigit(const std::string& str)  {
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

std::vector<std::string> IOFile::Split (std::string str, std::string delim) {
  /// @brief this func split in 2 the string and store them in vector, 
  //         depending of the char
  std::vector<std::string> tokens;
  size_t prev = 0, pos = 0;
  do {
    pos = str.find(delim, prev);
    if (pos == std::string::npos) pos = str.length();
    std::string token = str.substr(prev, pos-prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  }
  while (pos < str.length() && prev < str.length());
  return tokens;
}

#endif