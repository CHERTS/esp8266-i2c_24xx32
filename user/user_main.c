/*
 *  Test for read and write Eeprom ATMEL AT24C512
 *  http://www.atmel.com/Images/doc1116.pdf
 * 
 *  For a single device, connect as follows:
 *  EEPROM 4 (GND) to GND
 *  EEPROM 8 (Vcc) to Vcc (3.3 Volts)
 *  EEPROM 5 (SDA) to ESP Pin GPIO2
 *  EEPROM 6 (SCL) to ESP Pin GPIO0 (see i2c.h)
 *  EEPROM 7 (WP)  to GND
 *  EEPROM 1 (A0)  to GND
 *  EEPROM 2 (A1)  to GND
 *  EEPROM 3 (NC)  to NC
 *
 */

#include "ets_sys.h"
#include "driver/i2c.h"
#include "driver/uart.h"
#include "osapi.h"
#include "os_type.h"
#include "user_interface.h"
#include "user_config.h"

os_event_t user_procTaskQueue[user_procTaskQueueLen];
extern int ets_uart_printf(const char *fmt, ...);
int (*console_printf)(const char *fmt, ...) = ets_uart_printf;
static void user_procTask(os_event_t *events);

uint32_t time;
uint32_t finishTime;
uint32_t errors = 0;
uint32_t address = 0;
uint8_t loop_size;
uint32_t wdata, rdata;

static void ICACHE_FLASH_ATTR
user_procTask(os_event_t *events)
{
    os_delay_us(5000);
}

static void ICACHE_FLASH_ATTR writeByByteTest()
{
	time = system_get_time();
	errors = 0;
	address = 0;
	ets_uart_printf("--------------------------------\r\n");
	ets_uart_printf("Write byte test:\r\n");
	console_printf( "Start address: %d, End address: %d\r\n", MIN_ADDRESS, MAX_ADDRESS);
	ets_uart_printf("Writing data: ");
	for (address = MIN_ADDRESS; address <= MAX_ADDRESS; address++)
	{
		wdata = address % loop_size;
		if(!eeprom_writeByte(DEVICEADDRESS, address, wdata))
			console_printf( "Failed write, address: %d, data: %d\r\n", address, (uint8_t)wdata);
		else
		{
			if (!(address % 500)) {
				//console_printf( "Address: %d, data: %d\r\n", address, (uint8_t)wdata);
				ets_uart_printf("..500..");
			}
		}
		sleepms(3);
	}
	finishTime = system_get_time() - time;
	ets_uart_printf("DONE!\r\n");
	console_printf( "Total Time (seconds): %d\r\n", (uint32_t)(finishTime / 1000000));
	console_printf( "Write operations per second: %d\r\n", (uint32_t)(MAX_ADDRESS / (finishTime / 1000000)));
	ets_uart_printf("--------------------------------\r\n");
	ets_uart_printf("\r\n");
}

void readByByteTest()
{
	time = system_get_time();
	errors = 0;
	address = 0;
	ets_uart_printf("--------------------------------\r\n");
	ets_uart_printf("Read byte test:\r\n");
	console_printf( "Start address: %d, End address: %d\r\n", MIN_ADDRESS, MAX_ADDRESS);
	ets_uart_printf("Reading data:");
	for (address = MIN_ADDRESS; address <= MAX_ADDRESS; address++)
	{
		rdata = eeprom_readByte(DEVICEADDRESS, address);
		wdata = address % loop_size;
		if (rdata != (uint8_t)wdata)
		{
			console_printf( "Address: %d", address);
			console_printf( " Should be: %d", (uint8_t)wdata);
			console_printf( " Read val: %d\r\n", rdata);
			errors++;
		}
		if (!(address % 500)) ets_uart_printf("..500..");
		sleepms(3);
	}
	finishTime = system_get_time() - time;
	ets_uart_printf("DONE\r\n");
	console_printf( "Total time (seconds): %d\r\n", (uint32_t)(finishTime / 1000000));
	console_printf( "Read operations per second: %d\r\n", (uint32_t)(MAX_ADDRESS / (finishTime / 1000000)));
	console_printf( "Total errors: %d\r\n", errors);
	ets_uart_printf("--------------------------------\r\n");
	ets_uart_printf("\r\n");
}

void user_init(void)
{
    //Init uart
    uart_init(BIT_RATE_9600, BIT_RATE_9600);
    os_delay_us(1000);

    ets_uart_printf("Booting...\r\n");

    // i2c
    i2c_init();

    loop_size = rand();
    // start write test
    writeByByteTest();
    // start read test
    readByByteTest();

    system_os_task(user_procTask, user_procTaskPrio,user_procTaskQueue, user_procTaskQueueLen);
}

