
#include "Vector.h"

template <class T>
Vector<T>::Vector(){
    vector = NULL;
    sz = 0;
}

template <class T>
Vector<T>::Vector(int size){
    vector = NULL;
    sz = size;
    
    crea_vector();
}

template <class T>
Vector<T>::~Vector(void){
    destruye_vector();
}

template <class T>
void Vector<T>::crea_vector(void){
    vector = new T[sz];
}

template <class T>
void Vector<T>::destruye_vector(void){
    if(vector != NULL){
        delete [] vector;
        vector = NULL;
    }
}

template <class T>
void Vector<T>::resize(int size){
    destruye_vector();
    sz = size;
    crea_vector();
}

template <class T>
int Vector<T>::get_sz(void) const{
    return sz;
}

template <class T>
T Vector<T>::get_v(int pos) const{
    assert((pos < sz) && (pos >= 0));
    return (vector[pos]);            
}

template <class T>
T& Vector<T>::get_set_v(int pos){
    assert((pos < sz) && (pos >= 0));
    return (vector[pos]);            
}

template <class T>
std::ostream& Vector<T>::write(std::ostream& os) const{
	
    for(int i = 0; i < sz; i ++)
        os << vector[i] << " ";
        return os;
}

template class Vector<int>;
template class Vector<float>;
template class Vector<double>;
template class Vector<char>;

