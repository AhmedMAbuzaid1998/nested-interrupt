/*
 * multi_isr_with_periority.c
 *
 * Created: 1/25/2024 8:53:42 AM
 *  Author: Ahmed Abuzaid
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "led.h"
#include "button.h"
#include "bitmask.h"
#include <avr/interrupt.h>
int main(void)
{
	led_inti('b',0);//led for ISR INT0
	led_inti('b',1);//led for ISR INT1
	led_inti('b',3);//led for ISR INT2
	button_inti('d',2);//button for ISR INT0
	button_inti('d',3);//button for ISR INT1
	button_inti('b',2);//button for ISR INT2
	sei();//to set interrupt bit (equal to set_bit(SREG,7)
	
	SET_BIT(GICR,INT0);//to enable INT0
	SET_BIT(GICR,INT1);//to enable INT1
	SET_BIT(GICR,INT2);//to enable INT2
	
	/* to set action (rising mode)for INT0 */
	SET_BIT(MCUCR,0);//equal to set_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,1);//equal to set_BIT(MCUCR,ISC01);
	
	/* to set action (rising mode)for INT1 */
	SET_BIT(MCUCR,2);//equal to set_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,3);//equal to set_BIT(MCUCR,ISC01);
	
	/* to set action (rising mode)for INT0 */
	SET_BIT(MCUCSR,6);//equal to set_BIT(MCUCSR,ISC2);
	
	while(1)
	{
		led_off('b',0);
		led_off('b',1);
		led_off('b',3);
	}
}



ISR (INT0_vect)
{
	sei();
	CLC_BIT(GICR,INT1);//to disable INT1
	CLC_BIT(GICR,INT2);//to disable INT2
	led_on('b',0);
	_delay_ms(2000);
	SET_BIT(GICR,INT1);//to enable INT1
	SET_BIT(GICR,INT2);//to enable INT2
	
}
ISR (INT1_vect)
{
	sei();
	CLC_BIT(GICR,INT2);//to disable INT2
	led_on('b',1);
	_delay_ms(2000);
	SET_BIT(GICR,INT2);//to enable INT2
}

ISR (INT2_vect)
{
	sei();
	led_on('b',3);
	_delay_ms(2000);
}
