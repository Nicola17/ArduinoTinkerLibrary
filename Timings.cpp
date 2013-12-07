#include "Timings.h"
#include "Exception.h"

namespace Tinker{
  
    
    void Timer::start(){
        TNK_ASSERT_LOGIC_RTN(!_isRunning,"Timer already started");
        _startTimeStamp = millis();
    }

    void Timer::stop(){
        TNK_ASSERT_LOGIC_RTN(_isRunning,"Timer is not running");
        _stopTimeStamp = millis();
    }

    float Timer::elapsedTime(TimeUnit unit)const{
        TNK_ASSERT_LOGIC_RTNV(!_isRunning,"Timer is running", -1);
        const uint32_t elapsed(_stopTimeStamp-_startTimeStamp);
        switch(unit){
            case Millisecond:   return static_cast<float>(elapsed);
            case Second:        return static_cast<float>(elapsed)/MILLISECOND_IN_A_SECOND;
            case Minute:        return static_cast<float>(elapsed)/MILLISECOND_IN_A_MINUTE;
            case Hour:          return static_cast<float>(elapsed)/MILLISECOND_IN_AN_HOUR;
            case Day:           return static_cast<float>(elapsed)/MILLISECOND_IN_A_DAY;
            default:            TNK_THROW_LOGIC_RTNV("Invalid unit", -1);
        }
    }

    boolean Timer::isRunning()const{
        return _isRunning;
    }
	

}
