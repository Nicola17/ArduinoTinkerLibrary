#ifndef ToggleSwitch_H
#define ToggleSwitch_H

#include "AbstractLog.h"
/****************************************
 * ToggleSwitch
 * Once initialized return the status of
 * a toggle switch
 ****************************************/
namespace Tinker{

	class ToggleSwitch{
	public:
		ToggleSwitch():_log(0){}
		ToggleSwitch(int pin);
		void setPin(int pin);
      int pin()const;
      void initialize();
		
		virtual boolean enabled()const;
		
	private:
		int _pin;

	public:
		AbstractLog* _log;
	};

}

#endif
