#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <Arduino.h>
namespace Tinker{

	//! A static class used to handle exceptions
	/*!
	This class permits to uset something similar to C++ try/catch in your arduino code
	\author Nicola Pezzotti
	*/
	class Exception{
	public:
		enum Type{None=0,Logic=1,Runtime=2};
		typedef unsigned long time_type;
		typedef String string_type;

	public:
		//!Throws an exception.
		static void throwException(Type type, string_type& message);
		//!Throws an exception.
		static void throwException(Type type, const char* message);
		//!Returns true if an exception has been thrown.
		static bool exceptionThrown();
		//!Resets exception handler.
		static void reset();
		//!Returns exception type.
		static Type type();
		//!Returns time in millis from sketch start to the current exception.
		static time_type time();
		//!Returns exception message.
		static const string_type& message();

	private:
		static bool			_exceptionThrown;
		static Type			_type; 
		static time_type	_time;
		static string_type	_message;
	};

}

#define TNK_THROW(type,message){Tinker::Exception::throwException(type,message);}
#define TNK_THROW_LOGIC(message){Tinker::Exception::throwException(Tinker::Exception::Logic,message);}
#define TNK_THROW_RUNTIME(message){Tinker::Exception::throwException(Tinker::Exception::Runtime,message);}

#define TNK_ASSERT(cond,type,message){if(!(cond)){Tinker::Exception::throwException(type,message);}}
#define TNK_ASSERT_LOGIC(cond,message){if(!(cond)){Tinker::Exception::throwException(Tinker::Exception::Logic,message);}}
#define TNK_ASSERT_RUNTIME(cond,message){if(!(cond)){Tinker::Exception::throwException(Tinker::Exception::Runtime,message);}}
		
#define TNK_THROW_RTN(type,message){TNK_THROW(type,message);return;}
#define TNK_THROW_LOGIC_RTN(message){TNK_THROW_LOGIC(message);return;}
#define TNK_THROW_RUNTIME_RTN(message){TNK_THROW_RUNTIME(message);return;}
#define TNK_THROW_RTNV(type,message,val){TNK_THROW(type,message);return val;}
#define TNK_THROW_LOGIC_RTNV(message,val){TNK_THROW_LOGIC(message);return val;}
#define TNK_THROW_RUNTIME_RTNV(message,val){TNK_THROW_RUNTIME(message);return val;}

#define TNK_ASSERT_RTN(cond,type,message){TNK_ASSERT(cond,type,message);return;}
#define TNK_ASSERT_LOGIC_RTN(cond,message){TNK_ASSERT_LOGIC(cond,message);return;}
#define TNK_ASSERT_RUNTIME_RTN(cond,message){TNK_ASSERT_RUNTIME(cond,message);return;}
#define TNK_ASSERT_RTNV(cond,type,message,val){TNK_ASSERT(cond,type,message);return val;}
#define TNK_ASSERT_LOGIC_RTNV(cond,message,val){TNK_ASSERT_LOGIC(cond,message);return val;}
#define TNK_ASSERT_RUNTIME_RTNV(cond,message,val){TNK_ASSERT_RUNTIME(cond,message);return val;}

#define STOP_SKETCH_ON_EXCEPTION(){if(Tinker::Exception::exceptionThrown())return;}
#define STOP_SKETCH_ON_EXCEPTION(val){if(Tinker::Exception::exceptionThrown())return val;}

#endif