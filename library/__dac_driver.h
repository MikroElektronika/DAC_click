/*
    __dac_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __dac_driver.h
@brief    DAC Driver
@mainpage DAC Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   DAC
@brief      DAC Click Driver
@{

| Global Library Prefix | **DAC** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jul 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _DAC_H_
#define _DAC_H_

/** 
 * @macro T_DAC_P
 * @brief Driver Abstract type 
 */
#define T_DAC_P    const uint8_t*

/** @defgroup DAC_COMPILE Compilation Config */              /** @{ */

   #define   __DAC_DRV_SPI__                            /**<     @macro __DAC_DRV_SPI__  @brief SPI driver selector */
//  #define   __DAC_DRV_I2C__                            /**<     @macro __DAC_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __DAC_DRV_UART__                           /**<     @macro __DAC_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup DAC_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup DAC_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup DAC_INIT Driver Initialization */              /** @{ */

#ifdef   __DAC_DRV_SPI__
void dac_spiDriverInit(T_DAC_P gpioObj, T_DAC_P spiObj);
#endif
#ifdef   __DAC_DRV_I2C__
void dac_i2cDriverInit(T_DAC_P gpioObj, T_DAC_P i2cObj, uint8_t slave);
#endif
#ifdef   __DAC_DRV_UART__
void dac_uartDriverInit(T_DAC_P gpioObj, T_DAC_P uartObj);
#endif


/** @defgroup DAC_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic 12-bit data write function
 *
 * @param[in] valueDAC 12-bit data value
 *
 * Function set DAC increments 12-bit data ( 0..4095 ) --> output voltage ( 0..Vref [mV] )
 */
void dac_setOutVoltage( uint16_t valueDAC );

/**
 * @brief Function write procentage value
 *
 * @param[in] valueDACPct Data procentage value
 *
 * Function set DAC increments procentage ( 0..100 [%] ) --> output voltage ( 0..Vref [mV] )
 */
void dac_setOutputVoltageProcentage( uint8_t valueDACPct );





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_DAC_STM.c
    @example Click_DAC_TIVA.c
    @example Click_DAC_CEC.c
    @example Click_DAC_KINETIS.c
    @example Click_DAC_MSP.c
    @example Click_DAC_PIC.c
    @example Click_DAC_PIC32.c
    @example Click_DAC_DSPIC.c
    @example Click_DAC_AVR.c
    @example Click_DAC_FT90x.c
    @example Click_DAC_STM.mbas
    @example Click_DAC_TIVA.mbas
    @example Click_DAC_CEC.mbas
    @example Click_DAC_KINETIS.mbas
    @example Click_DAC_MSP.mbas
    @example Click_DAC_PIC.mbas
    @example Click_DAC_PIC32.mbas
    @example Click_DAC_DSPIC.mbas
    @example Click_DAC_AVR.mbas
    @example Click_DAC_FT90x.mbas
    @example Click_DAC_STM.mpas
    @example Click_DAC_TIVA.mpas
    @example Click_DAC_CEC.mpas
    @example Click_DAC_KINETIS.mpas
    @example Click_DAC_MSP.mpas
    @example Click_DAC_PIC.mpas
    @example Click_DAC_PIC32.mpas
    @example Click_DAC_DSPIC.mpas
    @example Click_DAC_AVR.mpas
    @example Click_DAC_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __dac_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */