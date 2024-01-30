/*
 * led.c
 *
 * Created: 1/11/2024 9:11:14 AM
 *  Author: Ahmed Abuzaid
 */ 
#include "DIO.h"

void led_inti(char port,char pin)
{
	DIO_setpin_dir(port,pin,1);
}

void led_on(char port,char pin)
{
	DIO_pin_write(port,pin,1);
}

void led_off(char port,char pin)
{
	DIO_pin_write(port,pin,0);
}

void led_tog(char port,char pin)
{
	DIO_toggelpin(port,pin);
}

char led_status(char port,char pin)
{
	char status;
	status=DIO_pin_read(port,pin);
	return status;
}