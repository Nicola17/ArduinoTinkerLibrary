#ifndef EXCEPTIONHANDLERS_H
#define EXCEPTIONHANDLERS_H

#include "Exception.h"
namespace Tinker{
	//! A scoped class that catches exception on its destruction
	/*!
	Use a CatchConcept implementation as a template parameter
	\author Nicola Pezzotti
	*/
	template <class Catch>
	class TryAndCatchOnDestruction{
	public:
		~TryAndCatchOnDestruction();
	};
	template <class Catch>
	TryAndCatchOnDestruction<Catch>::~TryAndCatchOnDestruction(){
		if(Tinker::Exception::exceptionThrown()){
			Catch::catchException();
			Tinker::Exception::reset();
		}
	}

	//! Concept for a catch implementation
	/*!
	\author Nicola Pezzotti
	*/
	class CatchConcept{
	public:
		static void catchException(){}
	};

	//! A CatchConcept implementation that writes exception on serial 
	/*!
	\author Nicola Pezzotti
	*/
	class SerialCatch{
	public:
		static void catchException(){
			Serial.print("Exc - ");
			Serial.print(Exception::time());Serial.print(": ");
			Serial.println(Exception::message());
		}
	};
}

#define RETURN_ON_EXCEPTION(){if(Tinker::Exception::exceptionThrown())return;}
#define RETURN_ON_EXCEPTION(val){if(Tinker::Exception::exceptionThrown())return val;}

#endif