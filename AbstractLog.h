#ifndef ABSTRACTLOG_H
#define ABSTRACTLOG_H

#include <Arduino.h>
#include "configuration\Configuration.h"

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
#ifdef ENABLE_LOGGER
	#define SECURE_LOG(logptr,val){if((logptr)!=0){(logptr)->display(val);(logptr)->endline();}}
	#define SECURE_LOG_VAL(logptr,name,val){if((logptr)!=0){(logptr)->display(name);(logptr)->display(": ");(logptr)->display(val);(logptr)->endline();}}
	#define SECURE_LOG_CLEAR(logptr){if((logptr)!=0){(logptr)->clear();}}
	#define SECURE_LOG_ONOFF(logptr,name,v){\
		if((logptr)!=0){\
			if(v){\
				(logptr)->display(name);(logptr)->display(": ON");(logptr)->endline();\
			}else{\
				(logptr)->display(name);(logptr)->display(": OFF");(logptr)->endline();\
			}\
		}\
	}
#else
	#define SECURE_LOG(logptr,val){}
	#define SECURE_LOG_VAL(logptr,name,val){}
	#define SECURE_LOG_CLEAR(logptr){}
	#define SECURE_LOG_ONOFF(logptr,name,v){}
#endif

#endif
