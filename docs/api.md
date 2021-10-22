# Vishay_VCNL4200 library

## Methods

### `begin()`

Initialize the vcnl4200.

#### Syntax 

```
vcnl4200.begin()
```

#### Parameters

None.

#### Returns

1 on success, 0 on failure.

#### Example

```
if (!vcnl4200.begin()) {
    Serial.println("Failed to initialize vcnl4200!");
    while (1);
}
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

### `end()`

De-initialize the vcnl4200.

#### Syntax 

```
vcnl4200.end()
```

#### Parameters

None.

#### Returns

None.

#### Example

```
if (!vcnl4200.begin()) {
    Serial.println("Failed to initialize vcnl4200!");
    while (1);
}

// Read data...

// Done with the vcnl4200 readings
vcnl4200.end();
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

### `read_PRX()`

Read the vcnl4200's Proximity sensor. 

#### Syntax 

```
boolean vcnl4200.read_PRX(uint16_t *prx)
```

#### Parameters

prx - point of uint16_t for proximity count.

#### Returns

true on success, false on failure.

#### Example

```
uint16_t prx;

if (vcnl4200.read_PRX(&prx))
    Serial.print(prx);

```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

### `read_ALS()`

Read the vcnl4200's Ambient Light sensor. 

#### Syntax 

```
boolean vcnl4200.read_ALS(uint16_t *als)
```

#### Parameters

als - point of uint16_t for ambient light count.

#### Returns

true on success, false on failure.

#### Example

```
uint16_t als;

if (vcnl4200.read_ALS(&als))
    Serial.print(als);

```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

### `get_lux()`

Read the vcnl4200's Ambient Light sensor and report to lux. 

#### Syntax 

```
float vcnl4200.get_lux()
```

#### Parameters

None.

#### Returns

Positive or zero on success, negative on failure.

#### Example

```
float lux = vcnl4200.get_lux();

if (lux >= 0)
    Serial.print(lux);

```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

### `ALS_SD()`

Shutdown/Enable Ambient Light sensor. 

#### Syntax 

```
boolean vcnl4200.ALS_SD(boolean shutdown)
```

#### Parameters

shutdown - true to Shut Down sensor, false to Power On sensor.

#### Returns

true on success, false on failure.

#### Example

```
// Power on Ambient Light sensor
vcnl4200.ALS_SD(false);
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

### `ALS_INT_EN()`

Enable/disable interrupt of Ambient Light sensor. 

#### Syntax 

```
boolean vcnl4200.ALS_INT_EN(boolean enable)
```

#### Parameters

enable - true to enable ALS interrupt, false to disable ALS interrupt.

#### Returns

true on success, false on failure.

#### Example

```
// Enable ALS interrupt
vcnl4200.ALS_INT_EN(true);
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

### `ALS_INT_with_threshold()`

Enable Ambient Light sensor interrupt and set threshold by percentage. 

#### Syntax 

```
boolean vcnl4200.ALS_INT_with_threshold(float percent)
```

#### Parameters

percent - set the +/- percentage of current Ambient Light counts.

#### Returns

true on success, false on failure.

#### Example

```
// Enable ALS interrupt with +/- 3.0% threshold
vcnl4200.ALS_INT_with_threshold(3.0f);
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

### `PRX_SD()`

Shutdown/Enable Proximity sensor. 

#### Syntax 

```
boolean vcnl4200.PRX_SD(boolean shutdown)
```

#### Parameters

shutdown - true to Shut Down sensor, false to Power On sensor.

#### Returns

true on success, false on failure.

#### Example

```
// Shut Down Proximity sensor
vcnl4200.PRX_SD(true);
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

### `PRX_INT()`

Set interrupt mode for Proximity sensor. 

#### Syntax 

```
boolean vcnl4200.PRX_INT(VCNL4200Sensor prx_int)
```

#### Parameters

prx_int - one of the followings: PRX_INT_DISABLE, PRX_INT_CLOSING, PRX_INT_AWAY, PRX_INT_BOTH

#### Returns

true on success, false on failure.

#### Example

```
// Enable PRX both Closing and Away interrupt
vcnl4200.ALS_INT_EN(vcnl4200.PRX_INT_BOTH);
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

### `PRX_INT_with_threshold()`

Enable Proximity sensor interrupt and set Low and High thresholds. 

#### Syntax 

```
boolean vcnl4200.PRX_INT_with_threshold(uint16_t thdl, uint16_t thdh)
```

#### Parameters

thdl - Low threshold.
thdh - High threshold.

#### Returns

true on success, false on failure.

#### Example

```
// Enable PRX interrupt at 50 low threshold and 100 high threshold.
vcnl4200.PRX_INT_with_threshold(50, 100);
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

### `read_INT_FLAG()`

Read to clean interrupt for VCNL4200.

#### Syntax 

```
boolean vcnl4200.read_INT_FLAG(uint16_t *int_flag)
```

#### Parameters

int_flag - point of uint16_t, it mixes by:
		ALS_IF_H for ALS High threshold event.
		ALS_IF_L for ALS High threshold event.
		PRX_IF_CLOSE for PRX Close event.
		PRX_IF_AWAY for PRX Away event.
		PRX_SPFLAG for PRX enter sunlight protection.
		PRX_UPFLAG for PRX code saturated.

#### Returns

true on success, false on failure.

#### Example

```
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
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)


### `lens_factor`

Lens Factor for customerize material effect. 

#### Syntax 

```
float vcnl4200.lens_factor
```

#### Parameters

None.

#### Returns

Floating variable.

#### Example

```
Serial.print(vcnl4200.lens_factor);
```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [ALS_SD()](#ALS_SD)
* [ALS_INT_EN()](#ALS_INT_EN)
* [ALS_INT_with_threshold()](#ALS_INT_with_threshold)
* [PRX_SD()](#PRX_SD)
* [PRX_INT()](#PRX_INT)
* [PRX_INT_with_threshold()](#PRX_INT_with_threshold)
* [read_INT_FLAG()](#read_INT_FLAG)
* [lens_factor](#lens_factor)

