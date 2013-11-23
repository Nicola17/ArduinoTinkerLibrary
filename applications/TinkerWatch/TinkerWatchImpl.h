#include "ToggleSwitch.h"
#include "SerialLog.h"
#include "SequentialStatusSwitcher.h"
#include "TimedButton.h"
#include "NeoPixelCircularDisplay.h"

class TinkerWatchImpl{
public:
	typedef Tinker::SerialLog 	SerialLog;
	typedef Tinker::TimedButton TimedButton;
	typedef Tinker::SequentialStatusSwitcher<Tinker::TimedButton>	StatusSwitcher;
	typedef Tinker::NeoPixelCircularDisplay<16> Display;
	typedef Tinker::Vect3d<uint8_t> 			color_type;
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
	
	void update();
	
	
private:

	int8_t	_ringPin;
	int8_t	_switchPin;
	int8_t	_nStatus;
	int8_t	_currentStatus;
	int8_t	_brightness;
	
	TimedButton 	_syncroButton;
	StatusSwitcher 	_statusSwitcher;
	Display 		_display;
	SerialLog		_serialLog;
};