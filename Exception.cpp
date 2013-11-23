#include "Exception.h"

namespace Tinker{

	bool					Exception::_exceptionThrown = false;
	Exception::Type			Exception::_type = Exception::None; 
	Exception::time_type	Exception::_time = 0;
	Exception::string_type	Exception::_message = "";

	void Exception::throwException(Type type, string_type& message){
		_time = millis();
		_type = type;
		_message = message;
		_exceptionThrown = true;
	}
	void Exception::throwException(Type type, const char* message){
		_time = millis();
		_type = type;
		_message = String(message);
		_exceptionThrown = true;
	}

	bool Exception::exceptionThrown(){
		return _exceptionThrown;
	}
	
	void Exception::reset(){
		_exceptionThrown = false;
		_message = String("");
		_type = None;
		_time = 0;
	}

	Exception::Type Exception::type(){
		return _type;
	}
	Exception::time_type Exception::time(){
		return _time;
	}
	const Exception::string_type& Exception::message(){
		return _message;
	}
}