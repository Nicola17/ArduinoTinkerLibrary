#include "TimedButton.h"

namespace Tinker{
	TimedButton::TimedButton(int pin):
		_log(0),
		_toggle(pin),
		_waiting(false)
	{}
	void TimedButton::setPin(int pin){
		_toggle.setPin(pin);
	}
	int TimedButton::pin()const{
		return _toggle.pin();
	}
	void TimedButton::initialize(float minT,float maxT){
		SECURE_LOG(_log,"Timed button initialization");
		setMinTime(minT);
		setMaxTime(maxT);
	}
	
	void TimedButton::setMinTime(float minT){
		_minTimeout.setTimeout(minT);
	}
	unsigned long TimedButton::minTime()const{
		return _minTimeout.timeout();
	}
	void TimedButton::setMaxTime(float maxT){
		_maxTimeout.setTimeout(maxT);
	}
	unsigned long TimedButton::maxTime()const{
		return _maxTimeout.timeout();
	}
	
	boolean TimedButton::refreshAndCheck(){
		const boolean enabled(_toggle.enabled());
		if(!_waiting && enabled){
			SECURE_LOG(_log,"Timed button is waiting...");
			_waiting = true;
			_minTimeout.refresh();
			_maxTimeout.refresh();
		}
		if(_waiting){
			const boolean minT(_minTimeout.timeoutReached());
			const boolean maxT(_maxTimeout.timeoutReached());
			
			//Released too early
			if(!enabled && !minT && !maxT){
				SECURE_LOG(_log,"Timed button released too early");
				_waiting = false;
				return false;
			}
			
			//Released too late
			if(!enabled && minT && maxT){
				SECURE_LOG(_log,"Timed button released too late");
				_waiting = false;
				return false;
			}
			
			//Activated
			if(!enabled && minT && !maxT){
				SECURE_LOG(_log,"Timed button activated");
				_waiting = false;
				return true;
			}
			
		}
		return false;
	}

}