/****************************************************************************
 *
 *   Copyright (C) 2012 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file vrbrain_spi.c
 *
 * Board-specific SPI functions.
 */

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>
#include <debug.h>

#include <nuttx/spi/spi.h>
#include <arch/board/board.h>

#include "up_arch.h"
#include "chip.h"
#include "stm32.h"
#include "board_config.h"

/************************************************************************************
 * Public Functions
 ************************************************************************************/

/************************************************************************************
 * Name: stm32_spiinitialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins for the VRBRAIN board.
 *
 ************************************************************************************/

__EXPORT void weak_function stm32_spiinitialize(void)
{
	stm32_configgpio(GPIO_SPI_CS_DATAFLASH);
	stm32_configgpio(GPIO_SPI_CS_EEPROM);
	stm32_configgpio(GPIO_SPI_CS_DF_EXT1);
	stm32_configgpio(GPIO_SPI_CS_DF_EXT2);
	stm32_configgpio(GPIO_SPI_CS_DF_EXT3);
	stm32_configgpio(GPIO_SPI_CS_DF_EXT4);
	stm32_configgpio(GPIO_SPI_CS_DF_EXT5);
	stm32_configgpio(GPIO_SPI_CS_MS5611);
	stm32_configgpio(GPIO_SPI_CS_MPU6000);

	stm32_configgpio(GPIO_SPI_CS_SDCARD);






	/* De-activate all peripherals,
	 * required for some peripheral
	 * state machines
	 */
	stm32_gpiowrite(GPIO_SPI_CS_DATAFLASH, 1);
	stm32_gpiowrite(GPIO_SPI_CS_EEPROM, 1);
	stm32_gpiowrite(GPIO_SPI_CS_DF_EXT1, 1);
	stm32_gpiowrite(GPIO_SPI_CS_DF_EXT2, 1);
	stm32_gpiowrite(GPIO_SPI_CS_DF_EXT3, 1);
	stm32_gpiowrite(GPIO_SPI_CS_DF_EXT4, 1);
	stm32_gpiowrite(GPIO_SPI_CS_DF_EXT5, 1);
	stm32_gpiowrite(GPIO_SPI_CS_MS5611, 1);
	stm32_gpiowrite(GPIO_SPI_CS_MPU6000, 1);

	stm32_gpiowrite(GPIO_SPI_CS_SDCARD, 1);



}

