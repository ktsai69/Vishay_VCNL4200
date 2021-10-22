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
    boolean read(uint8_t reg, uint16_t *data);
    boolean write( uint8_t reg, uint16_t data);
    virtual boolean read_PRX(uint16_t *prx);
    virtual boolean read_ALS(uint16_t *als);
    virtual float get_lux(void);
    boolean ALS_SD(boolean shutdown);
    boolean ALS_INT_EN(boolean enable);
    boolean ALS_INT_with_threshold(float percent);
    boolean PRX_SD(boolean shutdown);
    boolean PRX_INT(uint16_t prx_int);
    boolean PRX_INT_with_threshold(uint16_t thdl, uint16_t thdh);
    boolean read_INT_FLAG(uint16_t *int_flag);
    float lens_factor;
    const uint16_t
      PRX_IF_AWAY = (1 << 8),
      PRX_IF_CLOSE = (1 << 9),
      ALS_IF_H = (1 << 12),
      ALS_IF_L = (1 << 13),
      PRX_SPFLAG = (1 << 14),
      PRX_UPFLAG = (1 << 15);
    const uint16_t
      PRX_INT_DISABLE = 0,
      PRX_INT_CLOSING = 1,
      PRX_INT_AWAY = 2,
      PRX_INT_BOTH = 3;
    
  private:
    TwoWire* _wire;
    uint8_t slaveAddress;
    boolean bitsUpdate(uint8_t reg, uint16_t mask, uint16_t update);  
};

extern VCNL4200Class vcnl4200;
