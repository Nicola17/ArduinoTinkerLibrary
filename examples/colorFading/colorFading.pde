#include <Vect3d.h>
#include <SerialLog.h>

Tinker::Vect3d<float> red(255,0,0);
Tinker::Vect3d<float> green(0,255,0);
Tinker::SerialLog serialLog;

void setup(){
  Serial.begin(9600);
  serialLog.display("Fade color example");  
  serialLog.endline();
}

void loop(){
  const uint32_t t   = millis()%10000;
  const float cosArg = t/10000.*3.1415*2;
  const float fade   = abs(cos(cosArg));

  Tinker::Vect3d<uint8_t> finalColor(red*fade + green*(1-fade));
  
  Tinker::LOG::displayVect3d(finalColor,&serialLog);
  serialLog.endline();
  delay(500);
}
