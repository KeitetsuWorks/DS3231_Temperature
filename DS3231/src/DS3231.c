/**
 * @file        DS3231.c
 * @brief       DS3231 I2C RTC Control Functions
 * @author      Keitetsu
 * @date        2016/09/05
 * @copyright   Copyright (c) 2016 Keitetsu
 * @license     This software is released under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "i2c.h"
#include "DS3231.h"

int DS3231_open(
        char *i2c_bus)
{
    int fd;

    fd = i2c_open_bus(i2c_bus);

    return fd;
}


void DS3231_close(
        int fd)
{
    i2c_close_bus(fd);

    return;
}


int DS3231_read_temperature(
        int fd,
        double *temperature)
{
    uint8_t temperature_msb, temperature_lsb;
    int ret;
    double temperature_work;
    
    ret = i2c_read_register(
            fd,
            DS3231_ADDR,
            DS3231_TEMPERATURE_MSB,
            &temperature_msb);
    if(ret != 0) {
        return 1;
    }

    ret = i2c_read_register(
            fd,
            DS3231_ADDR,
            DS3231_TEMPERATURE_LSB,
            &temperature_lsb);
    if(ret != 0) {
        return 1;
    }

    temperature_work = (
                (temperature_msb & DS3231_BIT_TEMPERATURE_MSB)
            +   (0.25 * ((temperature_lsb & DS3231_BIT_TEMPERATURE_LSB) >> 6)));
    if((temperature_msb & DS3231_BIT_TEMPERATURE_SIGN) != 0) {
        temperature_work *= -1;
    }

    *temperature = temperature_work;

    return 0;
}

