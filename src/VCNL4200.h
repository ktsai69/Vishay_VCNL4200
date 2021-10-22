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

enum VCNL4200Sensor {NONE, ALS=1, PRX=2, ALSPRX};
enum VCNL4200PRX_INT {Disable=0, Closing, Away, Both};

class VCNL4200Class {
  public:
    VCNL4200Class(TwoWire& wire);
    virtual ~VCNL4200Class();

    int begin();
    void end();
    boolean read(uint8_t reg, uint16_t *data);
    boolean write( uint8_t reg, uint16_t data);
    virtual boolean read_PRX(uint16_t *prx);
    virtual boolean read_ALS(uint16_t *als);
    virtual float get_lux(void);
    boolean ALS_SD(boolean shutdown);
    boolean ALS_INT_EN(boolean enable);
    boolean ALS_INT_with_threshold(float percent);
    boolean PRX_SD(boolean shutdown);
    boolean PRX_INT(VCNL4200PRX_INT prx_int);
    boolean PRX_INT_with_threshold(uint16_t thdl, uint16_t thdh);
    VCNL4200Sensor clean_INT(uint8_t *flag);
    float lens_factor;

    const uint8_t
      PRX_IF_AWAY = (1 << 0),
      PRX_IF_CLOSE = (1 << 1),
      ALS_IF_H = (1 << 2),
      ALS_IF_L = (1 << 3);
    
  private:
    TwoWire* _wire;
    uint8_t slaveAddress;
    boolean bitsUpdate(uint8_t reg, uint16_t mask, uint16_t update);  
};

extern VCNL4200Class vcnl4200;
