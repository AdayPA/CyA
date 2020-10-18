// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 2 CyA - La criba de Eratóstenes
// Autor: Aday Padilla Amaya
// Correo: alu0100843453@ull.edu.es
// Fecha: 07/10/2020
// Archivo erathostenes: Contiene las directrices básicas de ejecución del proyecto
//                       Dado un numero entero N, leído desde la línea de comandos, 
//                       el programa imprime los valores primos hasta N. 
//                       Para ello utiliza el algoritmo de Eratóstenes contenido en 
//                       la clase Aritmetica.
//                       
// Referencias: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// Enunciado de la práctica: https://github.com/fsande/CyA-P02-Eratosthenes/blob/master/Eratosthenes.md
// Historial de revisiones:
// 07/10/2020 - Creación (primera versión) del código
// 11/10/2020 - Modificación de la salida por pantalla

#include "Aritmetica.h"

#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <stdlib.h>  // for strtol

#include <iostream>

int main(int argc, char** argv) { 

  char *p = {};
  int num = -1;
  errno = 0;
  long conv = strtol(argv[1], &p, 10);

  // Filtramos la entrada
    if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < 0) {
    std::cout << "Has introducido numero incorrecto" << std::endl;
  } else if (conv == 1 || conv == 0) {
    std::cout << "El número " << conv << " no es primo" << std::endl; 
  } else if (conv == 2) {
    std::cout << "El número 1 no es primo" << std::endl;
    std::cout << "El número 2 es primo" << std::endl;
  } else {
    num = conv;    
    std::cout << "Has introducido el numero: " << num << std::endl;
    Aritmetica primos(num);
  }
  return 0;
};