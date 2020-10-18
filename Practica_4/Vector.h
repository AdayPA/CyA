#ifndef VECTOR_T_H_
#define VECTOR_T_H_

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

//using namespace std;

//namespace AED {

template <class T>
class vector_t{
private:
	T*      v_;
	int     sz_;

public:

	vector_t(void):
		v_(NULL),
		sz_(0) {}

	vector_t(int sz):
		v_(NULL),
		sz_(sz) {

		crea_vector_t();
	}

	vector_t(const vector_t& v):
	v_(NULL),
	sz_(v.sz_)
	{
		crea_vector_t();

	    for(int i = 0; i < sz_; i++)
	        v_[i] = v.v_[i];
	}

	vector_t& operator=(const vector_t& v)
	{
	    resize(v.sz_);

	    for(int i = 0; i < sz_; i++)
	        v_[i] = v.v_[i];

	     return *this;
	}

	~vector_t(void){

		destruye_vector_t();
	}

	void resize(int sz)
	{
		destruye_vector_t();
		sz_ = sz;
		crea_vector_t();
	}

	int size(void) const
	{
		return sz_;
	}

	const T& at(int pos) const{

		assert((pos < sz_) && ((pos >= 0)));

		return v_[pos];
	}

	T& at(int pos){

		assert((pos < sz_) && ((pos >= 0)));

		return v_[pos];
	}

	const T& operator[](int pos) const {
		return at(pos);
	}

	T& operator[](int pos) {
		return at(pos);
	}

	std::ostream& write(std::ostream& os) const{

	/*	os << setw(5) <<  sz_ << endl;
		os << endl;

		for(int i = 0; i < sz_; i ++){
			v_[i].write(os);
			os << " ";
		}

		return os;*/


		os << setw(8) << sz_ << endl;

		for(int i = 0; i < sz_; i++)
			os << setw(8) << fixed << setprecision(4) << v_[i] << " ";

		os << endl;
	}

	std::istream& read(std::istream& is){

				is >> sz_;

				resize(sz_);

				for(int i = 0; i < sz_; i ++)
				 	is >> v_[i];

				return is;
			}

private:

	void crea_vector_t(void){
		v_ = new T[sz_];
	}

	void destruye_vector_t(void)
	{
		if (v_ != NULL){
			delete [] v_;
			v_ = NULL;
		}
	}

};
//}

#endif /* VECTOR_T_H_ */
