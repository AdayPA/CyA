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
// @brief Traveler.h : This class manipulates files
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

#ifndef PRACTICA_12_Traveler_H_
#define PRACTICA_12_Traveler_H_

#include <string>
#include <vector>

class Traveler {
 public:
  Traveler();
  Traveler(std::string& inputGRA);
  std::string Get_line(const std::string&, const int&);
  std::vector<std::string> Split(std::string, std::string);
  ~Traveler();

 private:
  unsigned int num_cities;  //cuidades totales
  bool directed;            //value para saber si es o no dirigido
  std::vector<std::vector<float>> matrix; //matrix de valores de ciudades
  void Greedy(void);        //algoritmo greedy


  //metodos para manejo de archivos
  void OutputOpenError(void);
  constexpr const int& CountChar(void);
  int Count_lines(const std::string);
  const bool IsDigit(const std::string&);
  void RemoveFile(const char * file_to_remove);
  std::string ClearComments(std::string new_file_name);

};

#endif  // PRACTICA_9_Traveler_H_
