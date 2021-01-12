// University of La Laguna
// College of Engineering and Tech
// Degree of Computer Science
// Subject: Computabilidad y Algoritmia (CyA)
// Course/Year: 2º
// @praxis: Number 12 CyA 
// @author: Aday Padilla Amaya
// @e-mail: alu0100843453@ull.edu.es
// @date: 10/01/2021
// @brief Traveler.cc : This file implement the header
// @compile: $ make
// References:
// Lab exercise:
// (private link)
// Version Control:
// 10/01/2021- First version of the code
//
//
//

#ifndef Traveler_CC_
#define Traveler_CC_

#include "Traveler.h"

#include <stdio.h>

#include <fstream>
#include <iostream>
#include <regex>
#include <algorithm>
#include <set>
#include <limits>
#include <list>

const std::string kFileExt = ".txt";

Traveler::Traveler() {}

Traveler::~Traveler() {}

Traveler::Traveler(std::string& inputGRA) {
  //Leemos el archivo, creamos la matriz y la rellenamos con los datos.

  num_cities = stoi(Get_line(inputGRA,1));
  matrix.resize(num_cities);
  for (unsigned int i = 0; i < num_cities; ++i)
    matrix[i].resize(num_cities);
  directed = stoi(Get_line(inputGRA,2));
  for (unsigned int i = 0; i < num_cities; i++){
    for (unsigned int j = 0; j < num_cities; j++) {
      if ( i == j) {
        matrix.at(i).at(j) = 0;
      } else{
        matrix.at(i).at(j) = -1;
      }
    }
  }
  if (!directed) {
    // como no es dirigido, da igual si la ruta es 1->3 o 3->1, por 
    // lo que copiamos el coste de la ruta en ambos sentidos
    for (int k = 3; k <= Count_lines(inputGRA); k++ ) {
      std::vector<std::string> temp = Split (Get_line(inputGRA,k), " ");
      matrix.at(stoi(temp.at(0))-1).at(stoi(temp.at(1))-1) = stof(temp.at(2));
      matrix.at(stoi(temp.at(1))-1).at(stoi(temp.at(0))-1) = stof(temp.at(2));
    }
  }else{
    // al ser dirigido, añadimos el coste directamente a la ciudad correspondiente
    for (int k = 3; k <= Count_lines(inputGRA); k++ ) {
      std::vector<std::string> temp = Split (Get_line(inputGRA,k), " ");
      matrix.at(stoi(temp.at(0))-1).at(stoi(temp.at(1))-1) = stof(temp.at(2));
    }
  }
  
  std::cout << std::endl;
  for (int i = 0; i < num_cities; i++) {
    for (int j = 0; j < num_cities; j++) {
      std::cout << matrix.at(i).at(j);
    }
    std::cout<< std::endl;
  }
  

  Greedy();

}

