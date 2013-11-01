#ifndef VECT2DCIRCULARDISPLAY_H
#define VECT2DCIRCULARDISPLAY_H

#include "AbstractLog.h"
#include "Vect2d.h"

/*****************************************************************
 * Template class for the visualization of a Vect2d on a Display
 * Display should be an implementation of CircularDisplayConcept
 *****************************************************************/

namespace Tinker{

	template <class Display, uint16_t NCLRS=1>
	class Vect2dCircularDisplay{
	public: 
		typedef typename Display::fp_color_type 	fp_color_type;
		typedef typename Display::color_type 		color_type;
	public:
		Vect2dCircularDisplay(uint8_t pin, uint8_t type=NEO_GRB+NEO_KHZ800);
		void init(float minVal, float maxVal, float minSigma, float maxSigma, float minBright, float maxBright);
		void setValueRange(float minVal, float maxVal);
		void setSigmaRange(float minSigma, float maxSigma);
		void setBrightRange(float minBright, float maxBright);
		void setColor(int idx, const color_type& color);
		void show(const Vect2d<float>& v);
	
	private:
		Display _display;
		float _minVal;
		float _maxVal;
		float _minSigma;
		float _maxSigma;
		float _minBright;
		float _maxBright;
		color_type _colors[NCLRS];
		
	public:
		AbstractLog* _log;
	};
	
/**************************************************************/

	template <class Display, uint16_t NCLRS>
	Vect2dCircularDisplay<Display,NCLRS>::Vect2dCircularDisplay(uint8_t pin, uint8_t type):
		_display(pin, type),
		_log(0)
	{
		for(int i = 0; i < NCLRS; ++i)
			_colors[i] = color_type(0,0,255);
	}
	template <class Display, uint16_t NCLRS>
	void Vect2dCircularDisplay<Display,NCLRS>::init(float minVal, float maxVal, float minSigma, float maxSigma, float minBright, float maxBright){
		_display.init();
		setValueRange(minVal,maxVal);
		setSigmaRange(minSigma,maxSigma);
		setBrightRange(minBright,maxBright);
	}
	
	template <class Display, uint16_t NCLRS>
	void Vect2dCircularDisplay<Display,NCLRS>::setValueRange(float minVal, float maxVal){
		SECURE_LOG_VAL(_log,"New min val",minVal);
		SECURE_LOG_VAL(_log,"New max val",maxVal);
		_minVal = minVal;
		_maxVal = maxVal;
	}
	template <class Display, uint16_t NCLRS>
	void Vect2dCircularDisplay<Display,NCLRS>::setSigmaRange(float minSigma, float maxSigma){
		SECURE_LOG_VAL(_log,"New min sigma",minSigma);
		SECURE_LOG_VAL(_log,"New max sigma",maxSigma);
		_minSigma = minSigma;
		_maxSigma = maxSigma;
	}
	template <class Display, uint16_t NCLRS>
	void Vect2dCircularDisplay<Display,NCLRS>::setBrightRange(float minBright, float maxBright){
		SECURE_LOG_VAL(_log,"New min brightness",minBright);
		SECURE_LOG_VAL(_log,"New max brightness",maxBright);
		_minBright = minBright;
		_maxBright = maxBright;
	}
	template <class Display, uint16_t NCLRS>
	void Vect2dCircularDisplay<Display,NCLRS>::setColor(int idx, const color_type& color){
		if(idx>=NCLRS){
			SECURE_LOG(_log,"ALERT!!! Invalid index");
			return;
		}
		SECURE_LOG_VAL(_log,"New color - idx",idx);
		_colors[idx] = color;
	}
	template <class Display, uint16_t NCLRS>
	void Vect2dCircularDisplay<Display,NCLRS>::show(const Vect2d<float>& v){
	//TODO - direction
		SECURE_LOG(_log,"Display a Vector on a 2D circular Display");
		const float l(normL2(v));
		SECURE_LOG_VAL(_log,"NormL2",l);
		if(l < _minVal || l>= _maxVal){
			SECURE_LOG(_log,"Vector lenght out of range");
			_display.reset();
			_display.show();
			return;
		}
		float rad = atan2(v[0],v[1]);
		SECURE_LOG_VAL(_log,"rad",rad);
		
		const float f((l-_minVal)/(_maxVal-_minVal));
		SECURE_LOG_VAL(_log,"f",f);
		const float bright	(_minBright + f*(_maxBright-_minBright));
		SECURE_LOG_VAL(_log,"bright",bright);
		const float sigma	(_minSigma 	+ f*(_maxSigma-_minSigma));
		SECURE_LOG_VAL(_log,"sigma",sigma);
		
		if(NCLRS == 1){
			_display.setColorFp(rad,_colors[0],sigma, false);
			_display.setBrightness(bright);
		}else{
			const float fpColorIdx(f*(NCLRS-1));
			const int intColorIdx(static_cast<int>(fpColorIdx));
			const float s(fpColorIdx-intColorIdx);
			const color_type color = _colors[intColorIdx]*(1-s)+_colors[intColorIdx+1]*(s);
			
			const float colorNorm(normL2(color));
			SECURE_LOG_VAL(_log,"Color norm",colorNorm);
			const float normalizedBright(255.*bright/colorNorm);
			SECURE_LOG_VAL(_log,"Normalized brightness",normalizedBright);
			
			_display.setBrightness(bright);
			_display.setColorFp(rad,color,sigma, false);
		
		}
		_display.show();
	}

}

#endif