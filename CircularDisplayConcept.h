#ifndef NEOPIXELCIRCULARDISPLAY_H
#define NEOPIXELCIRCULARDISPLAY_H

#include "Vect3d.h"

namespace Tinker{

    //! Concept for a circular display
    /*!
        A class with this signature could be used as a template parameter to any class which display data on a circular indicator
        \see Vect2dCircularDisplay
        \author Nicola Pezzotti
    */
	class CircularDisplayConcept{
	private: 
		typedef Vect3d<float> fp_color_type;
    public:
		typedef Vect3d<uint8_t> color_type;
	public:
        //! Initialize circular display
		void init(){}
        //! Shows current colors on display
		void show(){} 	
        //! Resets colors
		void reset(){}
        //! Sets brightness of the display
        /*!
            \param b Brightness
        */
		void setBrightness(uint8_t b){}
        //! Sets color on all circular display
        /*!
            \param color color to set
            \param blend color with the existing ones
        */
		void setColor(color_type color, bool blend = false){}
        //! Sets color for a circular elements
        /*!
            \param idx index of circular element
            \param color color to set
            \param blend color with the existing ones
        */
		void setColor(uint16_t idx, color_type color, bool blend = false){}
        //! Sets color on ciruclar display
        /*!
            Display color with a gaussian distribution
            \param rad mean value in radians of the gaussian distribution
            \param sigma of the gaussian distribution
            \param color color to set
            \param blend color with the existing ones
        */
		void setColorFp(float rad, color_type color, float sigma, bool blend = false){}
	};
}


#endif