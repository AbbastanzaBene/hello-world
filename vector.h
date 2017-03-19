#include <cstddef>

class Vector {
	size_t max_sz; 
	size_t sz;
	double* values; 
	void reserve(size_t); /*Neuen Speicher zuweisen, nur PRIVATE*/
public:
	
	/* NESTED CLASS Iterator */ 
	class Iterator { 
		double *ptr; 
	
	public:
		Iterator(double* new_iterator) {ptr = new_iterator;};
		const Iterator& operator++ () {++ptr; return *this;};
		bool operator!=(const Iterator& right_op) {return ptr!=right_op.ptr;};
		//double& operator*(){return *ptr;};
		double& operator*() const {return *ptr;};
		

/* NESTED CLASS Const_Iterator */ 
	class Const_Iterator { 
		const double *ptr; 
	
	public:
		Const_Iterator(double* new_iterator) {ptr = new_iterator;};
		const Const_Iterator& operator++ () {++ptr; return *this;};
		bool operator!=(const Const_Iterator& right_op) {return ptr!=right_op.ptr;};
		//const double& operator*(){return *ptr;};
		const double& operator*() const {return *ptr;};
	};
	
	/* TYPEDEF */
public:
	using value_type = double;
	using size_type = size_t;
	using difference_type = ptrdiff_t;
	using reference = double&;
	using const_reference = const double&;
	using pointer = double*;
	using const_pointer = const double*;
	using iterator = Iterator;
	using const_iterator = Const_Iterator;
	
	
	/* Konstruktoren */ 
	Vector(); 
	Vector(size_t); 
	Vector(std::initializer_list<double>); 
	Vector(const Vector&); /* Kopierkonstruktor */
	~Vector(); /* Dekonstruktor */ 

	/* METHODEN */ 
	size_t size(); /* (liefert die Anzahl der gespeicherten Elemente) */
	bool empty(); /* (liefert true, falls der Vektor leer ist, false sonst) */
	void clear();
	void pop_back();
	double& operator[](size_t);
	const double& operator[](size_t) const; 
	void push_back(const double&);
	/* Kopierzuweisungsoperator */
	Vector& operator= (const Vector&);
	
  	/* und weitere Methoden lt. Liste: */
 	Iterator begin();
	Iterator end();
	Const_Iterator begin() const;
	Const_Iterator end() const;

	/* GLOBALE Friend Funktion*/ 
	friend difference_type operator-(const Const_Iterator& lop, const Const_Iterator& rop) {
	return lop.ptr - rop.ptr;}


};
