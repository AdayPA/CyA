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
#include <thread>

#include <pthread.h>

const int kBASE = 10;

Palindromic::Palindromic() {}

Palindromic::Palindromic(int digits, std::string output_file) {
  set_numDigits(digits);
  set_outputFile(output_file);
  FindPalin();
  //Write();
}

Palindromic::~Palindromic() {}

void Palindromic::FindPalin(void) {
  std::ofstream outputfile;
  outputfile.open(get_outputFile());
  std::cout << "Maximo: " << MaxNumber() << std::endl;
  std::cout << "Minimo: " << MinNumber() << std::endl;
  for (int multiplicand = MinNumber(); multiplicand <= MaxNumber(); multiplicand++ ){
    for (int multiplier = MinNumber(); multiplier <= MaxNumber(); multiplier++ ){
      int result, aux_result, digit, rev_result = 0;
      result = multiplicand * multiplier;
      aux_result = result;
      do {
         digit = result % kBASE;
         rev_result = (rev_result * kBASE) + digit;
         result = result / kBASE;
      } while (result != 0);
      if (aux_result == rev_result) {
        outputfile << rev_result << " = " << multiplicand << " * " << multiplier << std::endl;
      }
    }
  }
  //std::cout << "tamaño:" << size_my_palindroms() << std::endl;
  
  
  /*std::thread thread_one(&Palindromic::Multiply,this,0);
  std::thread thread_two(&Palindromic::Multiply,this,1);
  thread_one.join();
  thread_two.join();*/
}

void Palindromic::Multiply (int origin){
  //std::cout << "Maximo: " << MaxNumber() << std::endl;
  //std::cout << "Minimo: " << MinNumber() << std::endl;
  std::ofstream outputfile;
  outputfile.open(get_outputFile());
  for (int multiplicand = MinNumber() + origin ; multiplicand <= MaxNumber(); multiplicand += 2){
    for (int multiplier = MinNumber(); multiplier <= MaxNumber(); multiplier++ ){
      int result, aux_result, digit, rev_result = 0;
      result = multiplicand * multiplier;
      aux_result = result;
      do {
         digit = result % kBASE;
         rev_result = (rev_result * kBASE) + digit;
         result = result / kBASE;
      } while (result != 0);
      if (aux_result == rev_result) {
        //outputfile << *it << std::endl;
        outputfile << rev_result << " = " << multiplicand << " * " << multiplier << std::endl;
        //set_my_palindroms(rev_result);
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
  outputfile << "Total numbers of palindroms: " << size_my_palindroms() << std::endl;
  for (std::set<int>::iterator it = my_palindroms.begin(); it != my_palindroms.end(); ++it) {
    outputfile << *it << std::endl;
  }
  outputfile.close();
}