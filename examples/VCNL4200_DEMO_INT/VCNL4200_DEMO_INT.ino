/*
  This file is part of the Vishay_VEML6035 library.
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

/*
 * This demo requests to cnnect the INT pin of VCNL4200 to Digital Pin 2. 
 */
 
#include <Vishay_VCNL4200.h>

const byte interruptPin = 2;
volatile boolean interrupt_triggered = false;
float thd_percent = 10.0f;
uint16_t prx_away_threshold = 40;
uint16_t prx_close_threshold = 50;

void setup()
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println();

  if (!vcnl4200.begin())
  {
    Serial.println("Failed to initialize vcnl4200");
    while(1);
  }

  // Initial interrupt
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), isr, FALLING);
  uint16_t int_flag;
  vcnl4200.read_INT_FLAG(&int_flag);
  vcnl4200.ALS_INT_with_threshold(thd_percent);
  vcnl4200.PRX_INT_with_threshold(prx_away_threshold, prx_close_threshold);

  Serial.println("VCNL4200 ALS and PRX sensor");
}

void isr()
{
  interrupt_triggered = true;  
}

void loop()
{
  if (interrupt_triggered)
  {
    interrupt_triggered = false;
    uint16_t int_flag;
    if (vcnl4200.read_INT_FLAG(&int_flag))
    {
      if (int_flag & (vcnl4200.ALS_IF_L | vcnl4200.ALS_IF_H))
      {
        Serial.print("Lux = ");
        Serial.print(vcnl4200.get_lux());
        if (int_flag & vcnl4200.ALS_IF_L)
          Serial.print("\tLow threshold.");
        if (int_flag & vcnl4200.ALS_IF_H)
          Serial.print("\tHigh threshold.");
        Serial.println();
        // Re-set thresholds
        vcnl4200.ALS_INT_with_threshold(thd_percent);
      }
      if (int_flag & (vcnl4200.PRX_IF_CLOSE | vcnl4200.PRX_IF_AWAY))
      {
        uint16_t prx;
        vcnl4200.read_PRX(&prx);
        Serial.print("PRX = ");
        Serial.print(prx);
        if (int_flag & vcnl4200.PRX_IF_CLOSE)
          Serial.print("\tClose event.");
        if (int_flag & vcnl4200.PRX_IF_AWAY)
          Serial.print("\tAway event.");
        Serial.println();
      }
    }
  }
}