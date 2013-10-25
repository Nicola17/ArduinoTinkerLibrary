#ifndef ABSTRACTACTUATOR_H
#define ABSTRACTACTUATOR_H

#include <arduino.h>

namespace Tinker{

  /*********************************************
  * Abstract interface for a Digital Actuator
  *********************************************/
  class AbstractActuator{
  public:
    virtual void setEnabled(boolean v) = 0;
    virtual boolean enabled()const = 0;
  };

}

#endif
