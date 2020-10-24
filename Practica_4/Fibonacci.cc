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
// 22/10/2020 - The core is done
// 23/10/2020 - Added IOFile
// 24/10/2020 - Added functionalities and output is good

#ifndef IOFILE_CC_
#define IOFILE_CC_

#include "Fibonacci.h"

#include <iostream>
#include <algorithm>

Fibonacci::Fibonacci() {}

Fibonacci::Fibonacci(std::string first, std::string second, int iterations) {
  Set_firstElement(first), Set_secondElement(second);
  Set_fibonacciIterations(iterations);
  DoFibonacci();
 }

Fibonacci::~Fibonacci() {}

void Fibonacci::DoFibonacci(void) {
  if ( !((IsDigit(Get_firstElement())) && (IsDigit(Get_secondElement()))) ) {
    std::string temp_first_element = Get_firstElement();
    std::string temp_second_element = Get_secondElement();
    std::string aux;
    fibonacci_string_Serie.push_back(temp_first_element), fibonacci_string_Serie.push_back(temp_second_element);
    for (int i = 0; i < Get_fibonacciIterations(); ++i) {
      aux = temp_first_element + temp_second_element;
      temp_first_element = temp_second_element;
      temp_second_element = aux;
      fibonacci_string_Serie.push_back(aux);
    }
  } else {
    int temp_first_element = std::stoi (Get_firstElement(),nullptr,0);
    int temp_second_element = std::stoi (Get_secondElement(),nullptr,0);
    int aux;
    fibonacci_int_Serie.push_back(temp_first_element), fibonacci_int_Serie.push_back(temp_second_element);
    for (int i = 0; i < Get_fibonacciIterations(); ++i) {
      aux = temp_first_element + temp_second_element;
      temp_first_element = temp_second_element;
      temp_second_element = aux;
      fibonacci_int_Serie.push_back(aux);
    }
  }
}

bool Fibonacci::Is_Fibonacci(const std::string& element, const int& position) const {
  if (element == fibonacci_string_Serie.at(position-1))
    return true;
  else if ( std::stoi(element,nullptr,0) == fibonacci_int_Serie.at(position-1))
    return true;
  else
    return false;
}

const bool Fibonacci::IsDigit(const std::string& str){
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

#endif