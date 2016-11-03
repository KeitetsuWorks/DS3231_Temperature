DS3231 Temperature Register Access Program
========

## Description
The C Program to Get Temperature from DS3231 RTC Module.

## Requirement for Raspberry Pi
### Hardware
* [Raspberry Pi](https://www.raspberrypi.org/products/raspberry-pi-3-model-b/)
* [DS3231 RTC Module for Raspberry Pi](http://www.amazon.co.jp/exec/obidos/ASIN/B00KB10VIO/keitetsu-22/ref=nosim/)

### Software
* [Raspbian](https://www.raspberrypi.org/downloads/raspbian/)
* [I2C Device Register Access Functions for Linux](https://github.com/KeitetsuWorks/I2C_Linux)

## Usage
### Get the DS3231 Temperature
    $ ./bin/DS3231_Temperature

## Installation
1. Download DS3231_Temperature

        $ git clone https://github.com/KeitetsuWorks/DS3231_Temperature.git
        $ cd DS3231_Temperature

2. Download I2C_Linux

        $ wget https://github.com/KeitetsuWorks/I2C_Linux/archive/master.zip
        $ unzip master.zip
        $ mv I2C_Linux-master i2c

3. Compile DS3231_Temperature

        $ make

After that you can find `DS3231_Temperature` under the `./bin/` directory.

## License
* MIT

