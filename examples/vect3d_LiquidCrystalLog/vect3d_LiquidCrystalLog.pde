#include "Vect3d.h"
#include "LiquidCrystalLog.h"
#include <LiquidCrystal.h> //I need to include it to avoid linker error

/*******************************
 * Vect3d - test and example
 *******************************/
Tinker::Vect3d<byte> b0; 
Tinker::Vect3d<byte> b1(128);
Tinker::Vect3d<byte> b2(64.5);
Tinker::Vect3d<float> f0;
Tinker::Vect3d<float> f1(1.f);
Tinker::Vect3d<float> f2(f1);
Tinker::Vect3d<float> f3(123,456,789);
Tinker::LiquidCrystalLog lcdLog;

void setup(){
	Serial.begin(9600);
	lcdLog.display("Vect3d Example");

	lcdLog.endline();  lcdLog.display("Constructor"); lcdLog.endline();
	Tinker::LOG::displayVect3d(b0,&lcdLog);
	lcdLog.endline();
	Tinker::LOG::displayVect3d(b1,&lcdLog);
	lcdLog.endline();
	Tinker::LOG::displayVect3d(b2,&lcdLog);
	lcdLog.endline();
	Tinker::LOG::displayVect3d(f0,&lcdLog);
	lcdLog.endline();
	Tinker::LOG::displayVect3d(f1,&lcdLog);
	lcdLog.endline();
	Tinker::LOG::displayVect3d(f2,&lcdLog);
	lcdLog.endline();
	Tinker::LOG::displayVect3d(f3,&lcdLog);
	lcdLog.endline();

	//Copy 
	lcdLog.endline();  lcdLog.display("Copy"); lcdLog.endline();
	f1 = b2;
	f0 = 1;
	Tinker::LOG::displayVect3d(f1,&lcdLog);
	lcdLog.endline();
	Tinker::LOG::displayVect3d(f0,&lcdLog);
	lcdLog.endline();

	//Test
	lcdLog.endline();  lcdLog.display("Test"); lcdLog.endline();
	if(f1 == b2){
	 lcdLog.display("f1 == b2"); lcdLog.endline();
	}
	if(f3 != b2){
	 lcdLog.display("f3 != b2"); lcdLog.endline();
	}

	//Sum
	lcdLog.endline();  lcdLog.display("Sum"); lcdLog.endline();
	Tinker::LOG::displayVect3d((f3+1),&lcdLog); lcdLog.endline();
	Tinker::LOG::displayVect3d((f3+Tinker::Vect3d<byte>(1,2,3)),&lcdLog); lcdLog.endline();
	b1+=1;
	Tinker::LOG::displayVect3d(b1,&lcdLog); lcdLog.endline();
	b1+=Tinker::Vect3d<float>(1.5,2.5,3.5);
	Tinker::LOG::displayVect3d(b1,&lcdLog); lcdLog.endline();

	//Sub
	lcdLog.endline();  lcdLog.display("Sub"); lcdLog.endline();
	Tinker::LOG::displayVect3d((f3-1),&lcdLog); lcdLog.endline();
	Tinker::LOG::displayVect3d((f3-Tinker::Vect3d<byte>(1,2,3)),&lcdLog); lcdLog.endline();
	b1-=1;
	Tinker::LOG::displayVect3d(b1,&lcdLog); lcdLog.endline();
	b1-=Tinker::Vect3d<float>(1.5,2.5,3.5);
	Tinker::LOG::displayVect3d(b1,&lcdLog); lcdLog.endline();

	//Scalar Mul
	lcdLog.endline();  lcdLog.display("Scalar Mul"); lcdLog.endline();
	Tinker::LOG::displayVect3d((f3*2.5),&lcdLog); lcdLog.endline();
	f2*=3;
	Tinker::LOG::displayVect3d(f2,&lcdLog); lcdLog.endline();
	  
	//Scalar Div
	lcdLog.endline();  lcdLog.display("Scalar Div"); lcdLog.endline();
	Tinker::LOG::displayVect3d((f3/2.5),&lcdLog); lcdLog.endline();
	f2/=3;
	Tinker::LOG::displayVect3d(f2,&lcdLog); lcdLog.endline();
  
	//External functions
	lcdLog.endline();  lcdLog.display("External functions"); lcdLog.endline();
	lcdLog.display("NormL1("); Tinker::LOG::displayVect3d(f0,&lcdLog);   lcdLog.display(" - "); Tinker::LOG::displayVect3d(f1,&lcdLog); lcdLog.display("): ");
	lcdLog.display(Tinker::normL1(f0,f1)); lcdLog.endline();

	lcdLog.display("NormL2("); Tinker::LOG::displayVect3d(f0,&lcdLog);   lcdLog.display(" - "); Tinker::LOG::displayVect3d(f1,&lcdLog); lcdLog.display("): ");
	lcdLog.display(Tinker::normL2(f0,f1)); lcdLog.endline();

	lcdLog.display("dot("); Tinker::LOG::displayVect3d(f0,&lcdLog);   lcdLog.display(" - "); Tinker::LOG::displayVect3d(f1,&lcdLog); lcdLog.display("): ");
	lcdLog.display(Tinker::dot(f0,f1)); lcdLog.endline();

	lcdLog.display("cross("); Tinker::LOG::displayVect3d(f3,&lcdLog);   lcdLog.display(" - "); Tinker::LOG::displayVect3d(f1,&lcdLog); lcdLog.display("): ");
	Tinker::LOG::displayVect3d(Tinker::cross(f3,f1),&lcdLog); lcdLog.endline();
  
}

void loop(){

}
