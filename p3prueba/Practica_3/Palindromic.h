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

#include <set>
#include <string>
#include <thread>
#include <vector>

class Palindromic {
  public:
    Palindromic();
    Palindromic(int digits, std::string output_file);
    ~Palindromic();

  private:
    int numDigits_;
    std::string outputFile_;
    inline void set_outputFile(const std::string& filename) { outputFile_ = filename; };
    inline const std::string& get_outputFile (void) { return outputFile_; };
    inline void set_numDigits(int numDigits) { numDigits_ = numDigits; };
    inline const int& get_numDigits(void) { return numDigits_; };
    std::set<int> my_palindroms;
    inline const int size_my_palindroms(void) {return my_palindroms.size(); };
    inline void set_my_palindroms(int& palindrom) { my_palindroms.insert(palindrom); };
    void FindPalin(void);
    const int MaxNumber(void);
    const int MinNumber(void);
    void Multiply(int origin);
    void Write(void);
};