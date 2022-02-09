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

#include <stdio.h>  // printf

#include "sensirion_common.h"
#include "sensirion_i2c_hal.h"
#include "sts4x_i2c.h"

/*
 * TO USE CONSOLE OUTPUT (PRINTF) YOU MAY NEED TO ADAPT THE INCLUDE ABOVE OR
 * DEFINE IT ACCORDING TO YOUR PLATFORM:
 * #define printf(...)
 */

int main(void) {
    int16_t error = 0;

    sensirion_i2c_hal_init();

    /**
     * select the proper i2c address for your sensor (defaults to 0x46)
     *
     * STS40-CD1B: ADDR_STS4X (I2C address: 0x46)
     * STS40-AD1B: ADDR_STS4X_ALT (I2C address: 0x44)
     * STS40-BD1B: ADDR_STS4X_ALT2 (I2C address: 0x45)
     */
    init_driver(ADDR_STS4X);

    uint32_t serial_number;
    error = sts4x_serial_number(&serial_number);
    if (error) {
        printf("Error executing sts4x_serial_number(): %i\n", error);
    } else {
        printf("Serial number: %u\n", serial_number);
    }

    // Start Measurement
    for (;;) {
        int32_t temperature;
        // Read Measurement
        error = sts4x_measure_high_precision(&temperature);
        if (error) {
            printf("Error executing sts4x_measure_high_precision(): %i\n",
                   error);
        } else {
            printf("Temperature: %.1f °C\n", temperature / 1000.0f);
        }

        sensirion_i2c_hal_sleep_usec(1000000);
    }

    return 0;
}
