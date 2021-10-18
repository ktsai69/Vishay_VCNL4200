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
* [lens_factor](#lens_factor)

### `read_PRX()`

Read the vcnl4200's Proximity sensor. 

#### Syntax 

```
vcnl4200.read_PRX()
```

#### Parameters

None.

#### Returns

Positive or zero on success, negative on failure.

#### Example

```
long prx = vcnl4200.read_PRX();

if (prx >= 0)
    Serial.print(prx);

```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [lens_factor](#lens_factor)

### `read_ALS()`

Read the vcnl4200's Ambient Light sensor. 

#### Syntax 

```
vcnl4200.read_ALS()
```

#### Parameters

None.

#### Returns

Positive or zero on success, negative on failure.

#### Example

```
long als = vcnl4200.read_ALS();

if (als >= 0)
    Serial.print(als);

```

#### See also

* [begin()](#begin)
* [end()](#end)
* [read_PRX()](#read_PRX)
* [read_ALS()](#read_ALS)
* [get_lux()](#get_lux)
* [lens_factor](#lens_factor)

### `get_lux()`

Read the vcnl4200's Ambient Lioght sensor and convert to lux. 

#### Syntax 

```
vcnl4200.get_lux()
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
* [lens_factor](#lens_factor)

### `lens_factor`

Lens Factor for customerize material effect. 

#### Syntax 

```
vcnl4200.lens_factor
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
* [lens_factor](#lens_factor)

