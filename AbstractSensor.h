#ifndef ABSTRACTSENSOR_H
#define ABSTRACTSENSOR_H

#include "vect3d.h"

namespace Tinker{

	//! Abstract interface for any scalar sensor
	/*!
		Every object that should act as a scalar sensor must inherit from this class. 
		\author Nicola Pezzotti
	*/
	class AbstractScalarSensor{
	public:
		//! Returns sensor reading.
		virtual float value()=0;
	};


	//! Abstract interface for any 3D sensor
	/*!
		Every object that should act as a 3D sensor must inherit from this class. 
		\author Nicola Pezzotti
	*/
	class Abstract3dSensor{
	public:
		//! Returns sensor reading.
		virtual Vect3d<float> value()=0;
	};
}

#endif
