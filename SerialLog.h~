#ifndef SERIALLOG_H
#define SERIALLOG_H

#include "AbstractLog.h"

namespace Tinker{

  class SerialLog: public AbstractLog{
  public:
    virtual void endline(){
      Serial.println("");
    }
    virtual void display(char* str){
      Serial.print(str);
    }
    virtual void display(byte v){
      Serial.print(v);
    }
    virtual void display(float v){
      Serial.print(v);
    }
    virtual void display(double v){
      Serial.print(v);
    }
    virtual void display(int v){
      Serial.print(v);
    }
    virtual void display(unsigned int v){
      Serial.print(v);
    }
    virtual void display(unsigned long v){
      Serial.print(v);
    }
    
    virtual void clear(){}; //Is not possibile to to clear data on Serial
  };

}

#endif
