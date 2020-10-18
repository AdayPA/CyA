// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 3 CyA - Productos capicúa
// Autor: Aday Padilla Amaya
// Correo: alu0100843453@ull.edu.es
// Fecha: 14/11/2020
// Archivo palindrome_prod.cc: Contiene las directrices básicas de ejecución del proyecto
//                             Dado dado un número entero n > 0, encuentra los números capicúas 
//                             resultantes de multiplicar dos números de n dígitos cada uno, 
//                             almacenándolos en un fichero de texto.
//                      
//                      
//                      
// Referencias: 
// https://es.wikipedia.org/wiki/Capic%C3%BAa#:~:text=En%20matem%C3%A1ticas%2C%20la%20palabra%20capic%C3%BAa,%2C%202882%2C%202442%2C%209102019.
// Enunciado de la práctica:
// https://github.com/fsande/CyA-P03-ProductosCapicua/blob/master/ProductosCapicua.md
// Historial de revisiones
// 14/10/2020 - Creación (primera versión) del código

#include "Palindromic.h"

#include <iostream>
#include <fstream>

#include <time.h>

const int kBASE = 10;
const std::string kErrFilName = "error_file";
const std::string kMSymbol = " * ";
const std::string kEqualSymbol = " = ";

Palindromic::Palindromic() {}

Palindromic::Palindromic(int digits, std::string output_file) {
  set_numDigits(digits);
  set_outputFile(output_file);
  FindPalin();
  Write();
}

Palindromic::~Palindromic() {}

void Palindromic::FindPalin(void) {
  for (int multiplicand = MinNumber(); multiplicand <= MaxNumber(); multiplicand++) {
    for (int multiplier = MinNumber(); multiplier <= MaxNumber(); multiplier++) {
      int result, aux_result, digit, rev_result = 0;
      result = multiplicand * multiplier;
      aux_result = result;
      do {
        digit = result % kBASE;
        rev_result = (rev_result * kBASE) + digit;
        result = result / kBASE;
      } while (result != 0);
      if (aux_result == rev_result) {
        my_palindroms.push_back(std::make_tuple(rev_result,multiplicand,multiplier));
      }
    }
  }
}

const int Palindromic::MaxNumber(void) {
  int num_digit = get_numDigits();
  int min_num = 1;
  while (num_digit != 0) { 
    num_digit = num_digit - 1; 
    min_num = min_num * kBASE; 
  }
  return min_num - 1;
}

const int Palindromic::MinNumber(void) {
  int num_digit = get_numDigits() - 1;
  int max_num = 1;
  while (num_digit != 0) { 
    num_digit = num_digit - 1; 
    max_num = max_num * kBASE; 
  }
  return max_num;
}

void Palindromic::Write(void) {
  std::ofstream outputfile;
  outputfile.open(get_outputFile());
  if(outputfile.is_open()) {
    if(outputfile.good()) {
      outputfile << "Total numbers of palindroms: " << my_palindroms.size() 
      << std::endl;
      for(const auto &i : my_palindroms)
        outputfile << std::get<0>(i) << kEqualSymbol << std::get<1>(i) 
        << kMSymbol << std::get<2>(i) << std::endl;
    }
    outputfile.close();
  } else {
    std::ofstream err_file;
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    err_file.open(kErrFilName);
    if(err_file.is_open()) {
      if(err_file.good()) {
        err_file << "Report of execution command at " << asctime(timeinfo);
        err_file << "Error occurred saving the palindorms result of N = " << get_numDigits() << "." << std::endl;
        err_file << "Error opening the file.";
      }
    }
    err_file.close();
  }
}