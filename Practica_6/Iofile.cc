// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 5 CyA - "Sets"
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

#include <fstream>
#include <iostream>
#include <algorithm>

const std::string kFileExt = ".txt";

IOFile::IOFile() {}

IOFile::IOFile(std::string input, std::string output) {
  /// @brief Constructor of P5
  Set_inputFile(input);
  Set_outputFile(output);
  OutFileSyntaxName();
  std::ofstream output_stream;
  output_stream.open(output);
  if (output_stream.is_open()) {
    Set A;
    for (int i = 1; i <= Count_lines(input); ++i) {
      A.Work(Get_line(Get_inputFile(),i));
      output_stream << Get_line(Get_inputFile(),i) << " = " << A.Write() << std::endl;
    }
  }
  Set B;
  Set C;
  B = "{1, 2}";
  B + 3;
  B.Belong(1);
  B.Clear();
  C == B;
}

IOFile::IOFile(std::string pattern, std::string input, std::string output) {
    /// @brief Constructor of P6
  Set_inputFile(input);
  Set_outputFile(output);
  Set A(Get_line(Get_inputFile(),1), pattern);

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

#endif