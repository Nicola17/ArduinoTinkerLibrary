#ifndef TIMEOUT_H
#define TIMEOUT_H

#include "AbstractLog.h"

namespace Tinker{
  
  class Timeout{
  public:
    Timeout():_timeout(0),_lastRefresh(0){}
    void setTimeout(float timeout){_timeout = timeout;}
    float timeout()const{return _timeout;}
    
    void refresh();
    bool timeoutReached()const;
         
    unsigned long timeToTimeout()const;
    unsigned long timeElapsedFromLastRefresh()const;
    float percentage()const;
  
  private:
    float _timeout;
    unsigned long _lastRefresh; 
  };	
}

#endif
