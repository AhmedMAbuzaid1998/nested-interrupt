/*
 * led.h
 *
 * Created: 1/11/2024 9:11:28 AM
 *  Author: Ahmed Abuzaid
 */ 


#ifndef LED_H_
#define LED_H_

void button_inti(char port,char pin);
char button_val(char port,char pin);

/*
button_inti(char port,char pin) to set the button pin as input
char button_val(char port,char pin);to read the buttun value return 1 if led on and 0 if the led off (pull down case)
*/

#endif /* LED_H_ */