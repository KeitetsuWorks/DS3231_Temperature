/**
 * @file        DS3231.h
 * @brief       DS3231 I2C RTC Control Functions
 * @author      Keitetsu
 * @date        2016/09/05
 * @copyright   Copyright (c) 2016 Keitetsu
 * @license     This software is released under the MIT License.
 */

#pragma once    // __DS3231_H__

/**
 * @name    Device Address
 */
/** @{ */
#define DS3231_ADDR                 0x68    /**< maxim integrated DS3231 */
/** @} */

/**
 * @name    Register Address Map
 */
/** @{ */
#define DS3231_TIME                 0x00
#define DS3231_ALARM1               0x07
#define DS3231_ALARM2               0x0B
#define DS3231_CONTROL              0x0E    /**< Control Register */
#define DS3231_CONTROL_STATUS       0x0F    /**< Status Register */
#define DS3231_AGING                0x10    /**< Aging Offset Register */
#define DS3231_TEMPERATURE_MSB      0x11    /**< Temperature Register (Upper Byte) */
#define DS3231_TEMPERATURE_LSB      0x12    /**< Temperature Register (Lower Byte) */
/** @} */

/**
 *@name     Register Address Offset
 */
/** @{ */
#define DS3231_SECONDS              0x00
#define DS3231_MINUTES              0x01
#define DS3231_HOURS                0x02
#define DS3231_DAY                  0x03
#define DS3231_DATE                 0x04
#define DS3231_MONTH_CENTURY        0x05
#define DS3231_YEAR                 0x06
#define DS3231_ALARM1_SECONDS       0x00
#define DS3231_ALARM1_MINUTES       0x01
#define DS3231_ALARM1_HOURS         0x02
#define DS3231_ALARM1_DAY_DATE      0x03
#define DS3231_ALARM2_MINUTES       0x00
#define DS3231_ALARM2_HOURS         0x01
#define DS3231_ALARM2_DAY_DATE      0x02
/** @} */

/**
 * @name    Register Bit Mask
 */
/** @{ */
#define DS3231_BIT_10SECONDS        0x70
#define DS3231_BIT_SECONDS          0x0F
#define DS3231_BIT_10MINUTES        0x70
#define DS3231_BIT_MINUTES          0x0F
#define DS3231_BIT_12_24            0x40
#define DS3231_BIT_AM_PM            0x20
#define DS3231_BIT_20HOUR           0x20
#define DS3231_BIT_10HOUR           0x10
#define DS3231_BIT_HOUR             0x0F
#define DS3231_BIT_DAY              0x07
#define DS3231_BIT_10DATE           0x30
#define DS3231_BIT_DATE             0x0F
#define DS3231_BIT_CENTURY          0x80
#define DS3231_BIT_10YEAR           0xF0
#define DS3231_BIT_YEAR             0x0F
#define DS3231_BIT_ALARM_MASK       0x80
#define DS3231_BIT_ALARM_DY_DT      0x40
#define DS3231_BIT_EOSC             0x80
#define DS3231_BIT_BBSQW            0x40
#define DS3231_BIT_CONV             0x20
#define DS3231_BIT_RS2              0x10
#define DS3231_BIT_RS1              0x08
#define DS3231_BIT_INTCN            0x04
#define DS3231_BIT_A2IE             0x02
#define DS3231_BIT_A1IE             0x01
#define DS3231_BIT_OSF              0x80
#define DS3231_BIT_EN32KHZ          0x08
#define DS3231_BIT_BSY              0x04
#define DS3231_BIT_A2F              0x02
#define DS3231_BIT_A1F              0x01
#define DS3231_BIT_AGING_SIGN       0x80
#define DS3231_BIT_AGING_DATA       0x7F
#define DS3231_BIT_TEMPERATURE_SIGN 0x80
#define DS3231_BIT_TEMPERATURE_MSB  0x7F
#define DS3231_BIT_TEMPERATURE_LSB  0xC0
/** @} */

// プロトタイプ宣言
/**
 * @brief   Open Function for DS3231
 * @param[in]       i2c_bus     Device File for I2C Bus
 * @return          File Descriptor
 */
int DS3231_open(
        char *i2c_bus);


/**
 * @brief   Close Function for DS3231
 * @param[in]       fd          Device File for I2C Bus
 */
void DS3231_close(
        int fd);


/**
 * @brief   Read DS3231 Temperature Register
 * @param[in]       fd          Device File for I2C Bus
 * @param[out]      temperature Celsius Temperature
 * @retval          0           Success
 * @retval          1           Failure
 */
int DS3231_read_temperature(
        int fd,
        double *temperature);
