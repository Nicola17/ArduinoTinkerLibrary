#include "SerialLog.h"
#include "Timings.h"

/*******************************
 * Timings - test and example
 *******************************/

Tinker::SerialLog 		serialLog;
Tinker::AbstractLog* 		logPtr;

void setup(){
	Serial.begin(9600);
	serialLog.display("Timings example\n");

    logPtr = &serialLog;
    Tinker::Timer timer;

    timer.start();
    delay(5*Tinker::MILLISECOND_IN_A_SECOND);
    timer.stop();
        
    SECURE_LOG_VAL(logPtr,"Elapsed time (millisecond)", timer.elapsedTime(Tinker::Timer::Millisecond));
    SECURE_LOG_VAL(logPtr,"Elapsed time (second)",      timer.elapsedTime(Tinker::Timer::Second));
    SECURE_LOG_VAL(logPtr,"Elapsed time (minute)",      timer.elapsedTime(Tinker::Timer::Minute));
    SECURE_LOG_VAL(logPtr,"Elapsed time (hour)",        timer.elapsedTime(Tinker::Timer::Hour));
    SECURE_LOG_VAL(logPtr,"Elapsed time (day)",         timer.elapsedTime(Tinker::Timer::Day));
}


void loop(){
    const uint32_t nTest = 10000000;
    float elapsedTime;
    {
        Tinker::ScopedTimer timer(elapsedTime,Tinker::Timer::Millisecond);
        delay(500);
    }
    SECURE_LOG_VAL(logPtr,"Elapsed time:", elapsedTime);
}
