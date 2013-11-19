#ifndef DigitalActuator_H
#define DigitalActuator_H

#include "AbstractLog.h"
#include "AbstractActuator.h"

namespace Tinker{

	class DigitalActuator: public AbstractActuator{
	public:
		DigitalActuator():_log(0),_enabled(false){}
		DigitalActuator(int pin);
		void setPin(int pin);
      int pin()const;
      void initialize();
		
		virtual void setEnabled(boolean v);
		virtual boolean enabled()const;
		
	private:
		int _pin;
		boolean _enabled;

	public:
		AbstractLog* _log;
	};
}

#endif
