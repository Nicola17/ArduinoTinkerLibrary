#ifndef Vect2d_H
#define Vect2d_H

#include <AbstractLog.h>

namespace Tinker{

	template <class T>
	class Vect2d{
	public:
		typedef T value_type;
		static const unsigned int DIM = 2;

	public:
		Vect2d(T v = 0);
		Vect2d(T v0, T v1);
		template <class T1>
		Vect2d(const Vect2d<T1>& other);

		//Constructor
		T& operator[](unsigned int idx);
		const T& operator[](unsigned int idx)const;

		//Assignment
		template <class T1>
		Vect2d<T>& operator=(const Vect2d<T1>& other);
		template <class T1>
		Vect2d<T>& operator=(T1 v);

		//Sum
		template <class T1>
		Vect2d<T> operator+(const Vect2d<T1>& other)const;
		template <class T1>
		Vect2d<T> operator+(T1 v)const;
		template <class T1>
		Vect2d<T>& operator+=(const Vect2d<T1>& other);
		template <class T1>
		Vect2d<T>& operator+=(T1 v);

		//Sub
		template <class T1>
		Vect2d<T> operator-(const Vect2d<T1>& other)const;
		template <class T1>
		Vect2d<T> operator-(T1 v)const;
		template <class T1>
		Vect2d<T>& operator-=(const Vect2d<T1>& other);
		template <class T1>
		Vect2d<T>& operator-=(T1 v);

		//Scalar Mult
		template <class T1>
		Vect2d<T> operator*(T1 v)const;
		template <class T1>
		Vect2d<T>& operator*=(T1 v);

		//Scalar Div
		template <class T1>
		Vect2d<T> operator/(T1 v)const;
		template <class T1>
		Vect2d<T>& operator/=(T1 v);

		//Test
		template <class T1>
		bool operator==(const Vect2d<T1>& other);
		template <class T1>
		bool operator!=(const Vect2d<T1>& other);

	public:
		T _v[DIM];
	};	

/***********************************
 * Methods
 ***********************************/
	template <class T>
	Vect2d<T>::Vect2d(T v){
		_v[0] = v;
		_v[1] = v;
	}

	template <class T>
	Vect2d<T>::Vect2d(T v0, T v1){
		_v[0] = v0;
		_v[1] = v1;
	}

	template <class T>
	template <class T1>
	Vect2d<T>::Vect2d(const Vect2d<T1>& other){
		_v[0] = static_cast<T>(other[0]);
		_v[1] = static_cast<T>(other[1]);
	}

	template <class T>
	T& Vect2d<T>::operator[](unsigned int idx){
		return _v[idx];
	}
	template <class T>
	const T& Vect2d<T>::operator[](unsigned int idx)const{
		return _v[idx];
	}

	template <class T>
	template <class T1>
	Vect2d<T>& Vect2d<T>::operator=(const Vect2d<T1>& other){
		_v[0] = other[0];
		_v[1] = other[1];
	}
	template <class T>
	template <class T1>
	Vect2d<T>& Vect2d<T>::operator=(T1 v){
		_v[0] = v;
		_v[1] = v;
	}

	template <class T>
	template <class T1>
	bool Vect2d<T>::operator==(const Vect2d<T1>& other){
		return (_v[0]==other[0] && _v[1]==other[1]);
	}
	template <class T>
	template <class T1>
	bool Vect2d<T>::operator!=(const Vect2d<T1>& other){
		return (_v[0]!=other[0] || _v[1]!=other[1]);
	}

	template <class T>
	template <class T1>
	Vect2d<T> Vect2d<T>::operator+(const Vect2d<T1>& other)const{
		Vect2d<T> r;
		r[0] = _v[0]+other[0];
		r[1] = _v[1]+other[1];
		return r;
	}
	template <class T>
	template <class T1>
	Vect2d<T> Vect2d<T>::operator+(T1 v)const{
		Vect2d<T> r;
		r[0] = _v[0]+v;
		r[1] = _v[1]+v;
		return r;
	}
	template <class T>
	template <class T1>
	Vect2d<T>& Vect2d<T>::operator+=(const Vect2d<T1>& other){
		_v[0] += other[0];
		_v[1] += other[1];
		return *this;
	}
	template <class T>
	template <class T1>
	Vect2d<T>& Vect2d<T>::operator+=(T1 v){
		_v[0] += v;
		_v[1] += v;
		return *this;
	}

	template <class T>
	template <class T1>
	Vect2d<T> Vect2d<T>::operator-(const Vect2d<T1>& other)const{
		Vect2d<T> r;
		r[0] = _v[0]-other[0];
		r[1] = _v[1]-other[1];
		return r;
	}
	template <class T>
	template <class T1>
	Vect2d<T> Vect2d<T>::operator-(T1 v)const{
		Vect2d<T> r;
		r[0] = _v[0]-v;
		r[1] = _v[1]-v;
		return r;
	}
	template <class T>
	template <class T1>
	Vect2d<T>& Vect2d<T>::operator-=(const Vect2d<T1>& other){
		_v[0] -= other[0];
		_v[1] -= other[1];
		return *this;
	}
	template <class T>
	template <class T1>
	Vect2d<T>& Vect2d<T>::operator-=(T1 v){
		_v[0] -= v;
		_v[1] -= v;
		return *this;
	}

	template <class T>
	template <class T1>
	Vect2d<T> Vect2d<T>::operator*(T1 v)const{
		Vect2d<T> r;
		r[0] = _v[0]*v;
		r[1] = _v[1]*v;
		return r;
	}
	template <class T>
	template <class T1>
	Vect2d<T>& Vect2d<T>::operator*=(T1 v){
		_v[0] *= v;
		_v[1] *= v;
		return *this;
	}

	template <class T>
	template <class T1>
	Vect2d<T> Vect2d<T>::operator/(T1 v)const{
		Vect2d<T> r;
		r[0] = _v[0]/v;
		r[1] = _v[1]/v;
		return r;
	}
	template <class T>
	template <class T1>
	Vect2d<T>& Vect2d<T>::operator/=(T1 v){
		_v[0] /= v;
		_v[1] /= v;
		return *this;
	}

/***********************************
 * External functions
 ***********************************/

	template <class T1, class T2>
	float dot(const Vect2d<T1>& a, const Vect2d<T2>& b){
		return a[0]*b[0]+a[1]*b[1];
	}
	template <class T1, class T2>
	Vect2d<float> cross(const Vect2d<T1>& a, const Vect2d<T2>& b){
		Vect2d<float> r;
		//TODO
		return r;
	}
	template <class T>
	float normL1(const Vect2d<T>& a){
		return abs(a[0])+abs(a[1]);
	}
	template <class T>
	float normL2(const Vect2d<T>& a){
		return sqrt(dot(a,a));
	}
	
	namespace LOG{
		template <class T>
		void displayVect2d(const Vect2d<T>& v, AbstractLog* log){
			log->display("V[");
			log->display(v[0]);
			log->display(";");
			log->display(v[1]);
			log->display("]");
		}
	}

}

#endif
