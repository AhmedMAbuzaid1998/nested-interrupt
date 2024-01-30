/*
 * DIO.c
 *
 * Created: 12/26/2023 8:20:22 PM
 *  Author: Ahmed Abuzaid
 */ 
#include <avr/io.h>
#include "bitmask.h"
void DIO_setpin_dir(char port,char pin,char dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if(dir==1)
		{
			SET_BIT(DDRA,pin);
		}
		else
		{
			CLC_BIT(DDRA,pin);
		}
		break;
		case 'B':
		case 'b':
		if(dir==1)
		{
			SET_BIT(DDRB,pin);
		}
		else
		{
			CLC_BIT(DDRB,pin);
		}
		break;
		case 'C':
		case 'c':
		if(dir==1)
		{
			SET_BIT(DDRC,pin);
		}
		else
		{
			CLC_BIT(DDRC,pin);
		}
		break;
		case 'D':
		case 'd':
		if(dir==1)
		{
			SET_BIT(DDRD,pin);
		}
		else
		{
			CLC_BIT(DDRD,pin);
		}
		break;
	}		
}

void DIO_pin_write(char port,char pin,char level)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if(level==1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLC_BIT(PORTA,pin);
		}
		break;
		case 'B':
		case 'b':
		if(level==1)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLC_BIT(PORTB,pin);
		}
		break;
		case 'C':
		case 'c':
		if(level==1)
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLC_BIT(PORTC,pin);
		}
		break;
		case 'D':
		case 'd':
		if(level==1)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLC_BIT(PORTD,pin);
		}
		break;
	}
}

void DIO_toggelpin(char port,char pin)
{
	switch(port)
	{
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pin);
		break;
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pin);
		break;
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pin);
		break;
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pin);
		break;
	}
}

unsigned char DIO_pin_read(char port,char pin)
{
	int back_val=0;
	switch(port)
	{
		case 'A':
		case 'a':
		back_val=READ_BIT(PINA,pin);
		break;
		case 'B':
		case 'b':
		back_val=READ_BIT(PINB,pin);
		break;
		case 'C':
		case 'c':
		back_val=READ_BIT(PINC,pin);
		break;
		case 'D':
		case 'd':
		back_val=READ_BIT(PIND,pin);
		break;
	}
	return back_val;//back_val return 1 or 0 
}
void DIO_set_portdir(char port,char dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		DDRA=dir;
		break;
		case 'B':
		case 'b':
		DDRB=dir;
		break;
		case 'C':
		case 'c':
		DDRC=dir;
		break;
		case 'D':
		case 'd':
		DDRD=dir;
		break;
	}
}

unsigned char DIO_read_portval(char port)
{
	int port_val;
	switch(port)
	{
		case 'A':
		case 'a':
		port_val=PINA;
		break;
		case 'B':
		case 'b':
		port_val=PINB;
		break;
		case 'C':
		case 'c':
		port_val=PINC;
		break;
		case 'D':
		case 'd':
		port_val=PIND;
		break;
	}
	return port_val;
	
}

void DIO_write_allport(char port,char val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA=val;
		break;
		case 'B':
		case 'b':
		PORTB=val;
		break;
		case 'C':
		case 'c':
		PORTC=val;
		break;
		case 'D':
		case 'd':
		PORTD=val;
		break;
	}
}

void DIO_port_toggle(char port)
{
		switch(port)
		{
			case 'A':
			case 'a':
			PORTA=~PORTA;
			break;
			case 'B':
			case 'b':
			PORTB=~PORTB;
			break;
			case 'C':
			case 'c':
			PORTC=~PORTC;
			break;
			case 'D':
			case 'd':
			PORTD=~PORTD;
			break;
		}
}

void DIO_connect_pullup(char port,char pin,char val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if(val==1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLC_BIT(PORTA,pin);
		}
		break;
		case 'B':
		case 'b':
		if(val==1)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLC_BIT(PORTB,pin);
		}
		break;
		case 'C':
		case 'c':
		if(val==1)
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLC_BIT(PORTC,pin);
		}
		break;
		case 'D':
		case 'd':
		if(val==1)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLC_BIT(PORTD,pin);
		}
		break;
	}
}

void write_lownibble(char port,char val)
{
	DIO_pin_write(port,0,READ_BIT(val,0));
	DIO_pin_write(port,1,READ_BIT(val,1));
	DIO_pin_write(port,2,READ_BIT(val,2));
	DIO_pin_write(port,3,READ_BIT(val,3));
}

void write_highnibble(char port,char val)
{
	DIO_pin_write(port,4,READ_BIT(val,0));
	DIO_pin_write(port,5,READ_BIT(val,1));
	DIO_pin_write(port,6,READ_BIT(val,2));
	DIO_pin_write(port,7,READ_BIT(val,3));
}
