// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º 
// @praxis: Number 5 CyA - ""
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 26/11/2020
// @brief ./.cc:  
// 
// @compile: $ make                                                    
// References: 
// 
// Lab exercise:
// 
// Version Control:
// 26/10/2020 - First version of the code 
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
  Set_inputFile(input);
  Set_outputFile(output);
  OutFileSyntaxName();
  Set A;
  A.Work(Get_line(Get_inputFile(),1));
  //Set B;
  //B >> Get_line(Get_inputFile(),1);
  

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