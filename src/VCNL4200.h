/*
  This file is part of the Vishay_VCNL4200 library.
  Copyright (c) 2021 Vishay Capella.  All rights reserved.

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
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Arduino.h>
#include <Wire.h>

class VCNL4200Class {
  public:
    VCNL4200Class(TwoWire& wire);
    virtual ~VCNL4200Class();

    int begin();
    void end();
    long read( uint8_t reg);
    int write( uint8_t reg, uint16_t data);
    virtual long read_PRX(void);
    virtual long read_ALS(void);
    virtual float get_lux(void);
    float lens_factor;

  private:
    TwoWire* _wire;
    uint8_t slaveAddress;  
};

extern VCNL4200Class vcnl4200;
