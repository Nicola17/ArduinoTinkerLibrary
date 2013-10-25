#ifndef LIQUIDCRISTALLOG_H
#define LIQUIDCRISTALLOG_H

#include <AbstractLog.h>
#include "ExternalLibsInc.h"

namespace Tinker{

	class LiquidCrystalLog: public AbstractLog{
	public:
		LiquidCrystalLog(unsigned int delayTime = 500): 
			_delayTime(delayTime), 
			_lcd(12, 11, 5, 4, 3, 2)
		{
			_lcd.begin(16,2);
		}

		virtual void endline(){
			delay(_delayTime);
			_lcd.clear();
		}
		virtual void display(char* str){
			_lcd.print(str);
		}
		virtual void display(byte v){
			_lcd.print(v);
		}
		virtual void display(float v){
			_lcd.print(v);
		}
		virtual void display(double v){
			_lcd.print(v);
		}
		virtual void display(int v){
			_lcd.print(v);
		}
		virtual void display(unsigned int v){
			_lcd.print(v);
		}
		virtual void display(unsigned long v){
			_lcd.print(v);
		}

		virtual void clear(){
			_lcd.clear();
		};

	public: 
		unsigned int _delayTime;
		LiquidCrystal _lcd;
	
	};

}

#endif
