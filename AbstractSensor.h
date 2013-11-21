#ifndef ABSTRACTSENSOR_H
#define ABSTRACTSENSOR_H

namespace Tinker{

	//! Abstract interface for any scalar sensor
	/*!
		Every object that should act as a scalar sensor must inherit from this class. 
		\author Nicola Pezzotti
	*/
  class AbstractSensor{
  public:
	//! Returns sensor reading.
	virtual float value()=0;
  };

}

#endif
