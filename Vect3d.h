#ifndef VECT3D_H
#define VECT3D_H

#include <AbstractLog.h>

namespace Tinker{

	template <class T>
	class Vect3d{
	public:
		typedef T value_type;
		static const unsigned int DIM = 3;

	public:
		Vect3d(T v = 0);
		Vect3d(T v0, T v1, T v2);
		template <class T1>
		Vect3d(const Vect3d<T1>& other);

		//Constructor
		T& operator[](unsigned int idx);
		const T& operator[](unsigned int idx)const;

		//Assignment
		template <class T1>
		Vect3d<T>& operator=(const Vect3d<T1>& other);
		template <class T1>
		Vect3d<T>& operator=(T1 v);

		//Sum
		template <class T1>
		Vect3d<T> operator+(const Vect3d<T1>& other)const;
		template <class T1>
		Vect3d<T> operator+(T1 v)const;
		template <class T1>
		Vect3d<T>& operator+=(const Vect3d<T1>& other);
		template <class T1>
		Vect3d<T>& operator+=(T1 v);

		//Sub
		template <class T1>
		Vect3d<T> operator-(const Vect3d<T1>& other)const;
		template <class T1>
		Vect3d<T> operator-(T1 v)const;
		template <class T1>
		Vect3d<T>& operator-=(const Vect3d<T1>& other);
		template <class T1>
		Vect3d<T>& operator-=(T1 v);

		//Scalar Mult
		template <class T1>
		Vect3d<T> operator*(T1 v)const;
		template <class T1>
		Vect3d<T>& operator*=(T1 v);

		//Scalar Div
		template <class T1>
		Vect3d<T> operator/(T1 v)const;
		template <class T1>
		Vect3d<T>& operator/=(T1 v);

		//Test
		template <class T1>
		bool operator==(const Vect3d<T1>& other);
		template <class T1>
		bool operator!=(const Vect3d<T1>& other);

	public:
		T _v[DIM];
	};	

/***********************************
 * Methods
 ***********************************/
	template <class T>
	Vect3d<T>::Vect3d(T v){
		_v[0] = v;
		_v[1] = v;
		_v[2] = v;
	}

	template <class T>
	Vect3d<T>::Vect3d(T v0, T v1, T v2){
		_v[0] = v0;
		_v[1] = v1;
		_v[2] = v2;
	}

	template <class T>
	template <class T1>
	Vect3d<T>::Vect3d(const Vect3d<T1>& other){
		_v[0] = static_cast<T>(other[0]);
		_v[1] = static_cast<T>(other[1]);
		_v[2] = static_cast<T>(other[2]);
	}

	template <class T>
	T& Vect3d<T>::operator[](unsigned int idx){
		return _v[idx];
	}
	template <class T>
	const T& Vect3d<T>::operator[](unsigned int idx)const{
		return _v[idx];
	}

	template <class T>
	template <class T1>
	Vect3d<T>& Vect3d<T>::operator=(const Vect3d<T1>& other){
		_v[0] = other[0];
		_v[1] = other[1];
		_v[2] = other[2];
	}
	template <class T>
	template <class T1>
	Vect3d<T>& Vect3d<T>::operator=(T1 v){
		_v[0] = v;
		_v[1] = v;
		_v[2] = v;
	}

	template <class T>
	template <class T1>
	bool Vect3d<T>::operator==(const Vect3d<T1>& other){
		return (_v[0]==other[0] && _v[1]==other[1] && _v[2]==other[2]);
	}
	template <class T>
	template <class T1>
	bool Vect3d<T>::operator!=(const Vect3d<T1>& other){
		return (_v[0]!=other[0] || _v[1]!=other[1] || _v[2]!=other[2]);
	}

