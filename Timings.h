#ifndef TIMINGS_H
#define TIMINGS_H

#include <Arduino.h>

namespace Tinker{

    const uint32_t MILLISECOND_IN_A_SECOND  = 1000;
    const uint32_t MILLISECOND_IN_A_MINUTE  = 60000;
    const uint32_t MILLISECOND_IN_AN_HOUR   = 3600000;
    const uint32_t MILLISECOND_IN_A_DAY     = 43200000;

    //! A timer
    /*!
    This class permits to measure time elapsed between two timestamps
    \author Nicola Pezzotti
    */
    class Timer{
    public:
        enum TimeUnit{Millisecond, Second, Minute, Hour, Day};
    public:
	    //! Creates an empty timer. 
        Timer():_startTimeStamp(0),_stopTimeStamp(0),_isRunning(false){}
	    //! Starts the timer.
        void start();
	    //! Stops the timer.
        void stop();
        //! Returns the elapsed time.
        /*!
            \warning Timer must be stopped
        */
        float elapsedTime(TimeUnit unit = Millisecond)const;
        //!Returns timer status
        boolean isRunning()const;
  
    private:
        uint32_t _startTimeStamp;
        uint32_t _stopTimeStamp; 
        boolean _isRunning;
    };

    //! A scoped timer
    /*!
    This class permits to measure time elapsed between this object creation and destruction
    \author Nicola Pezzotti
    */
    class ScopedTimer{
    public:
	    //! Creates the scoped timer. 
        ScopedTimer(float& time, Timer::TimeUnit unit = Timer::Millisecond);
	    //! Destroys the scoped timer and compute the elapsed time. 
        ~ScopedTimer();
	
    private:
        float&          _time;
        Timer::TimeUnit _unit;
        Timer           _timer;
    };	


}

#endif
