// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 2 CyA - La criba de Eratóstenes
// Autor: Aday Padilla Amaya
// Correo: alu0100843453@ull.edu.es
// Fecha: 07/10/2020
// Archivo Aritmetica:   Contiene la clase Aritmetica, el cual aplica el algoritmo de Eratóstenes para hallar los numeros primos.
                       
#include <vector>
#include <tuple>


class Aritmetica {
public:
  Aritmetica(void);
  Aritmetica(int numPrimos);
  ~Aritmetica();
   
private:
  int numPrimos_;
  inline void set_numPrimos(int numPrimos) { numPrimos_ = numPrimos; };
  inline int get_numPrimos(void) { return numPrimos_; };
  std::vector<bool> vectorPrimos_;
  inline void set_vectorPrimos(int pos_, bool boolean_) { vectorPrimos_[pos_] = boolean_; };
  inline bool get_vectorPrimos(int pos_) { return vectorPrimos_[pos_]; };
  void siege(void);
  void remove(int iter_);
  void imprimir(void);
};