#ifndef ABSTRACTLOG_H
#define ABSTRACTLOG_H

#include <Arduino.h>

namespace Tinker{

/***************************************************
 * AbstractLog - Abstract interface for any logger
 *************************************************+*/

	class AbstractLog{
	public:
		virtual void endline()=0;
		virtual void display(char* str)=0;
		virtual void display(byte v)=0;
		virtual void display(float v)=0;
		virtual void display(double v)=0;
		virtual void display(int v)=0;
		virtual void display(unsigned int v)=0;
		virtual void display(unsigned long v)=0;
		virtual void clear()=0;
	};
}

#define SECURE_LOG(_logptr,val){if(_logptr!=0){_logptr->display(val);_logptr->endline();}}
#define SECURE_LOG_VAL(_logptr,name,val){if(_logptr!=0){_logptr->display(name);_logptr->display(": ");_logptr->display(val);_logptr->endline();}}
#define SECURE_LOG_CLEAR(_logptr){if(_logptr!=0){_logptr->clear();}}

#endif
