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
//
//
//

#ifndef IOFILE_CC_
#define IOFILE_CC_

#include "Iofile.h"
#include "DFA.h"
#include "Grammar.h"

#include <stdio.h>

#include <fstream>
#include <iostream>
#include <regex>
#include <algorithm>

const std::string kFileExt = ".txt";

IOFile::IOFile() {}

IOFile::~IOFile() {}

IOFile::IOFile(std::string& inputDFA, std::string& outputGRA) {
  // TODO: clear comments
  inputDFA_ = inputDFA;
  outputFile_ = outputGRA;
  DFA A(inputDFA);
  Grammar grammar(A);
  //ReadDFA();
}

void IOFile::ReadDFA(void) {
  DFA A;
  /****************************************************************************
   *
   *        We read the alphabet here and store it in the DFA
   *
  ****************************************************************************/
  int alpha_loop = std::stoi (Get_line(Get_inputDFA(),1));
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
    A.SetAcceptStates(Get_line(Get_inputDFA(),i + current_line));
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


  Grammar grammar(A);

}

void IOFile::OutputOpenError(void) {
  /// @brief If output file got an error, we will notice it
  std::ofstream output_stream;
  output_stream.open("dfa_log_error.txt");
  output_stream << "Error opening the file.";
}

void IOFile::OutFileSyntaxName(void) {
  /// @brief we add the .txt file to the output
  std::string temp_name = Get_outputFile();
  if (temp_name.size() <= 4) {
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
  /// @brief Return the string of the line read.
  std::ifstream inputfile(filename);
  auto temp(1);
  std::string line;
  while ((!(inputfile.eof())) && (temp < line_number)) {
    std::getline(inputfile, line);
    ++temp;
  }
  std::getline(inputfile, line);
  return line;
}

int IOFile::Count_lines(const std::string file) {
  /// @brief Count total lines from a file
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

std::vector<std::string> IOFile::Split(std::string str, std::string delim) {
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

std::string IOFile::ClearComments(std::string new_file_name) {
  std::ofstream output_stream;
  output_stream.open("temp_" + new_file_name);
  std::regex comment("(//.*)");
  // std::regex comment2("(\t+|\s+|\r\n)((\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+)|(.*))");
  // std::regex comment3("/\*(.|\n)*?\*/");
  std::string unused;
  std::ifstream file_to_count(new_file_name);
  while (std::getline(file_to_count, unused)) {
    if (!std::regex_match(unused, comment)) {
      output_stream << unused << std::endl;
    }
  }
  output_stream.close();
  return new_file_name;
}

void IOFile::RemoveFile(const char * file_to_remove) {
  remove(file_to_remove);
}

#endif
