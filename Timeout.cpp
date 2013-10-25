#include "Timeout.h"

namespace Tinker{
  
  void Timeout::refresh(){
     _lastRefresh = millis(); 
  }	
         
  bool Timeout::timeoutReached()const{
    return (timeToTimeout() == 0);
  }
  unsigned long Timeout::timeToTimeout()const{
    const unsigned long t = millis();	
    const long v(_lastRefresh + _timeout - t);
    if(v>0)
    return v;
    return 0;
  }
  unsigned long Timeout::timeElapsedFromLastRefresh()const{
    const unsigned long t = millis();
    return t - _lastRefresh;
  }
  float Timeout::percentage()const{
    float v(float(timeElapsedFromLastRefresh())/_timeout);
    if(v < 1)
      return v;
    return 1;
  }

}
