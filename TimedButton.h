#ifndef TIMEDBUTTON_H
#define TIMEDBUTTON_H

#include "AbstractLog.h"
#include "AbstractActuator.h"
#include "Timeout.h"
#include "ToggleSwitch.h"

namespace Tinker{

	class TimedButton{
	public:
		TimedButton():_log(0),_waiting(false){}
		TimedButton(int pin);
		void setPin(int pin);
		int pin()const;
		void initialize(float minT,float maxT);
		
		void setMinTime(float minT);
		unsigned long minTime()const;
		void setMaxTime(float maxT);
		unsigned long maxTime()const;
		
		boolean enabled();
		
	private:
		ToggleSwitch 	_toggle;
		bool 			_waiting;
		unsigned long 	_lastChangeT; 
		Timeout			_minTimeout;
		Timeout			_maxTimeout;

	public:
		AbstractLog* _log;
	};
}

#endif
