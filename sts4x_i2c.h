/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * I2C-Generator: 0.2.0
 * Yaml Version: 0.1.0
 * Template Version: 0.7.0-12-g6411a7e
 */
/*
 * Copyright (c) 2021, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef STS4X_I2C_H
#define STS4X_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensirion_config.h"

// i2c adresses
#define ADDR_STS4X 0x46
#define ADDR_STS4X_ALT 0x44
#define ADDR_STS4X_ALT2 0x45

typedef struct sts4x_tag {
    uint8_t i2c_address;
} sts4x_t;

/**
 * init_driver() - initialize the driver with the i2c address to be used to
 *                 communicate with the STS4x sensor
 *
 * @param i2c_address i2c address of the STS4x sensor
 */
void init_driver(uint8_t i2c_address);

/**
 * sts4x_measure_high_precision_ticks() - SHT4x command for a single shot
 * measurement with high repeatability.
 *
 * @param temperature_ticks Temperature ticks. Convert to degrees celsius by
 * (175 * value / 65535) - 45
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sts4x_measure_high_precision_ticks(uint16_t* temperature_ticks);

/**
 * sts4x_measure_high_precision() - SHT4x command for a single shot
 * measurement with high repeatability.
 *
 * @param temperature Temperature in milli degrees centigrade.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sts4x_measure_high_precision(int32_t* temperature);

/**
 * sts4x_measure_medium_precision_ticks() - SHT4x command for a single shot
 * measurement with medium repeatability.
 *
 * @param temperature_ticks Temperature ticks. Convert to degrees celsius by
 * (175 * value / 65535) - 45
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sts4x_measure_medium_precision_ticks(uint16_t* temperature_ticks);

/**
 * sts4x_measure_medium_precision() - SHT4x command for a single shot
 * measurement with medium repeatability.
 *
 * @param temperature Temperature in milli degrees centigrade.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sts4x_measure_medium_precision(int32_t* temperature);

/**
 * sts4x_measure_lowest_precision_ticks() - SHT4x command for a single shot
 * measurement with lowest repeatability.
 *
 * @param temperature_ticks Temperature ticks. Convert to degrees celsius by
 * (175 * value / 65535) - 45
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sts4x_measure_lowest_precision_ticks(uint16_t* temperature_ticks);

/**
 * sts4x_measure_lowest_precision() - SHT4x command for a single shot
 * measurement with lowest repeatability.
 *
 * @param temperature Temperature in milli degrees centigrade.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sts4x_measure_lowest_precision(int32_t* temperature);

/**
 * sts4x_serial_number() - Read out the serial number
 *
 * @note Each sensor has a unique serial number that is assigned by Sensirion
 * during production. It is stored in the one-time-programmable memory and
 * cannot be manipulated after production.
 *
 * @param serial_number Unique serial number
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sts4x_serial_number(uint32_t* serial_number);

/**
 * sts4x_soft_reset() - Perform a soft reset.
 *
 * @note A reset of the sensor can be achieved in three ways: By perform a soft
 * reset using this function, by using an I2C general call, at which all devices
 * on the I2C bus will be reset, or by a power down (incl. pulling SCL and SDA
 * low). See the datasheet for more detailed information.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sts4x_soft_reset(void);

#ifdef __cplusplus
}
#endif

#endif /* STS4X_I2C_H */
