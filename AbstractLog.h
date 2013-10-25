#ifndef ABSTRACTLOG_H
#define ABSTRACTLOG_H

#include <arduino.h>

namespace Tinker{

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

#endif
