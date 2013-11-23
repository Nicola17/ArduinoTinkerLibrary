#include "MagneticSensorLSM303.h"
#include "Exception.h"

namespace Tinker{
	MagneticSensorLSM303::MagneticSensorLSM303():
		_initialized(false)
	{}
	MagneticSensorLSM303::~MagneticSensorLSM303(){}

	void MagneticSensorLSM303::initialize(){
		bool res = _sensor.begin();
		TNK_ASSERT_RUNTIME_RTN(res,"Unable to initialize LSM303 magnetic sensor");
		_initialized = true;
	}
	bool MagneticSensorLSM303::isInitialized(){
		return _initialized;
	}
	MagneticSensorLSM303::string_type MagneticSensorLSM303::name()const{
		TNK_ASSERT_LOGIC_RTNV(_initialized,"Sensor must be initialized","");
		sensor_t s;
		_sensor.getSensor(&s);
		return String(s.name);
	}
	int32_t MagneticSensorLSM303::version()const{
		TNK_ASSERT_LOGIC_RTNV(_initialized,"Sensor must be initialized",0);
		sensor_t s;
		_sensor.getSensor(&s);
		return s.version;
	}
	int32_t MagneticSensorLSM303::id()const{
		TNK_ASSERT_LOGIC_RTNV(_initialized,"Sensor must be initialized",0);
		sensor_t s;
		_sensor.getSensor(&s);
		return s.sensor_id;
	}
	float MagneticSensorLSM303::maxValue()const{
		TNK_ASSERT_LOGIC_RTNV(_initialized,"Sensor must be initialized",0);
		sensor_t s;
		_sensor.getSensor(&s);
		return s.max_value;
	}
	float MagneticSensorLSM303::minValue()const{
		TNK_ASSERT_LOGIC_RTNV(_initialized,"Sensor must be initialized",0);
		sensor_t s;
		_sensor.getSensor(&s);
		return s.min_value;
	}
	float MagneticSensorLSM303::resolution()const{
		TNK_ASSERT_LOGIC_RTNV(_initialized,"Sensor must be initialized",0);
		sensor_t s;
		_sensor.getSensor(&s);
		return s.resolution;
	}

	//! Returns sensor reading.
	Vect3d<float> MagneticSensorLSM303::value(){
		//TNK_ASSERT_LOGIC_RTNV(_initialized,"Sensor must be initialized",0);
		sensors_event_t event; 
		_sensor.getEvent(&event);
		return Vect3d<float>(event.magnetic.x,event.magnetic.y,event.magnetic.z);
	}


}