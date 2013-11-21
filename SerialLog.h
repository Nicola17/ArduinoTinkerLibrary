#ifndef SERIALLOG_H
#define SERIALLOG_H

namespace Tinker{

    //! Arduino serial logger
    /*!
        The SerialLog class is used to send any log on the Arduino Serial port
        \author Nicola Pezzotti
    */
    class SerialLog: public AbstractLog{
    public:
        //! Endline.
        virtual void endline(){
          Serial.println("");
        }
        //! Display a character array.
        virtual void display(char* str){
          Serial.print(str);
        }
        //! Display a byte value.
        virtual void display(byte v){
          Serial.print(v);
        }
        //! Display a float value.
        virtual void display(float v){
          Serial.print(v);
        }
        //! Display a double value.
        virtual void display(double v){
          Serial.print(v);
        }
        //! Display an integer value.
        virtual void display(int v){
          Serial.print(v);
        }
        //! Display an unsigned int value.
        virtual void display(unsigned int v){
          Serial.print(v);
        }
        //! Display an unsigned long value.
        virtual void display(unsigned long v){
          Serial.print(v);
        }
        //! Clear the logger.
        /*!
            \warning Is not possibile to to clear data on Serial.
        */
        virtual void clear(){}; 
    };

}

#endif
