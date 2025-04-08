/*
 *  src/sd-driver.c 
 *  
 *  Init and read from SD card using SD or SPI mode. 
 * 
 *  Not suitable for general use:
 *  - Write not supported. Write protect switch is not honored.
 *  - Init erase not supported.
 *  
 */

// #include

/// @brief Power on cycle according to SD spec
///        Must hold 1ms (74 clock cycles) per spec. 
/// @param host 
void sd_power_init(struct sd_host *host)
{
    
}

/// @brief Power cycle SD card
/// @param host 
/// @param ocr 
void sd_power_cycle(struct sd_host *host, u32 ocr)
{
	sd_power_off(host);
	/* Wait at least 1 ms according to SD spec */
	mmc_delay(1);
	mmc_power_up(host, ocr);
}

/// @brief SD card setup.
///        Notes: 
///        - Write Protect switch is not honored. 
///        - Init erase not supported. I don't intend to ever write to these SD cards. 
/// @param spi_handle 
/// @param reinit 
/// @return 
int sd_setup_card(struct spi_handle *spi_handle, bool reinit)
{
    if (!reinit)
    {
        // Check SCR/OCR Register for supported features

        // Check Status Register

        // No init erase supported
    }

    // Would check WP Switch here if supported 

    // Set CRC



}