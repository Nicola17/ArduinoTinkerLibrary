#ifndef NEOPIXELCIRCULARDISPLAY_H
#define NEOPIXELCIRCULARDISPLAY_H

#include "Vect3d.h"

namespace Tinker{

/******************************************************************
 * CircularDisplayConcept - Concept for a generic circular display
 * a class with this signature could be used in every template 
 * advanced circular display (look at Vect2dCircularDisplay)
 ******************************************************************/

	class CircularDisplayConcept{
	public: 
		typedef Vect3d<float> fp_color_type;
		typedef Vect3d<uint8_t> color_type;
	public:
		void init(){} 	//initialize circular display
		void show(){} 	//show current colors on display
		void reset(){}	//reset colors;

		void setBrightness(uint8_t b){}
		void setColor(color_type color, bool blend = false){}
		void setColor(uint16_t idx, color_type color, bool blend = false){}
		void setColorFp(float rad, color_type color, float sigma, bool blend = false){}
	};
}


#endif