__EXPORT void stm32_spi1select(FAR struct spi_dev_s *dev, enum spi_dev_e devid, bool selected)
{
	/* SPI select is active low, so write !selected to select the device */

	switch (devid) {
	case SPIDEV_FLASH:
		/* Making sure the other peripherals are not selected */
		stm32_gpiowrite(GPIO_SPI_CS_DATAFLASH, !selected);
		stm32_gpiowrite(GPIO_SPI_CS_MS5611, 1);
		stm32_gpiowrite(GPIO_SPI_CS_EEPROM, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT1, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT2, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT3, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT4, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT5, 1);
		break;

	case SPIDEV_EEPROM:
		/* Making sure the other peripherals are not selected */
		stm32_gpiowrite(GPIO_SPI_CS_DATAFLASH, 1);
		stm32_gpiowrite(GPIO_SPI_CS_EEPROM, !selected);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT1, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT2, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT3, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT4, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT5, 1);
		stm32_gpiowrite(GPIO_SPI_CS_MS5611, 1);
		break;
	case SPIDEV_DF_EXT1:
			/* Making sure the other peripherals are not selected */
			stm32_gpiowrite(GPIO_SPI_CS_DATAFLASH, 1);
			stm32_gpiowrite(GPIO_SPI_CS_EEPROM, 1);
			stm32_gpiowrite(GPIO_SPI_CS_DF_EXT1, !selected);
			stm32_gpiowrite(GPIO_SPI_CS_DF_EXT2, 1);
			stm32_gpiowrite(GPIO_SPI_CS_DF_EXT3, 1);
			stm32_gpiowrite(GPIO_SPI_CS_DF_EXT4, 1);
			stm32_gpiowrite(GPIO_SPI_CS_DF_EXT5, 1);
			stm32_gpiowrite(GPIO_SPI_CS_MS5611, 1);
			break;
	case SPIDEV_DF_EXT2:
				/* Making sure the other peripherals are not selected */
				stm32_gpiowrite(GPIO_SPI_CS_DATAFLASH, 1);
				stm32_gpiowrite(GPIO_SPI_CS_EEPROM, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT1, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT2, !selected);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT3, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT4, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT5, 1);
				stm32_gpiowrite(GPIO_SPI_CS_MS5611, 1);
				break;
	case SPIDEV_DF_EXT3:
				/* Making sure the other peripherals are not selected */
				stm32_gpiowrite(GPIO_SPI_CS_DATAFLASH, 1);
				stm32_gpiowrite(GPIO_SPI_CS_EEPROM, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT1, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT2, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT3, !selected);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT4, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT5, 1);
				stm32_gpiowrite(GPIO_SPI_CS_MS5611, 1);
				break;
	case SPIDEV_DF_EXT4:
				/* Making sure the other peripherals are not selected */
				stm32_gpiowrite(GPIO_SPI_CS_DATAFLASH, 1);
				stm32_gpiowrite(GPIO_SPI_CS_EEPROM, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT1, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT2, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT3, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT4, !selected);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT5, 1);
				stm32_gpiowrite(GPIO_SPI_CS_MS5611, 1);
				break;
	case SPIDEV_DF_EXT5:
				/* Making sure the other peripherals are not selected */
				stm32_gpiowrite(GPIO_SPI_CS_DATAFLASH, 1);
				stm32_gpiowrite(GPIO_SPI_CS_EEPROM, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT1, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT2, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT3, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT4, 1);
				stm32_gpiowrite(GPIO_SPI_CS_DF_EXT5, !selected);
				stm32_gpiowrite(GPIO_SPI_CS_MS5611, 1);
				break;

	case SPIDEV_MS5611:
		/* Making sure the other peripherals are not selected */
		stm32_gpiowrite(GPIO_SPI_CS_MS5611, !selected);
		stm32_gpiowrite(GPIO_SPI_CS_DATAFLASH, 1);
		stm32_gpiowrite(GPIO_SPI_CS_EEPROM, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT1, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT2, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT3, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT4, 1);
		stm32_gpiowrite(GPIO_SPI_CS_DF_EXT5, 1);
		break;

	default:
		break;

	}
}

__EXPORT uint8_t stm32_spi1status(FAR struct spi_dev_s *dev, enum spi_dev_e devid)
{
	return SPI_STATUS_PRESENT;
}

__EXPORT void stm32_spi2select(FAR struct spi_dev_s *dev, enum spi_dev_e devid, bool selected)
{
	/* SPI select is active low, so write !selected to select the device */

	switch (devid) {
	case SPIDEV_MPU6000:
		/* Making sure the other peripherals are not selected */
		stm32_gpiowrite(GPIO_SPI_CS_MPU6000, !selected);
		break;

	default:
		break;

	}
}

__EXPORT uint8_t stm32_spi2status(FAR struct spi_dev_s *dev, enum spi_dev_e devid)
{
	return SPI_STATUS_PRESENT;
}


__EXPORT void stm32_spi3select(FAR struct spi_dev_s *dev, enum spi_dev_e devid, bool selected)
{
	/* SPI select is active low, so write !selected to select the device */

	switch (devid) {
	case SPIDEV_MMCSD:
		/* Making sure the other peripherals are not selected */
		stm32_gpiowrite(GPIO_SPI_CS_SDCARD, !selected);
		break;

	default:
		break;

	}
}

__EXPORT uint8_t stm32_spi3status(FAR struct spi_dev_s *dev, enum spi_dev_e devid)
{
	return SPI_STATUS_PRESENT;
}
