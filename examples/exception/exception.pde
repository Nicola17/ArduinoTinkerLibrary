#include "Exception.h"
#include "ExceptionHandlers.h"
#include "SerialLog.h"
#include "DigitalActuator.h"

/*******************************
 * Exception - test and example
 *******************************/

Tinker::SerialLog 		serialLog;
Tinker::DigitalActuator led;

void setup(){
	Serial.begin(9600);
	serialLog.display("Exception example\n");
	
	led.setPin(13);
	led.initialize();

        
}

void runtimeError(){
	TNK_THROW_RUNTIME_RTN("We can handle it!");
}
void logicError(){
	TNK_ASSERT_RTN(millis()<10000,Tinker::Exception::Logic,"Maybe some bug?");
}

void loop(){
	STOP_SKETCH_ON_EXCEPTION();
	{
		Tinker::TryAndCatchOnDestruction<Tinker::SerialCatch> tryAndCatc;
		runtimeError();
	}
	{
		logicError();
		RETURN_ON_EXCEPTION();
	}
	led.setEnabled(true);
	delay(500);
	led.setEnabled(false);
	delay(500);
}