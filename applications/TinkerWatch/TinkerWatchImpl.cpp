#include "TinkerWatchImpl.h"
#include "Exception.h"

const uint32_t TinkerWatchImpl::_millsDay = 43200000;
const uint32_t TinkerWatchImpl::_millsHour = 3600000;
const uint32_t TinkerWatchImpl::_millsMinute = 60000;
const uint32_t TinkerWatchImpl::_millsSecond = 1000;

TinkerWatchImpl::TinkerWatchImpl():
	_switchPin(10),
	_ringPin(9),
	_display(9),
	_magDisplay(9),
	_brightness(30),
	_nStatus(6),
	_currentStatus(0),
	_transitionColor(255,150,0),
	_magnColor(255,0,255),
	_colorMilliSec(200,120,0),
	_colorSec(0,200,0),
	_colorMin(0,0,200),
	_colorHour(200,0,0),
	_sigmaMilliSec(Display::radBetweenPixels()/6),
	_sigmaSec(Display::radBetweenPixels()/3.5),
	_sigmaMin(Display::radBetweenPixels()/2),
	_sigmaHour(Display::radBetweenPixels()/1.5),
	_lastTimeExecMillis(0),
	_lastTimeDayMillis(0)
{}
	
void TinkerWatchImpl::initialize(){
	delay(5000);
	_statusSwitcher._log = &_serialLog;
	_statusSwitcher.switcher().setPin(_switchPin);
	_statusSwitcher.switcher().initialize(100,2000);
	_statusSwitcher.setNumberOfStatus(_nStatus);
	_statusSwitcher.setStatus(_currentStatus);
	
	_magSensor.initialize();
	STOP_SKETCH_ON_EXCEPTION();
	
	_magDisplay.init(0,200,Display::radBetweenPixels()/2,Display::radBetweenPixels(),10,40);
	_magDisplay.setColor(0,_magnColor);
	STOP_SKETCH_ON_EXCEPTION();
	
	_tmpSensor.setPin(6);
	_tmpSensor.setVoltageRef(3.3);
	_tmpSensor.initialize();
	STOP_SKETCH_ON_EXCEPTION();
	
	_display.init();
	_display.setBrightness(_brightness);
	startAnimation();
}

void TinkerWatchImpl::startAnimation(){
	for(int i = 0; i < 4; ++i){
		_display.reset();
		if(i%2)
			_display.setColor(color_type(0,150,255));
		else	
			_display.setColor(color_type(255,150,0));
		_display.show();
		delay(200);
	}
}

void TinkerWatchImpl::changeStatusAnimation(){
	uint8_t nPxl(16);
	_display.reset();
	for(int i = 0; i < 16; ++i){
		_display.setColor(i,_transitionColor);
		_display.show();
		delay(20);
	}
	for(int i = 0; i < 16; ++i){
		_display.setColor(i,color_type(0));
		_display.show();
		delay(20);
	}
}

void TinkerWatchImpl::randomAnimation(){
	uint8_t nPxl(6);
	_display.reset();
	for(int i = 0; i < nPxl; ++i){
		color_type color;
		do{
			color[0] = random()%256;
			color[1] = random()%256;
			color[2] = random()%256;
		}while(normL2(color) < 400);
		_display.setColor(random()%16,color);
	}
	_display.show();
	delay(50);
}

void TinkerWatchImpl::compass(){
	const Tinker::Vect3d<float> readings(_magSensor.value());
	Tinker::Vect2d<float> v(readings[0],readings[1]);
	_magDisplay.show(v);
}


void TinkerWatchImpl::displayTime(){
	const uint32_t time = millis()-_lastTimeExecMillis+_lastTimeDayMillis;

	const float radMilliSec = 2.*PI*(time%_millsSecond)/_millsSecond;
	const float radSec 		= 2.*PI*(time%_millsMinute)/_millsMinute;
	const float radMin 		= 2.*PI*(time%_millsHour)/_millsHour;
	const float radHour 	= 2.*PI*(time%_millsDay)/_millsDay;
	
	_display.reset(); 
	_display.setColorFp(radMilliSec,_colorMilliSec,_sigmaMilliSec,true);
	_display.setColorFp(radSec,_colorSec,_sigmaSec,true);
	_display.setColorFp(radMin,_colorMin,_sigmaMin,true);
	_display.setColorFp(radHour,_colorHour,_sigmaHour,true);
	_display.show();
}

void TinkerWatchImpl::setTime(uint32_t h, uint32_t m, uint32_t s){
	_serialLog.display("Set time");_serialLog.endline();
	_serialLog.display("h:");_serialLog.display(h);_serialLog.endline();
	_serialLog.display("m:");_serialLog.display(m);_serialLog.endline();
	_serialLog.display("s:");_serialLog.display(s);_serialLog.endline();
	_lastTimeExecMillis = millis();
	_lastTimeDayMillis = s*_millsSecond + m*_millsMinute + h*_millsHour;
}

void TinkerWatchImpl::displayTemperature(){
//TODO
	_tmpSensor._log = &_serialLog;
	float temp = _tmpSensor.value();
	_serialLog.display(temp);_serialLog.endline();
	int intTemp(temp);
	int u(intTemp%10);
	int d(intTemp/10);
	_serialLog.display(u);_serialLog.endline();
	_serialLog.display(d);_serialLog.endline();
	_display.reset();
	for(int i = 0; i < u; ++i)
		_display.setColor(i,color_type(0,255,0),true);
	for(int i = 0; i < d; ++i)
		_display.setColor(i,color_type(255,0,0),true);
	_display.show();
	delay(100);
	
}

void TinkerWatchImpl::update(){
	STOP_SKETCH_ON_EXCEPTION();
	
	_statusSwitcher.refresh();
	StatusSwitcher::status_type s = _statusSwitcher.status();
	if(s!=_currentStatus){
		_currentStatus = s;
		changeStatusAnimation();
	}
	switch(_currentStatus){
		case Compass: 			compass(); 			break;
		case Accellerometer: break;
		case GPS: break;
		case Clock: 			displayTime(); 		break;
		case Temperature:		displayTemperature(); break;
		case RandomAnimation: 	randomAnimation(); 	break;
	}
}