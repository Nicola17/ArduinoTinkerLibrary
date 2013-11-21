#ifndef ABSTRACTLOG_H
#define ABSTRACTLOG_H

#include <Arduino.h>

namespace Tinker{

	//! Abstract interface for any logger
	/*!
		Every object that should act as a logger must inherit from this class. 
		\author Nicola Pezzotti
	*/
	class AbstractLog{
	public:
		//! Endline.
		virtual void endline()=0;
		//! Display a character array.
		virtual void display(char* str)=0;
		//! Display a byte value.
		virtual void display(byte v)=0;
		//! Display a float value.
		virtual void display(float v)=0;
		//! Display a double value.
		virtual void display(double v)=0;
		//! Display an integer value.
		virtual void display(int v)=0;
		//! Display an unsigned int value.
		virtual void display(unsigned int v)=0;
		//! Display an unsigned long value.
		virtual void display(unsigned long v)=0;
		//! Clear the logger.
		virtual void clear()=0;
	};
}

#define SECURE_LOG(_logptr,val){if(_logptr!=0){_logptr->display(val);_logptr->endline();}}
#define SECURE_LOG_VAL(_logptr,name,val){if(_logptr!=0){_logptr->display(name);_logptr->display(": ");_logptr->display(val);_logptr->endline();}}
#define SECURE_LOG_CLEAR(_logptr){if(_logptr!=0){_logptr->clear();}}

#endif
