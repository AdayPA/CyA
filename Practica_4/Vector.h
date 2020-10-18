#ifndef VECTOR_H_
#define VECTOR_H_

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

//using namespace std;

template <class T>
class Vector {
    
    private:
        T* vector;
        int sz;
        
    public:
        Vector();
        Vector(int);
        ~Vector();
        void resize(int);
        int get_sz(void) const;
        T get_v(int pos) const;
        T& get_set_v(int pos);
        void crea_vector(void);
        void destruye_vector(void);
        std::ostream& write(std::ostream& os) const;
};

#endif /* VECTOR_H_ */