void Traveler::Greedy(void) {
  std::set<int> visited;  // ciudades visitadas
  float path1 = 0;
  float path2 = 0;
  int inicio1 = 1;         // cuidad de partida camion 1
  int inicio2 = 3;         // cuidad de partida camion 2
  float max_val1 = 999;
  float max_val2 = 999;
  int temp_city1 = -1;
  int temp_city2 = -1;
  int actual1 = inicio1 -1;
  int actual2 = inicio2 -1;
  bool exist1 = true;
  bool exist2 = true;
  std::list<int> path1_finder1;   // cuidades a la solucion del problema camion 1
  std::list<int> path1_finder2;   // cuidades a la solucion del problema camion 2
  visited.insert(actual1); 
  path1_finder1.push_back(inicio1);
  path1_finder2.push_back(inicio2);
  while (visited.size() != num_cities){ 
    // mientras no halla recorrido todas las ciudades
    for (unsigned int i = 0; i < num_cities; i++) {
      // busco a que ciudades colindantes me puedo mover
      const bool is_in = visited.find(i) != visited.end();
      if ((matrix.at(i).at(actual1) != -1) && (matrix.at(i).at(actual1) != 0) && (!is_in) && (matrix.at(i).at(actual1) < max_val1) && exist1) {
        // si la ciudad no ha sido visitada, no es la ciudad en la que estoy y el coste es menor, sera mi nuevo minimo temporal
        // hasta que compruebe todas ellas
        temp_city1  = i + 1;
        max_val1 = matrix.at(i).at(actual1);
      }
    }
    // recorrido para el segundo camion
    for (unsigned int i = num_cities; i == 0; i--) {
      const bool is_in = visited.find(i) != visited.end();
      if ((matrix.at(i).at(actual2) != -1) && (matrix.at(i).at(actual2) != 0) && (!is_in) && (matrix.at(i).at(actual2) < max_val2) && exist2) {
        temp_city2  = i + 1;
        max_val2 = matrix.at(i).at(actual2);
      }
    }
    if(max_val1 == 999){
      // Si se da el caso de que no hay camino posible, no saco por pantalla 
      std::cout << "No hay caminopara recorrer todas las ciudades" << std::endl;
      exist1 = false;
      max_val1 = 0;
      temp_city1++;
      //break;
    } 
    if(max_val2 == 999){
      // Si se da el caso de que no hay camino posible, no saco por pantalla
      std::cout << "No hay camino posible para recorrer todas las ciudades" << std::endl;
      exist2 = false;
      max_val2 = 0;
      temp_city2++;
     // break;
    }
    // ahora ya se a que ciudad moverme, asi que sumo el coste y la guardo para el recorrido y actualizo como ciudad visitada
    path1 += max_val1;
    path2 += max_val2;
    path1_finder1.push_back(temp_city1);
    path1_finder2.push_back(temp_city2);
    max_val1 = 999;
    max_val2 = 999;
    actual1 = temp_city1 -1;
    actual2 = temp_city2 -1;
    visited.insert(temp_city1-1);
    visited.insert(temp_city2-1);
  }
  std::cout << "Coste del camino 1: " << path1 << std::endl;
  std::cout << "Recorrido de las ciudades camino 1: "  ;
  for (int x : path1_finder1) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  std::cout << "Coste del camino 2: " << path2 << std::endl;
  std::cout << "Recorrido de las ciudades camino 2: ";
  for (int x : path1_finder2) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  std::cout << "Coste total: " << path2 + path1<< std::endl;

}

void Traveler::OutputOpenError(void) {
  /// @brief If output file got an error, we will notice it
  std::ofstream output_stream;
  output_stream.open("dfa_log_error.txt");
  output_stream << "Error opening the file.";
}

std::string Traveler::Get_line(const std::string& filename, const int& line_number) {
  /// @brief Return the string of the line read.
  std::ifstream inputfile(filename);
  auto temp(1);
  std::string line;
  while ((!(inputfile.eof())) && (temp < line_number)) {
    std::getline(inputfile, line);
    ++temp;
  }
  std::getline(inputfile, line);
  return line;
}

int Traveler::Count_lines(const std::string file) {
  /// @brief Count total lines from a file
  int lines = 0;
  std::ifstream file_to_count(file);
  std::string unused;
  while (std::getline(file_to_count, unused)) {
    ++lines;
  }
  return lines;
}

const bool Traveler::IsDigit(const std::string& str)  {
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

std::vector<std::string> Traveler::Split(std::string str, std::string delim) {
  /// @brief this func split in 2 the string and store them in vector,
  //         depending of the char
  std::vector<std::string> tokens;
  size_t prev = 0, pos = 0;
  do {
    pos = str.find(delim, prev);
    if (pos == std::string::npos) pos = str.length();
    std::string token = str.substr(prev, pos-prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  }
  while (pos < str.length() && prev < str.length());
  return tokens;
}

std::string Traveler::ClearComments(std::string new_file_name) {
  std::ofstream output_stream;
  output_stream.open("temp_" + new_file_name);
  std::regex comment("(//.*)");
  // std::regex comment2("(\t+|\s+|\r\n)((\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+)|(.*))");
  // std::regex comment3("/\*(.|\n)*?\*/");
  std::string unused;
  std::ifstream file_to_count(new_file_name);
  while (std::getline(file_to_count, unused)) {
    if (!std::regex_match(unused, comment)) {
      output_stream << unused << std::endl;
    }
  }
  output_stream.close();
  return new_file_name;
}

void Traveler::RemoveFile(const char * file_to_remove) {
  remove(file_to_remove);
}

#endif
