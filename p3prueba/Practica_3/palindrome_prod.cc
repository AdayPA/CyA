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

#include "Palindromic.cc"

#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <stdlib.h>  // for strtol

#include <cstdlib>
#include <iostream>   // std::cout
#include <string>

#include <thread>

const int kFILE_IN = 1;
const int kFILE_OUT = 2;
const int kFIRST = 1;
const int kSECOND = 2;
const int kTHIRD = 3;
//const int kBASE = 10;
const int kMINIMUN = 1;
const char kEMPTY = '\0';
const std::string kEXPLAIN = "--help";


/**
 ** Función declarada que retorna al comando "./palindrome_prod --help" un breve
 ** texto explicativo del funcionamiento del programa.
 */
void Help(void) {
  std::cout << "Modo de empleo: ./G2CNF input.gra output.gra" << std::endl;
}

void BadImput (void){
  std::cout << "Usage: ./palindrome_prod Number_of_Digits" << std::endl;
  std::cout << "Try: './palindrome_prod --help' for more information." << std::endl;
}

int main(int argc, char** argv) {
  switch (argc) {
    case kFIRST:	 {
      BadImput();
      break;
	  }	
    case kSECOND:	{
      std::string input_file = argv[kFILE_IN];
      if (input_file == kEXPLAIN) {
        Help();
      } else {
        BadImput();
      }
       break;
    }
    case kTHIRD: {
      std::string output_file(argv[kFILE_OUT]);
      char *aux_char = {};
      long digit = strtol(argv[1], &aux_char, kBASE);
      if ( *aux_char != kEMPTY || digit > INT_MAX || digit < kMINIMUN ) {
        BadImput();
      } else {
        int numCPU = sysconf(_SC_NPROCESSORS_ONLN);
        //Palindromic capicua(digit, output_file);
      }
      break;
    }
    default: {
      BadImput();
      break;
    }
  }
  return 0;
}