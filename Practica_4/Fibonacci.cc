// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 4 CyA - "Palabras de Fibonacci"
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 21/11/2020
// @brief ./fibonacci_words.cc:  
//         
// @compile: $ make                                                    
// References: 
// https://en.wikipedia.org/wiki/Fibonacci_sequence
// Lab exercise:
// https://github.com/fsande/CyA-P04-FibonacciWords/blob/master/FibonacciWords.md
// Version Control:
// 21/10/2020 - First version of the code 

#ifndef IOFILE_CC_
#define IOFILE_CC_

#include "Fibonacci.h"

#include <iostream>


Fibonacci::Fibonacci() {}

Fibonacci::Fibonacci(std::string first, std::string second, int iterations) {
  set_firstElement(first), set_secondElement(second);
  set_fibonacciIterations(iterations);
  doFibonacci();
  
 }

Fibonacci::~Fibonacci() {}

void Fibonacci::doFibonacci(void){
  std::string temp_first_element = get_firstElement();
  std::string temp_second_element = get_secondElement();
  std::string aux;
  fibonacciSerie.push_back(temp_first_element), fibonacciSerie.push_back(temp_second_element);
  for (int i = 0; i < get_fibonacciIterations(); ++i){
    aux = temp_first_element + temp_second_element;
    temp_first_element = temp_second_element;
    temp_second_element = aux;
    fibonacciSerie.push_back(aux);
  }
}

bool Fibonacci::is_Fibonacci(const std::string& element, const int& position) const {
  if (element == fibonacciSerie.at(position))
    return true;
  else
    return false;
}

#endif 