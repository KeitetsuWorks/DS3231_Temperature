/**
 * @file        main.c
 * @brief       Main Function for DS3231 Temperature Register Access
 * @author      Keitetsu
 * @date        2016/08/30
 * @copyright   Copyright (c) 2016 Keitetsu
 * @license     This software is released under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>

#include "DS3231.h"

#define I2C_BUS     "/dev/i2c-1"    //!< Device File for I2C Bus

/**
 * @brief   Main Function
 * @retval  0   Success
 * @retval  1   Failure
 */
int main(void)
{
    int ds3231_fd;
    int retval;
    double ds3231_temperature;

    ds3231_fd = DS3231_open(I2C_BUS);
    if(ds3231_fd < 0) {
        exit(EXIT_FAILURE);
    }

    retval = DS3231_read_temperature(ds3231_fd, &ds3231_temperature);
    if(retval != 0) {
        exit(EXIT_FAILURE);
    }

    printf("DS3231 Temperature: %+3.2lf 'C\n", ds3231_temperature);
    DS3231_close(ds3231_fd);

    exit(EXIT_SUCCESS);
}

