#ifndef ABSTRACTSENSOR_H
#define ABSTRACTSENSOR_H

#include <arduino.h>

namespace Tinker{

  class AbstractSensor{
  public:
    virtual float value()=0;
  };

}

#endif
