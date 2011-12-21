/*
  IOexpander.h
  12-02-2011
  Copyright (c) 2011 Koen Warffemius.  All right reserved. www.koenwar.nl

 +This class provides a easy to use interface to a MCP23016 i2c Pin expander.
 +The MCP23016 provides 16 digital IO ports.
 +The interface of this class looks as much the same as the default IO functions of the arduino
 +This class uses the Wire librarie for the i2c communication.

  versions:
  08-02-2011 – start of the project
  19-02-2011 – v0.2 intial release
  20-02-2011 - v0.3 improvements submitted by robtillaart, support added for the MCP23017 and MCP23018 (not tested yet)
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef IOlcd_h
#define IOlcd_h

#include <Wire.h>;
#include <inttypes.h>
//#include "Print.h"

#define ALL_OUTPUT 0x00
#define ALL_INPUT 0xFF
#define ALL_LOW 0x00
#define ALL_HIGH 0xFF
#define MCP23016 1
#define MCP23017 2
#define MCP23018 3

#define Lcd_clear 0x01
#define Lcd_blinkCursor 0x0f
#define Lcd_noBlinkCursor 0x0c
#define Lcd_home 0x02
#define Lcd_scrollDisplayLeft 0x18
#define Lcd_scrollDisplayRight 0x1c

class IOlcd
{
  private:
    uint8_t addr;
	uint8_t REGISTER_GP0;
	uint8_t REGISTER_IODIR0;
	
	uint8_t regPort0;
	uint8_t regPort1;
	uint8_t port0;
	uint8_t port1;
	
	bool refresh();
	bool sendData();
	void writeCommand(uint8_t command);
	int byteShift(int num);
	
  public:
    IOlcd();
	void home();
	void noBlinkCursor();
	void blinkCursor();
	void clear();
	void scrollDisplayLeft();
	void scrollDisplayRight();
	void begin(uint8_t cols, uint8_t lines);
	void print(char* arrayc);
	void print(int arrayc);
	void write(uint8_t c);
	void setCursor(uint8_t x, uint8_t y);
	
    bool init(uint8_t address, uint8_t device_type);
	bool pinMode(uint8_t port, uint8_t pin, bool mode);
	bool pinModePort(uint8_t port, bool mode);
};

#endif

