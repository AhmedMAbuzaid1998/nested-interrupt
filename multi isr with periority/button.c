/*
 * led.c
 *
 * Created: 1/11/2024 9:11:14 AM
 *  Author: Ahmed Abuzaid
 */ 
#include "DIO.h"

void button_inti(char port,char pin)
{
	DIO_setpin_dir(port,pin,0);
}

char button_val(char port,char pin)
{
	char status;
	status=DIO_pin_read(port,pin);
	return status;
}