	template <class T>
	template <class T1>
	Vect3d<T> Vect3d<T>::operator+(const Vect3d<T1>& other)const{
		Vect3d<T> r;
		r[0] = _v[0]+other[0];
		r[1] = _v[1]+other[1];
		r[2] = _v[2]+other[2];
		return r;
	}
	template <class T>
	template <class T1>
	Vect3d<T> Vect3d<T>::operator+(T1 v)const{
		Vect3d<T> r;
		r[0] = _v[0]+v;
		r[1] = _v[1]+v;
		r[2] = _v[2]+v;
		return r;
	}
	template <class T>
	template <class T1>
	Vect3d<T>& Vect3d<T>::operator+=(const Vect3d<T1>& other){
		_v[0] += other[0];
		_v[1] += other[1];
		_v[2] += other[2];
		return *this;
	}
	template <class T>
	template <class T1>
	Vect3d<T>& Vect3d<T>::operator+=(T1 v){
		_v[0] += v;
		_v[1] += v;
		_v[2] += v;
		return *this;
	}

	template <class T>
	template <class T1>
	Vect3d<T> Vect3d<T>::operator-(const Vect3d<T1>& other)const{
		Vect3d<T> r;
		r[0] = _v[0]-other[0];
		r[1] = _v[1]-other[1];
		r[2] = _v[2]-other[2];
		return r;
	}
	template <class T>
	template <class T1>
	Vect3d<T> Vect3d<T>::operator-(T1 v)const{
		Vect3d<T> r;
		r[0] = _v[0]-v;
		r[1] = _v[1]-v;
		r[2] = _v[2]-v;
		return r;
	}
	template <class T>
	template <class T1>
	Vect3d<T>& Vect3d<T>::operator-=(const Vect3d<T1>& other){
		_v[0] -= other[0];
		_v[1] -= other[1];
		_v[2] -= other[2];
		return *this;
	}
	template <class T>
	template <class T1>
	Vect3d<T>& Vect3d<T>::operator-=(T1 v){
		_v[0] -= v;
		_v[1] -= v;
		_v[2] -= v;
		return *this;
	}

	template <class T>
	template <class T1>
	Vect3d<T> Vect3d<T>::operator*(T1 v)const{
		Vect3d<T> r;
		r[0] = _v[0]*v;
		r[1] = _v[1]*v;
		r[2] = _v[2]*v;
		return r;
	}
	template <class T>
	template <class T1>
	Vect3d<T>& Vect3d<T>::operator*=(T1 v){
		_v[0] *= v;
		_v[1] *= v;
		_v[2] *= v;
		return *this;
	}

	template <class T>
	template <class T1>
	Vect3d<T> Vect3d<T>::operator/(T1 v)const{
		Vect3d<T> r;
		r[0] = _v[0]/v;
		r[1] = _v[1]/v;
		r[2] = _v[2]/v;
		return r;
	}
	template <class T>
	template <class T1>
	Vect3d<T>& Vect3d<T>::operator/=(T1 v){
		_v[0] /= v;
		_v[1] /= v;
		_v[2] /= v;
		return *this;
	}

/***********************************
 * External functions
 ***********************************/

	template <class T1, class T2>
	float dot(const Vect3d<T1>& a, const Vect3d<T2>& b){
		return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
	}
	template <class T1, class T2>
	Vect3d<float> cross(const Vect3d<T1>& a, const Vect3d<T2>& b){
		Vect3d<float> r;
		r[0] = a[1]*b[2]-a[2]*b[1];
		r[1] = a[2]*b[0]-a[0]*b[2];
		r[2] = a[0]*b[1]-a[1]*b[0];
		return r;
	}
	template <class T>
	float normL1(const Vect3d<T>& a){
		return abs(a[0])+abs(a[1])+abs(a[2]);
	}
	template <class T>
	float normL2(const Vect3d<T>& a){
		return sqrt(dot(a,a));
	}
	
	

	namespace LOG{
		template <class T>
		void displayVect3d(const Vect3d<T>& v, AbstractLog* log){
			#ifdef ENABLE_LOGGER
				log->display("V[");
				log->display(v[0]);
				log->display(";");
				log->display(v[1]);
				log->display(";");
				log->display(v[2]);
				log->display("]");
			#endif
		}
	}

}

#endif
