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

#include "VCNL4200.h"

#define VCNL4200_ADDRESS            0x51
#define VCNL4200_WHO_AM_I           0x58

#define VCNL4200_REG_ALS_CONF       0x00
#define VCNL4200_REG_ALS_THDH       0x01
#define VCNL4200_REG_ALS_THDL       0x02
#define VCNL4200_REG_PRX_CONF       0x03
#define VCNL4200_REG_PRX_CONF3      0x04
#define VCNL4200_REG_PRX_CANC       0x05
#define VCNL4200_REG_PRX_THDL       0x06
#define VCNL4200_REG_PRX_THDH       0x07
#define VCNL4200_REG_PRX_DATA       0x08
#define VCNL4200_REG_ALS_DATA       0x09
#define VCNL4200_REG_WHITE_DATA     0x0A
#define VCNL4200_REG_ID             0x0E

#define VCNL4200_ALS_IT_SHIFT       6
#define VCNL4200_ALS_IT_MASK        (0x3 << VCNL4200_ALS_IT_SHIFT)
#define VCNL4200_ALS_IT_50MS        (0x0 << VCNL4200_ALS_IT_SHIFT)
#define VCNL4200_ALS_IT_100MS       (0x1 << VCNL4200_ALS_IT_SHIFT)
#define VCNL4200_ALS_IT_200MS       (0x2 << VCNL4200_ALS_IT_SHIFT)
#define VCNL4200_ALS_IT_400MS       (0x3 << VCNL4200_ALS_IT_SHIFT)

#define VCNL4200_PRX_IT_SHIFT       1
#define VCNL4200_PRX_IT_MASK        (0x7 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_1T          (0x0 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_1_5T        (0x1 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_2T          (0x2 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_4T          (0x3 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_8T          (0x4 << VCNL4200_PRX_IT_SHIFT)
#define VCNL4200_PRX_IT_9T          (0x5 << VCNL4200_PRX_IT_SHIFT)

#define VCNL4200_DEFAULT_ALS_CONF   (VCNL4200_ALS_IT_100MS)
#define VCNL4200_DEFAULT_ALS_THDH   0x0000
#define VCNL4200_DEFAULT_ALS_THDL   0xFFFF
#define VCNL4200_DEFAULT_PRX_CONF   (VCNL4200_PRX_IT_2T)
#define VCNL4200_DEFAULT_PRX_CONF3  0x0000
#define VCNL4200_DEFAULT_PRX_CANC   0x0000
#define VCNL4200_DEFAULT_PRX_THDL   0x0000
#define VCNL4200_DEFAULT_PRX_THDH   0xFFFF

VCNL4200Class::VCNL4200Class(TwoWire& wire) :
  _wire(&wire)
{
}

VCNL4200Class::~VCNL4200Class()
{
}

VCNL4200Class::begin()
{
  _wire->begin();
  slaveAddress = VCNL4200_ADDRESS;
  
  int id = read(VCNL4200_REG_ID);
  if (id < 0 || (id & 0xFF) != VCNL4200_WHO_AM_I)
	  return 0;
  
  // Initialization
  write(VCNL4200_REG_ALS_CONF, VCNL4200_DEFAULT_ALS_CONF);
  write(VCNL4200_REG_ALS_THDH, VCNL4200_DEFAULT_ALS_THDH);
  write(VCNL4200_REG_ALS_THDL, VCNL4200_DEFAULT_ALS_THDL);
  write(VCNL4200_REG_PRX_CONF, VCNL4200_DEFAULT_PRX_CONF);
  write(VCNL4200_REG_PRX_CONF3, VCNL4200_DEFAULT_PRX_CONF3);
  write(VCNL4200_REG_PRX_CANC, VCNL4200_DEFAULT_PRX_CANC);
  write(VCNL4200_REG_PRX_THDL, VCNL4200_DEFAULT_PRX_THDL);
  write(VCNL4200_REG_PRX_THDH, VCNL4200_DEFAULT_PRX_THDH);
  lens_factor = 1.0;
  
  return 1;
}

int VCNL4200Class::read(uint8_t reg)
{
  uint8_t   wd;
  uint16_t  data;

  _wire->beginTransmission(slaveAddress);
  if (_wire->write (reg) != 1)
    goto read_error;
  _wire->endTransmission(false);
  if (_wire->requestFrom(slaveAddress, (uint8_t)2) != 2)
    goto read_error;
  
  wd = 10;
  while (_wire->available()<2 && wd)
    wd--;
  if (!wd)
    goto read_error;
  
  data = _wire->read();
  data |= _wire->read() << 8;
  return data;

read_error:
  _wire->endTransmission(true);
  return -1;
}

int VCNL4200Class::write(uint8_t reg, uint16_t data)
{
  int status = 1;
  
  _wire->beginTransmission(slaveAddress);
  if ((_wire->write(reg) == 1) &&
      (_wire->write((uint8_t)(data & 0xFF)) == 1) &&
      (_wire->write((uint8_t)((data >> 8) & 0xFF)) == 1))
      status = -1;
  _wire->endTransmission(true);

  return status;
}

int VCNL4200Class::read_PRX(void)
{
  return read(VCNL4200_REG_PRX_DATA);
}

int VCNL4200Class::read_ALS(void)
{
  return read(VCNL4200_REG_ALS_DATA);
}

float VCNL4200Class::get_lux(void)
{
  int als;
  float lux;
  float resolution[] = {0.024f, 0.012f, 0.006f, 0.003f};
  int als_conf = read(VCNL4200_REG_ALS_CONF);
  uint16_t als_it = 0x0000;
  if (als_conf >= 0)
  {
    als_it = (uint16_t)als_conf;
    als_it &= VCNL4200_ALS_IT_MASK;
    als_it >>= VCNL4200_ALS_IT_SHIFT;
  }
    
  als = read_ALS();
  if (als >= 0)
  {
    lux = (float)als;
    lux *= resolution[als_it];
    lux *= lens_factor;
    return lux;
  }
  return (float)als;
}

VCNL4200Class vcnl4200(Wire);
