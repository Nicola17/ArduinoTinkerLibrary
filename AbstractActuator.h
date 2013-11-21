#ifndef ABSTRACTACTUATOR_H
#define ABSTRACTACTUATOR_H

#include <Arduino.h>

namespace Tinker{

	//! Abstract interface for any digital actuator
	/*!
		Every object that should act as a digital actuator must inherit from this class. 
		\author Nicola Pezzotti
	*/
  class AbstractActuator{
  public:
  //! Changes actuator status.
    virtual void setEnabled(boolean v) = 0;
	//! Returns actuator status.
    virtual boolean enabled()const = 0;
  };

}

#endif
