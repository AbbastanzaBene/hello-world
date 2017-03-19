#include <stdexcept> 
#include "vector.h"
using namespace std;
	/*Konstruktoren */
	Vector::Vector() : max_sz(0), sz(0), values(nullptr) {}
	Vector::Vector(size_t max_sz) : max_sz{max_sz}, sz(0), values(max_sz>0?new double[max_sz]:nullptr) {} 
	Vector::Vector(std::initializer_list<double> il) {  
		values = il.size()>0?new double[il.size()]:nullptr;
		max_sz = il.size();
		sz = 0;
		for (const auto& elem : il) values[sz++] = elem;  /* Range-based-For-Loop, auto statt double, falls irgendwann auch andere werte zugelassen werden */ 
	}
	/* Kopierkonstruktor */
	Vector::Vector(const Vector& original) {
		max_sz = original.max_sz;
		sz = original.sz;
		values = max_sz>0?new double[max_sz]:nullptr;
		for (size_t i(0); i<sz; ++i) values[i]=original.values[i];
 	}
	/*Dekonstruktor */
	Vector::~Vector() {
		delete[] values;  /*Delete auf Nullptr bewirkt nichts, SF leerer Vektor muss nicht beachtet werden */ 
	}


	/* METHODEN */ 
	
	size_t Vector::size() {return sz;}
	bool Vector::empty() {return sz==0;}

	void Vector::clear() { 
		sz=0;
	}
	void Vector::pop_back() {
		if (sz>0)
			--sz;
	}
	double& Vector::operator[](size_t sz) {
		if (sz<this->sz)
			return values[sz];
		throw runtime_error("Index nicht in erlaubtem Bereich");
	}
	const double& Vector::operator[](size_t sz) const {
		if (sz<this->sz)
			return values[sz];
		throw runtime_error("Index nicht in erlaubtem Bereich");
	}
	void Vector::reserve(size_t max_sz) {
		if (max_sz<this->max_sz) return; /* Wenn neue Größe kleiner als aktuelle Größe -> return, nix tun*/
		double* new_array = new double[max_sz];
		for (size_t i(0); i<sz; ++i)
			new_array[i]=values[i];
		delete[] values;
		values = new_array;
		this->max_sz = max_sz;
	}
	void Vector::push_back(const double& val) {
		if (sz==max_sz) {
			reserve(max_sz*2+10); /*+10 für den Fall, dass leerer Vektor */ 
		}
		values[sz++] = val;
	}
	Vector& Vector::operator= (const Vector& right_op) {
		 if (&right_op == this) return *this; 
		 if (values) delete [] values;
		 max_sz = right_op.max_sz;
		 sz = right_op.sz;
		 values = max_sz>0?new double[max_sz]:nullptr;
		 for (size_t i(0); i<sz; ++i) values[i]=right_op.values[i];
		 return *this;
 	}
		 
	Vector::Iterator Vector::begin() {return iterator(values);}
	Vector::Iterator Vector::end() {return iterator(values + max_sz);}
	Vector::Const_Iterator Vector::begin() const {return Const_Iterator(values);}
	Vector::Const_Iterator Vector::end() const {return Const_Iterator(values + max_sz);}











