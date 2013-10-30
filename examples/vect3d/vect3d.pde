#include "Vect3d.h"
#include "SerialLog.h"

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
Tinker::SerialLog serialLog;

void setup(){
	Serial.begin(9600);
	serialLog.display("Vect3d Example");

	serialLog.endline();  serialLog.display("Constructor"); serialLog.endline();
	Tinker::LOG::displayVect3d(b0,&serialLog);
	serialLog.endline();
	Tinker::LOG::displayVect3d(b1,&serialLog);
	serialLog.endline();
	Tinker::LOG::displayVect3d(b2,&serialLog);
	serialLog.endline();
	Tinker::LOG::displayVect3d(f0,&serialLog);
	serialLog.endline();
	Tinker::LOG::displayVect3d(f1,&serialLog);
	serialLog.endline();
	Tinker::LOG::displayVect3d(f2,&serialLog);
	serialLog.endline();
	Tinker::LOG::displayVect3d(f3,&serialLog);
	serialLog.endline();

	//Copy 
	serialLog.endline();  serialLog.display("Copy"); serialLog.endline();
	f1 = b2;
	f0 = 1;
	Tinker::LOG::displayVect3d(f1,&serialLog);
	serialLog.endline();
	Tinker::LOG::displayVect3d(f0,&serialLog);
	serialLog.endline();

	//Test
	serialLog.endline();  serialLog.display("Test"); serialLog.endline();
	if(f1 == b2){
	 serialLog.display("f1 == b2"); serialLog.endline();
	}
	if(f3 != b2){
	 serialLog.display("f3 != b2"); serialLog.endline();
	}

	//Sum
	serialLog.endline();  serialLog.display("Sum"); serialLog.endline();
	Tinker::LOG::displayVect3d((f3+1),&serialLog); serialLog.endline();
	Tinker::LOG::displayVect3d((f3+Tinker::Vect3d<byte>(1,2,3)),&serialLog); serialLog.endline();
	b1+=1;
	Tinker::LOG::displayVect3d(b1,&serialLog); serialLog.endline();
	b1+=Tinker::Vect3d<float>(1.5,2.5,3.5);
	Tinker::LOG::displayVect3d(b1,&serialLog); serialLog.endline();

	//Sub
	serialLog.endline();  serialLog.display("Sub"); serialLog.endline();
	Tinker::LOG::displayVect3d((f3-1),&serialLog); serialLog.endline();
	Tinker::LOG::displayVect3d((f3-Tinker::Vect3d<byte>(1,2,3)),&serialLog); serialLog.endline();
	b1-=1;
	Tinker::LOG::displayVect3d(b1,&serialLog); serialLog.endline();
	b1-=Tinker::Vect3d<float>(1.5,2.5,3.5);
	Tinker::LOG::displayVect3d(b1,&serialLog); serialLog.endline();

	//Scalar Mul
	serialLog.endline();  serialLog.display("Scalar Mul"); serialLog.endline();
	Tinker::LOG::displayVect3d((f3*2.5),&serialLog); serialLog.endline();
	f2*=3;
	Tinker::LOG::displayVect3d(f2,&serialLog); serialLog.endline();
	  
	//Scalar Div
	serialLog.endline();  serialLog.display("Scalar Div"); serialLog.endline();
	Tinker::LOG::displayVect3d((f3/2.5),&serialLog); serialLog.endline();
	f2/=3;
	Tinker::LOG::displayVect3d(f2,&serialLog); serialLog.endline();
  
	//External functions
	serialLog.endline();  serialLog.display("External functions"); serialLog.endline();
	serialLog.display("NormL1("); Tinker::LOG::displayVect3d(f0,&serialLog);   serialLog.display(" - "); Tinker::LOG::displayVect3d(f1,&serialLog); serialLog.display("): ");
	serialLog.display(Tinker::normL1(f0-f1)); serialLog.endline();

	serialLog.display("NormL2("); Tinker::LOG::displayVect3d(f0,&serialLog);   serialLog.display(" - "); Tinker::LOG::displayVect3d(f1,&serialLog); serialLog.display("): ");
	serialLog.display(Tinker::normL2(f0-f1)); serialLog.endline();

	serialLog.display("dot("); Tinker::LOG::displayVect3d(f0,&serialLog);   serialLog.display(" - "); Tinker::LOG::displayVect3d(f1,&serialLog); serialLog.display("): ");
	serialLog.display(Tinker::dot(f0,f1)); serialLog.endline();

	serialLog.display("cross("); Tinker::LOG::displayVect3d(f3,&serialLog);   serialLog.display(" - "); Tinker::LOG::displayVect3d(f1,&serialLog); serialLog.display("): ");
	Tinker::LOG::displayVect3d(Tinker::cross(f3,f1),&serialLog); serialLog.endline();
  
}

void loop(){

}
