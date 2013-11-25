#ifdef SERIAL_COMM
	#include "SerialLog.h"
#endif
#include "ToggleSwitch.h"

#include "SequentialStatusSwitcher.h"
#include "TimedButton.h"
#include "NeoPixelCircularDisplay.h"
#include "MagneticSensorLSM303.h"
#include "Vect2dCircularDisplay.h"
#include "TMP36.h"



class TinkerWatchImpl{
public:
#ifdef SERIAL_COMM
	typedef Tinker::SerialLog 	SerialLog;
#endif
	typedef Tinker::TimedButton TimedButton;
	typedef Tinker::SequentialStatusSwitcher<Tinker::TimedButton>	StatusSwitcher;
	typedef Tinker::NeoPixelCircularDisplay<16> Display;
	typedef Tinker::MagneticSensorLSM303		MagSensor;
	typedef Tinker::Vect2dCircularDisplay<Display,1> MagDisplay;
	typedef Tinker::Vect3d<uint8_t> 			color_type;
	typedef Tinker::TMP36 			TemperatureSensor;
	enum Mode{
		RandomAnimation = 0,
		Compass = 1,
		Accellerometer = 2,
		GPS = 3, 
		Clock = 4,
		Temperature = 5
	};
	
public:
	TinkerWatchImpl();
	
	void initialize();
	
	void startAnimation();
	
	void changeStatusAnimation();
	
	void randomAnimation();
	
	void compass();
	
	void displayTime();
	
	void setTime(uint32_t h, uint32_t m, uint32_t s);
	
	void displayTemperature();
	
	void update();
	
	
private:

	int8_t	_ringPin;
	int8_t	_switchPin;
	int8_t	_nStatus;
	int8_t	_currentStatus;
	int8_t	_brightness;
	
	color_type _transitionColor;
	color_type _magnColor;
	
	//TimedButton 	_syncroButton;
	StatusSwitcher 	_statusSwitcher;
	Display 		_display;
	
	MagSensor		_magSensor;
	MagDisplay 		_magDisplay;
	TemperatureSensor _tmpSensor;

#ifdef SERIAL_COMM
	SerialLog		_serialLog;
#endif
	
	//Time
	uint32_t _lastTimeExecMillis;
	uint32_t _lastTimeDayMillis;
	
	static const uint32_t _millsDay;
	static const uint32_t _millsHour;
	static const uint32_t _millsMinute;
	static const uint32_t _millsSecond;
	
	float _sigmaMilliSec;
	float _sigmaSec;
	float _sigmaMin;
	float _sigmaHour;

	Display::color_type _colorMilliSec;
	Display::color_type _colorSec;
	Display::color_type _colorMin;
	Display::color_type _colorHour;
};