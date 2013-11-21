#ifndef TIMEOUT_H
#define TIMEOUT_H

#include "AbstractLog.h"
#include <Arduino.h>

namespace Tinker{
  //! A class to handle timeout events
  /*!
	This class permits to handle in an easy way any timeout event
	\author Nicola Pezzotti
  */
  class Timeout{
  public:
	//! Creates an empty timeout. 
	/*!
		The timeout will be set to 0. Use setTimeout() to specify a timeout threshold
	*/
    Timeout():_timeout(0),_lastRefresh(0){}
	//!Sets a timeout threshold in milliseconds.
	/*!
		\param timeout threshold in milliseconds
	*/
	void setTimeout(unsigned long timeout){_timeout = timeout;}
	//!Returns current timeout threshold.
	/*!
		\return threshold in milliseconds
	*/
    unsigned long timeout()const{return _timeout;}
    
	//! Refreshes the timeout
	/*!
		Resets the counter avoiding the timeout to be reached
	*/
    void refresh();
	
	//! Returns true if timeout is reached
    bool timeoutReached()const;
   
	//! Returns the timer's remaining value in milliseconds left until the timeout.
    unsigned long timeToTimeout()const;
	//! Returns the elapsed time from last refresh
    unsigned long timeElapsedFromLastRefresh()const;
	
	//! Returns the percentage of the timeout
	/*!
		Varies from 0 to 1. \n
		0 -> timeout refreshed\n
		1 -> timeout reached
	*/
    float percentage()const;
  
  private:
    unsigned long _timeout;
    unsigned long _lastRefresh; 
  };	
}

#endif
