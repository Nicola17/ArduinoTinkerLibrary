#include "TinkerWatchImpl.h"

TinkerWatchImpl::TinkerWatchImpl():
	_switchPin(10),
	_ringPin(9),
	_display(9),
	_brightness(30),
	_nStatus(6),
	_currentStatus(0)
{}
	
void TinkerWatchImpl::initialize(){
	delay(5000);
	_statusSwitcher._log = &_serialLog;
	_statusSwitcher.switcher().setPin(_switchPin);
	_statusSwitcher.switcher().initialize(100,2000);
	_statusSwitcher.setNumberOfStatus(_nStatus);
	_statusSwitcher.setStatus(_currentStatus);
	
	
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
	color_type color(255,0,0);
	uint8_t nPxl(16);
	_display.reset();
	for(int i = 0; i < 16; ++i){
		_display.setColor(i,color);
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

void TinkerWatchImpl::update(){

	_statusSwitcher.refresh();
	StatusSwitcher::status_type s = _statusSwitcher.status();
	if(s!=_currentStatus){
		_currentStatus = s;
		changeStatusAnimation();
	}
	switch(_currentStatus){
		case Compass: break;
		case Accellerometer: break;
		case GPS: break;
		case Clock: break;
		case RandomAnimation: randomAnimation(); break;
	}
}