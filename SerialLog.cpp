#include "SerialLog.h"

namespace Tinker{

	void SerialLog::endline(){
	  Serial.println("");
	}
	void SerialLog::display(char* str){
	  Serial.print(str);
	}
	void SerialLog::display(byte v){
	  Serial.print(v);
	}
	void SerialLog::display(float v){
	  Serial.print(v);
	}
	void SerialLog::display(double v){
	  Serial.print(v);
	}
	void SerialLog::display(int v){
	  Serial.print(v);
	}
	void SerialLog::display(unsigned int v){
	  Serial.print(v);
	}
	void SerialLog::display(unsigned long v){
	  Serial.print(v);
	}
	void SerialLog::clear(){
	}

}