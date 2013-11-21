#ifndef SERIALLOG_H
#define SERIALLOG_H

#include "AbstractLog.h"

namespace Tinker{
    //! Arduino serial logger
    /*!
        The SerialLog class is used to send any log on the Arduino Serial port
        \author Nicola Pezzotti
    */
    class SerialLog: public AbstractLog{
    public:
        //! Endline.
        virtual void endline();
        //! Display a character array.
        virtual void display(char* str);
        //! Display a byte value.
        virtual void display(byte v);
        //! Display a float value.
        virtual void display(float v);
        //! Display a double value.
        virtual void display(double v);
        //! Display an integer value.
        virtual void display(int v);
        //! Display an unsigned int value.
        virtual void display(unsigned int v);
        //! Display an unsigned long value.
        virtual void display(unsigned long v);
        //! Clear the logger.
        /*!
            \warning Is not possibile to to clear data on Serial.
        */
        virtual void clear(); 
    };
}

#endif
