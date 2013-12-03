#ifndef TOGGLESWITCH_H
#define TOGGLESWITCH_H

#include "AbstractLog.h"

namespace Tinker{

	//! A class to handle a toggle switch
	/*!
		This class permits to handle in an easy way any toggle switch
		\author Nicola Pezzotti
	*/
	class ToggleSwitch{
	public:
		//! Creates an unitialize toggle switch. 
		ToggleSwitch(uint16_t pin = -1):_log(0),_pin(pin){}
		//! Returns current switch pin
		int pin()const;
		//! Sets switch pin
		void setPin(uint16_t pin);
		//! Returns true if the switch is enabled on LOW
		boolean enabledOnLow()const;
		//! Returns true if pull up resistor is enabled
		boolean pullUpResistor()const;
		//! Initialiazes the toggle switch
		void initialize(bool enabledOnLow = false, bool pullUpResistor = false);
		//!Returns toggle switch status
		virtual boolean enabled()const;
		
	private:
		uint16_t _pin;
		bool _enabledOnLow;
		bool _pullUpResistor;

	public:
		AbstractLog* _log;
	};

}

#endif
