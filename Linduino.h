//! @todo Review this file.
/*
Linduino.h

This file contains the hardware definitions for the Linduino.

REVISION HISTORY
$Revision: 1906 $
$Date: 2013-08-26 15:09:18 -0700 (Mon, 26 Aug 2013) $

Copyright (c) 2013, Linear Technology Corp.(LTC)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of Linear Technology Corp.

The Linear Technology Linduino is not affiliated with the official Arduino team.
However, the Linduino is only possible because of the Arduino team's commitment
to the open-source community.  Please, visit http://www.arduino.cc and
http://store.arduino.cc , and consider a purchase that will help fund their
ongoing work.
*/

//! @defgroup Linduino Linduino: Linear Technology Arduino-Compatible Demonstration Board

/*! @file
    @ingroup Linduino
    @ingroup QuikEval
    Header File for Linduino Libraries and Demo Code
*/

#ifndef LINDUINO_H
#define LINDUINO_H

//! @name LINDUINO PIN ASSIGNMENTS
//! @{

#define QUIKEVAL_GPIO 9          //!< Linduino QuikEval GPIO pin (QuikEval connector pin 14) connects to Arduino pin 9
#define QUIKEVAL_CS SS           //!< QuikEval CS pin (SPI chip select on QuikEval connector pin 6) connects to Arduino SS pin.
#define QUIKEVAL_MUX_MODE_PIN 8  /*!< QUIKEVAL_MUX_MODE_PIN defines the control pin for the QuikEval MUX.
The I2C port's SCL and the SPI port's SCK signals share the same pin on the Linduino's QuikEval connector.
Additionally, the I2C port's SDA and the SPI port's MOSI signals share the same pin on the Linduino's QuikEval connector.
The pair of pins connected to the QuikEval connector is switched using a MUX on the Linduino board.
The control pin to switch the MUX is defined as QUIKEVAL_MUX_MODE_PIN (Arduino pin 8). */
//! @}

// Macros
//! Set "pin" low
//! @param pin pin to be driven LOW
#define output_low(pin)   digitalWrite(pin, LOW)
//! Set "pin" high
//! @param pin pin to be driven HIGH
#define output_high(pin)  digitalWrite(pin, HIGH)
//! Return the state of pin "pin"
//! @param pin pin to be read (HIGH or LOW).
//! @return the state of pin "pin"
#define input(pin)        digitalRead(pin)

//! @todo Make a note about whether Arduino/Linduino is Big Endian or Little Endian. Raspberry Pi appears to be the opposite.
//! This union splits one int16_t (16-bit signed integer) or uint16_t (16-bit unsigned integer)
//! into two uint8_t's (8-bit unsigned integers) and vice versa.
  union LT_union_int16_2bytes
  {
    int16_t LT_int16;    //!< 16-bit signed integer to be converted to two bytes
    uint16_t LT_uint16;  //!< 16-bit unsigned integer to be converted to two bytes
    uint8_t LT_byte[2];  //!< 2 bytes (unsigned 8-bit integers) to be converted to a 16-bit signed or unsigned integer
  };

//! @todo Make a note about whether Arduino/Linduino is Big Endian or Little Endian. Raspberry Pi appears to be the opposite.
//! This union splits one int32_t (32-bit signed integer) or uint32_t (32-bit unsigned integer)
//! into four uint8_t's (8-bit unsigned integers) and vice versa.
union LT_union_int32_4bytes
{
  int32_t LT_int32;    //!< 32-bit signed integer to be converted to four bytes
  uint32_t LT_uint32;  //!< 32-bit unsigned integer to be converted to four bytes
  uint8_t LT_byte[4];  //!< 4 bytes (unsigned 8-bit integers) to be converted to a 32-bit signed or unsigned integer
};

//! @todo Make a note about whether Arduino/Linduino is Big Endian or Little Endian. Raspberry Pi appears to be the opposite.
//! This union splits one float into four uint8_t's (8-bit unsigned integers) and vice versa.
union LT_union_float_4bytes
{
  float LT_float;      //!< float to be converted to four bytes
  uint8_t LT_byte[4];  //!< 4 bytes (unsigned 8-bit integers) to be converted to a float
};


#endif  // LINDUINO_H
