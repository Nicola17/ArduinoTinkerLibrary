#ifndef NEOPIXELCIRCULARDISPLAY_H
#define NEOPIXELCIRCULARDISPLAY_H

#include "ExternalLibsInc.h"
#include "Vect3d.h"
#include "AbstractLog.h"

namespace Tinker{

/***************************************************
 * AbstractLog - Abstract interface for any logger
 ***************************************************/

	template <uint16_t NPXL = 16>
	class NeoPixelCircularDisplay{
	public: 
		typedef Vect3d<float> fp_color_type;
		typedef Vect3d<uint8_t> color_type;
	public:
		NeoPixelCircularDisplay(uint8_t pin, uint8_t type=NEO_GRB+NEO_KHZ800):
			_log(0),
			_ring(NPXL,pin,type)
		{
			for(int i = 0; i < NPXL; ++i){
				_color[i] = 0;
				_toUpdate[i] = true;
			}
		}

		void init(); //initialize circular display
		void show(); //show current colors on display
		void reset();

		void setBrightness(uint8_t b);
		void setColor(color_type color, bool blend = false);
		void setColor(uint16_t idx, color_type color, bool blend = false);
		void setColorFp(float rad, color_type color, float sigma, bool blend = false);

		static float radBetweenPixels();

	private:
		uint16_t radToIdx(float rad)const;
		float radToFpIdx(float rad)const;
		float idxToRad(uint16_t idx)const;
		float idxToRad(uint16_t idx, float radRef)const;
		static float gauss(float x, float m, float s);

	private:
		fp_color_type _color[NPXL];
		bool _toUpdate[NPXL];
		Adafruit_NeoPixel _ring;
	public:
		AbstractLog* _log;
	};

/****************************************************/

	template <uint16_t NPXL>
	void NeoPixelCircularDisplay<NPXL>::init(){
		SECURE_LOG(_log,"Circular display initialization");
		_ring.begin();
	}

	template <uint16_t NPXL>
	void NeoPixelCircularDisplay<NPXL>::show(){
		SECURE_LOG(_log,"Circular display show");
		uint16_t updated(0);
		for(int i = 0; i < NPXL; ++i)
			if(_toUpdate[i]){
				_ring.setPixelColor(NPXL-i-1, min(_color[i][0],255), min(_color[i][1],255), min(_color[i][2],255));
				_toUpdate[i] = false;
				++updated;
			}
		_ring.show();
		SECURE_LOG_VAL(_log,"Updated pixels",updated);
	}
	
	template <uint16_t NPXL>
	void NeoPixelCircularDisplay<NPXL>::reset(){
		SECURE_LOG(_log,"Circular display reset");
		for(int i = 0; i < NPXL; ++i){
			_color[i] = color_type(0);
			_toUpdate[i] = true;
		}
	}

	template <uint16_t NPXL>
	void NeoPixelCircularDisplay<NPXL>::setBrightness(uint8_t b){
		SECURE_LOG_VAL(_log,"Circular display brightness",b);
		_ring.setBrightness(b);
	}

	template <uint16_t NPXL>
	void NeoPixelCircularDisplay<NPXL>::setColor(color_type color, bool blend){
		SECURE_LOG(_log,"Set color for a circular display");
		if(_log!=0){
			LOG::displayVect3d(color,_log); _log->endline();
		}
		for(int i = 0; i < NPXL; ++i){
			if(blend)
				_color[i] += color;
			else			
				_color[i] = color;
			_toUpdate[i] = true;
		}
	}

	template <uint16_t NPXL>
	void NeoPixelCircularDisplay<NPXL>::setColor(uint16_t idx, color_type color, bool blend){
		SECURE_LOG_VAL(_log,"Set color for a circular display - idx",idx);
		if(_log!=0){
			LOG::displayVect3d(color,_log); _log->endline();
		}
		if(blend)
			_color[idx] += color;
		else			
			_color[idx] = color;
		_toUpdate[idx] = true;
	}

	template <uint16_t NPXL>
	void NeoPixelCircularDisplay<NPXL>::setColorFp(float rad, color_type color, float sigma, bool blend){
//TODO - Optimization
		SECURE_LOG_VAL(_log,"Set color for a circular display - rad",rad);
		const	uint16_t nearestPxlIdx(radToIdx(rad)); 
		SECURE_LOG_VAL(_log,"Nearest pixel idx",nearestPxlIdx);
		const	float nearestPxlRad(idxToRad(nearestPxlIdx)); 
		SECURE_LOG_VAL(_log,"Nearest pixel rad",nearestPxlRad);

		for(int i = 0; i < NPXL; ++i){
			const float w(gauss(idxToRad(i,rad),rad,sigma));

			SECURE_LOG_VAL(_log,"W",w);
			if(blend)
				_color[i] += color*w;
			else
				_color[i] = color*w;
			_toUpdate[i] = true;
		}
	}

	template <uint16_t NPXL>
	uint16_t NeoPixelCircularDisplay<NPXL>::radToIdx(float rad)const{
		return static_cast<uint16_t>(rad/radBetweenPixels()+0.5)%NPXL;
	}
	template <uint16_t NPXL>
	float NeoPixelCircularDisplay<NPXL>::radToFpIdx(float rad)const{
		return rad/radBetweenPixels();
	}
	template <uint16_t NPXL>
	float NeoPixelCircularDisplay<NPXL>::radBetweenPixels(){
		return 2*PI/NPXL;
	}
	template <uint16_t NPXL>
	float NeoPixelCircularDisplay<NPXL>::gauss(float x, float m, float s){
		return exp(-(x-m)*(x-m)/(2*s*s));
	}
	template <uint16_t NPXL>
	float NeoPixelCircularDisplay<NPXL>::idxToRad(uint16_t idx)const{
		return idx*radBetweenPixels();
	}
	template <uint16_t NPXL>
	float NeoPixelCircularDisplay<NPXL>::idxToRad(uint16_t idx, float radRef)const{
//		return idx*radBetweenPixels();
		float rad = idx*radBetweenPixels();
		if(rad-radRef>PI)return rad-2*PI;
		if(rad-radRef<-PI)return rad+2*PI;
		return rad;
	}
}


#endif
