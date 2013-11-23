
#include "Exception.h"
#include "ExceptionHandlers.h"
#include "SerialLog.h"
#include "MagneticSensorLSM303.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303.h>

/*********************************************
 * Magnetic Sensor LSM303 - test and example
 *********************************************/

Tinker::SerialLog 				serialLog;
Tinker::MagneticSensorLSM303	magSensor;

void setup(){
	Serial.begin(9600);
	serialLog.display("Magnetic sensor example\n");

	magSensor.initialize();
	STOP_SKETCH_ON_EXCEPTION();     
}

void loop(){
	STOP_SKETCH_ON_EXCEPTION();
	const Tinker::Vect3d<float> readings(magSensor.value());
	serialLog.display("Vect3d: "); Tinker::LOG::displayVect3d(readings,&serialLog);serialLog.endline();
	serialLog.display("Intensity: "); serialLog.display(Tinker::normL2(readings)); serialLog.endline();
	delay(200);
}