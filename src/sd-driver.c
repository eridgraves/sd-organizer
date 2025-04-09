/*
 *  src/sd-driver.c 
 *  
 *  Init and read from SD card using SD or SPI mode. 
 * 
 *  Not suitable for general use:
 *  - Write not supported. Write protect switch is not honored.
 *  - Init erase not supported.
 *  
 *  Resources:
 *  - https://www.cactus-tech.com/wp-content/uploads/2019/03/An-Introduction-To-SD-Card-Interface.pdf
 *  - https://github.com/torvalds/linux/blob/master/drivers/mmc/core/sd.c
 */

// #include

// Start at 100% SPI CLK speed
#define SPI_CLK_SPEED 100 

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

/// @brief Bitbang delay -- spin for a bit 
void spi_delay()
{
    volatile int v;   // to avoid optimization
    for(int i=0; i<SPI_CLK_SPEED/2; i++)
        v;
    
}

/// @brief Set SPI clock polarity (CPOL)
void spi_set_clk_pol(unsigned char value)
{
    // HW stuff
}

/// @brief Set SPI clock phase (CPHA)
void spi_set_clk_phase(unsigned char value)
{
    // HW stuff
}


unsigned char spi_read_byte()
{
    // data on falling edge
    unsigned char byte_data = 0;

    // negative clock 
    spi_set_clk_pol(0);
    spi_set_clk_phase(0);

    // 1 byte of data
    for (unsigned char b=0; b<8; b++)
    {
        // delay by half clock
        spi_delay(SPI_CLK_SPEED/2);

        // set clk

        // wait

        // set clk

        // data

        // MISO
    }

    return byte_data;
}