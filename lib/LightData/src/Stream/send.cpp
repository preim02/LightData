#include "LDStream.h"
#include <Arduino.h>
namespace LD
{

    //functions still undefined -> still need to be defined

    /*sending Functions*/
    void LDStream::send(char Data)
    {
        if (LDStream::transmit)
        {
            unsigned int delay = 1000000/LDStream::Speed; //calculate from frequency in Hz to T in microseconds (T=1/f)
            for (int i = 0; i < 8; i++)
            {
                digitalWrite(LDStream::transmitPin, Data&0b10000000 ); //if the most significant bit is 1 then a high else send a low
                Data <<= 1; //shift to the right to read form the most significant bit to the least significant bit
                delayMicroseconds(delay);
            }
        }
    }

} // namespace LD