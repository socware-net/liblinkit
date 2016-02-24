/* Copyright Statement:
 *
 * @2015 MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek Inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE.
 */
 
#ifndef __HAL_ADC_H__
#define __HAL_ADC_H__
#include "hal_platform.h"

#ifdef HAL_ADC_MODULE_ENABLED

/**
 * @addtogroup HAL
 * @{
 * @addtogroup ADC
 * @{
 * This section describes the programming interfaces of the ADC HAL driver.
 *
 * @section HAL_ADC_Terms_Chapter Terms and acronyms
 *
 * The following provides descriptions to the terms commonly used in the ADC driver and how to use its various functions.
 *
 * |Terms                   |Details                                                                 |
 * |------------------------------|------------------------------------------------------------------------|
 * |\b ADC                        | ADC is an Analog-to-Digital Converter that converts a continuous physical quantity (usually voltage) to a digital number that represents the quantity's amplitude.|
 *
 * @section HAL_ADC_Features_Chapter Supported features
 * The ADC is a 12-bit, <a href="https://en.wikipedia.org/wiki/Successive_approximation_ADC">Successive Approximation ADC </a>. Only polling mode is supported in this ADC driver. The supported channels vary based on the actual MCU devices used.
 * - \b Retrieve \b ADC \b data \b for \b a \b channel. \n
 *   Call hal_adc_get_data_polling() function to get data for a channel. Only one sample data is retrieved at a time.
 *
 * @section HAL_ADC_Driver_Usage_Chapter How to use this driver
 * - \b Use \b ADC \b driver \b to \b gets \b sample \b data \b for \b a \b channel.\n
 *   - Step1: Call hal_adc_init() to initialize the ADC module.
 *   - Step2: Call hal_adc_get_data_polling() to retrieve sample data for a channel.
 *   - Step3: Call hal_adc_deinit() to return the ADC module back to its original state.
 *   - Sample code:
 *   @code
 *
 * 	 uint16_t adc_data;
 *
 * 	 hal_pinmux_set_function(HAL_GPIO_0, 2);//Set GPIO 0 to an ADC work mode. For more details, please refer to hal_pinmux_set_function().
 * 	 hal_adc_init();//Initialize ADC module.
 * 	 hal_adc_get_data_polling(HAL_ADC_CHANNEL_11, &adc_data);//Retrieve ADC data for channel 11.
 * 	 hal_adc_deinit();//Deinit ADC module when job done.
 *
 *   @endcode
 *
 */


#ifdef __cplusplus
extern "C" {
#endif


/*****************************************************************************
 * Enums
 *****************************************************************************/

/** @defgroup hal_adc_enum Enum
 *  @{
 */

/** @brief This enum defines the ADC API return status*/
typedef enum {
    HAL_ADC_STATUS_INVALID_PARAMETER = -3,      /**< Invalid parameter */
    HAL_ADC_STATUS_ERROR_CHANNEL = -2,          /**< ADC channel number error */
    HAL_ADC_STATUS_ERROR = -1,                  /**< ADC error */
    HAL_ADC_STATUS_OK = 0                       /**< ADC ok */
} hal_adc_status_t;

/**
 * @}
 */


/*****************************************************************************
 * Structures
 *****************************************************************************/



/*****************************************************************************
 * Functions
 *****************************************************************************/

/**
 * @brief 	ADC init function.
 * @return
 * #HAL_ADC_STATUS_OK, ADC init success.
 */
hal_adc_status_t hal_adc_init(void);


/**
* @brief 	ADC deinit function. This function resets the ADC peripheral registers to their default values.
* @return
* #HAL_ADC_STATUS_OK, ADC deinit success.
*/
hal_adc_status_t hal_adc_deinit(void);


/**
 * @brief 	ADC receives a sample data for a channel.
 * @param[in] channel is the channel that will be sampled. This parameter can only be the value of type #hal_adc_channel_t.
 * @param[out] data is the raw data of the channel.
 * @return
 * #HAL_ADC_STATUS_OK, ADC get data success. \n
 * #HAL_ADC_STATUS_ERROR_CHANNEL, the channel number is invalid.
 * @note Call hal_pinmux_set_function() to set the corresponding pin to operate on an ADC mode, before using an ADC peripheral. For more details, please refer to hal_pinmux_set_function() in @ref GPIO module.
 * @par Example
 * Sample code please refer to Use ADC driver to get sample data for a channel of @ref HAL_ADC_Driver_Usage_Chapter
 */
hal_adc_status_t hal_adc_get_data_polling(hal_adc_channel_t channel, uint16_t *data);


#ifdef __cplusplus
}
#endif

/**
 * @}
 * @}
*/
#endif /*HAL_ADC_MODULE_ENABLED*/
#endif /* __HAL_ADC_H__ */



