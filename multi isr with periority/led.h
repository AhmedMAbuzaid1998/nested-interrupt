/*
 * led.h
 *
 * Created: 1/11/2024 9:11:28 AM
 *  Author: Ahmed Abuzaid
 */ 


#ifndef LED_H_
#define LED_H_

void led_inti(char port,char pin);
void led_on(char port,char pin);
void led_off(char port,char pin);
void led_tog(char port,char pin);
char led_status(char port,char pin);

/*
led_inti(char port,char pin) to set the led pin as output
led_on(char port,char pin) to make the led on take the name of port and the pin number
led_off(char port,char pin) to make the led off take the name of port and the pin number
led_tog(char port,char pin) to toggel the led take the name of port and the pin number
char led_status(char port,char pin);to read the led status return 1 if led on and 0 if the led off
*/

#endif /* LED_H_ */