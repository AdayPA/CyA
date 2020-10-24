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

#include "Iofile.h"
#include "Fibonacci.h"

#include <fstream>
#include <iostream>
#include <algorithm>

const std::string kMessageTrue = " is the word number ";
const std::string kMessageFalse = " is not a Fibonacci word";

IOFile::IOFile() {}

IOFile::IOFile(std::string input, std::string output) {
  Set_inputFile(input);
  Set_outputFile(output);
  std::ofstream output_stream;
  output_stream.open(Get_outputFile());
  Fibonacci fibonacci(Get_line(Get_inputFile(),1), Get_line(Get_inputFile(),2), Count_lines(Get_inputFile()));
  /*
  if (output_stream.is_open()) {
    if (output_stream.good()) {
      for (int file_elements = 1; file_elements <= Count_lines(Get_inputFile()); ++file_elements) {
        if (fibonacci.Is_Fibonacci(Get_line(Get_inputFile(),file_elements),file_elements)) {
          output_stream << Get_line(Get_inputFile(),file_elements) << kMessageTrue << file_elements << std::endl;
        } else {
          output_stream << Get_line(Get_inputFile(),file_elements) << kMessageFalse << std::endl;
        } // third if (fibo)
      } // for
    } // second if (.good)
  } // first if (is_open)
  */
}
  
IOFile::~IOFile() {}

std::string IOFile::Get_line(const std::string& filename, const int& line_number) {
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

int IOFile::Count_lines (const std::string file) {
  int lines = 0;
  std::ifstream file_to_count(file);
  std::string unused;
  while (std::getline(file_to_count,unused)) {
    ++lines;
  }
  return lines;
}

const bool IOFile::IsDigit(const std::string& str){
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

#endif