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

#include "Iofile.h"
#include "Fibonacci.h"

#include <fstream>
#include <iostream>

IOFile::IOFile() {}

IOFile::IOFile(std::string input, std::string output) {
  set_inputFile(input);
  set_outputFile(output);
  Fibonacci fibonacci(get_line(get_inputFile(),1), get_line(get_inputFile(),2), count_lines(get_inputFile()));
  
}

IOFile::~IOFile() {}

std::string IOFile::get_line(const std::string filename, const int& line_number) {
  std::ifstream inputfile(filename);
  auto temp(1);
  std::string line;
  while((!(inputfile.eof())) && (temp < line_number)) {
    std::getline(inputfile,line);
    ++temp;
  }; 
  std::getline(inputfile,line);
  return line;
}

int IOFile::count_lines (const std::string file){
  int lines = 0;
  std::ifstream file_to_count(file);
  std::string unused;
  while (std::getline(file_to_count,unused)) {
    ++lines;
  }
  return lines;
}

#endif