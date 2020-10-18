// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 2 CyA - La criba de Eratóstenes
// Autor: Aday Padilla Amaya
// Correo: alu0100843453@ull.edu.es
// Fecha: 07/10/2020
// Archivo Aritmetica:  Contiene la clase Aritmetica, el cual aplica el 
//                      algoritmo de Eratóstenes para hallar los numeros 
//                      primos.



#include "Aritmetica.h"

#include <math.h>

#include <iostream>


Aritmetica::Aritmetica(){}

Aritmetica::Aritmetica(int numPrimos) {
  // Iniciamos el vector de booleanos, con todos los valores a true por 
  // defecto.
  set_numPrimos(numPrimos);
  for (int i=0; i<numPrimos; i++) {
    vectorPrimos_.push_back(true);
  }
  siege();
  imprimir();
}

Aritmetica::~Aritmetica() {}

void Aritmetica::imprimir(void) {
  // Imprimimos los números primos, que son los que tiene el valor true en el
  // vector booleano y despues los no primos con el valor false, de esta forma
  // es más comodo la visualizacion del resultado en la consola
  std::cout << "Los números primos son: " << std::endl;
  std::cout << "--------------------------- " << std::endl;
  int temp2_ = 1;
  for (auto i = (vectorPrimos_.begin()+2); i != vectorPrimos_.end(); ++i) { 
    temp2_++;
    if (*i == true) {
      std::cout << temp2_ << " ";
    }
  }
  std::cout << std::endl;
  std::cout << "\nLos números no primos son: " << std::endl;
  std::cout << "--------------------------- " << std::endl;
  std::cout << "0 1 ";
  int temp3_ = 1;
  for (auto i = (vectorPrimos_.begin()+2); i != vectorPrimos_.end(); ++i) { 
    temp3_++;
    if (*i == false) {
      std::cout << temp3_ << " ";
    }
  }
  std::cout << std::endl;
}

void Aritmetica::siege(void) {
  // Marca los no primos de la lista hasta raiz de n (el valor que se le ingresa 
  // por consola) e invoca a la función remove. Para mas detalle observar el 
  // pseudocódigo de las referencias.
  int temp_ = floor(sqrt(get_numPrimos()));
  for (int i = 2; i <= temp_; i++) {
    if (get_vectorPrimos(i)) {
      remove(i);
    }
  }
}

void Aritmetica::remove(int iter_) {
  // Marcamos como false en el vector de booleanos a los no primos.
  int temp_ = pow(iter_,2);
  for (int j = temp_; j <= get_numPrimos(); j += iter_) 
    set_vectorPrimos(j,false);
}

