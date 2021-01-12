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
// @brief Traveler.cc : This file implement the header
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

#ifndef Traveler_CC_
#define Traveler_CC_

#include "Traveler.h"

#include <stdio.h>

#include <fstream>
#include <iostream>
#include <regex>
#include <algorithm>
#include <set>
#include <limits>
#include <list>

const std::string kFileExt = ".txt";

Traveler::Traveler() {}

Traveler::~Traveler() {}

Traveler::Traveler(std::string& inputGRA) {
  num_cities = stoi(Get_line(inputGRA,1));
  matrix.resize(num_cities);
  for (int i = 0; i < num_cities; ++i)
    matrix[i].resize(num_cities);
  directed = stoi(Get_line(inputGRA,2));
  for (int i = 0; i < num_cities; i++){
    for (int j = 0; j < num_cities; j++) {
      if ( i == j) {
        matrix.at(i).at(j) = 0;
      } else{
        matrix.at(i).at(j) = -1;
      }
    }
  }
   std::cout << std::endl;
  if (!directed) {
    for (int k = 3; k <= Count_lines(inputGRA); k++ ) {
      std::vector<std::string> temp = Split (Get_line(inputGRA,k), " ");
      matrix.at(stoi(temp.at(0))-1).at(stoi(temp.at(1))-1) = stof(temp.at(2));
      matrix.at(stoi(temp.at(1))-1).at(stoi(temp.at(0))-1) = stof(temp.at(2));
    }
  }else{
    for (int k = 3; k <= Count_lines(inputGRA); k++ ) {
      std::vector<std::string> temp = Split (Get_line(inputGRA,k), " ");
      matrix.at(stoi(temp.at(0))-1).at(stoi(temp.at(1))-1) = stof(temp.at(2));
    }
  }
  std::cout << std::endl;
  for (int i = 0; i < num_cities; i++) {
    for (int j = 0; j < num_cities; j++) {
      std::cout << matrix.at(i).at(j);
    }
    std::cout<< std::endl;
  }

  Greedy();

}

void Traveler::Greedy(void) {
  std::set<int> visited;
  float path = 0;
  int inicio = 1;
  float max_val = 999;
  int temp_city = -1;
  int actual = inicio -1;
  std::list<int> path_finder;
  visited.insert(actual);
  path_finder.push_back(inicio);
  while (visited.size() != num_cities){
    for (int i = 0; i < num_cities; i++) {
      const bool is_in = visited.find(i) != visited.end();
      if ((matrix.at(i).at(actual) != -1) && (matrix.at(i).at(actual) != 0) && (!is_in) && (matrix.at(i).at(actual) < max_val) ) {
        temp_city  = i + 1;
        max_val = matrix.at(i).at(actual);
        std::cout << max_val << std::endl;
      }
    }
    if(max_val == 999){
      std::cout << "No hay camino" ;
      break;
    }
    path += max_val;
    std::cout << "voy a: " << temp_city <<" con coste:"<< max_val << std::endl;
    path_finder.push_back(temp_city);
    max_val = 999;
    actual = temp_city -1;
    visited.insert(temp_city-1);
  }
  std::cout<< std::endl;
  std::cout << "Coste del camino: " << path << std::endl;
  std::cout << "Recorrido de las ciudades: ";
  for (int x : path_finder) {
    std::cout << x << " ";
  }
}

void Traveler::OutputOpenError(void) {
  /// @brief If output file got an error, we will notice it
  std::ofstream output_stream;
  output_stream.open("dfa_log_error.txt");
  output_stream << "Error opening the file.";
}

std::string Traveler::Get_line(const std::string& filename, const int& line_number) {
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

int Traveler::Count_lines(const std::string file) {
  /// @brief Count total lines from a file
  int lines = 0;
  std::ifstream file_to_count(file);
  std::string unused;
  while (std::getline(file_to_count, unused)) {
    ++lines;
  }
  return lines;
}

const bool Traveler::IsDigit(const std::string& str)  {
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

std::vector<std::string> Traveler::Split(std::string str, std::string delim) {
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

std::string Traveler::ClearComments(std::string new_file_name) {
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

void Traveler::RemoveFile(const char * file_to_remove) {
  remove(file_to_remove);
}

#endif
