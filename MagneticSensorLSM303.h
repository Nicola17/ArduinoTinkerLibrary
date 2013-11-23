#ifndef MAGNETICSENSORLSM303_H
#define MAGNETICSENSORLSM303_H

#include <Arduino.h>
#include "ExternalLibsInc.h"
#include "AbstractSensor.h"


namespace Tinker{

	//! Class to handle LSM303 magnetic sensor
	/*!
		\author Nicola Pezzotti
	*/
	class MagneticSensorLSM303: public Abstract3dSensor{
	public:
		typedef String string_type;
	public:
		MagneticSensorLSM303();
		virtual ~MagneticSensorLSM303();

		//! Initialize the sensor
		void initialize();
		//! Returns true if the sensor is initialized
		bool isInitialized();
		//! Returns sensor name
		string_type name()const;
		//! Returns sensor version
		int32_t version()const;
		//! Returns sensor id
		int32_t id()const;
		//! Returns sensor max value
		float maxValue()const;
		//! Returns sensor min value
		float minValue()const;
		//! Returns sensor resolution
		float resolution()const;

		//! Returns sensor reading.
		virtual Vect3d<float> value();

	private: 
		bool _initialized;
		mutable Adafruit_LSM303_Mag _sensor;
	};


}

#endif