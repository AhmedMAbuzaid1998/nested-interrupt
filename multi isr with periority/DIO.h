/*
 * def.h
 *
 * Created: 12/26/2023 8:29:08 PM
 *  Author: Ahmed Abuzaid
 */ 


#ifndef DEF_H_
#define DEF_H_
enum status {input,output};//for direction replace input by 0 and output by 1
#define high 1
#define low 0
void DIO_setpin_dir(char port,char pin,char dir);//set pin direction
void DIO_pin_write(char port,char pin,char level);//write on output pin
void DIO_toggelpin(char port,char pin);//toggel output pin
unsigned char DIO_pin_read(char port,char pin);//read specific pin in a port
void DIO_set_portdir(char port,char dir);//set port direction
unsigned char DIO_read_portval(char port);
void DIO_write_allport(char port,char val);
void DIO_port_toggel(char port);
void DIO_connect_pullup(char port,char pin,char val);
void write_lownibble(char port,char val);
void write_highnibble(char port,char val);
/*
	DIO_setpin_dir(port name,pin number,output or input);//to set pin direction
	DIO_pin_write(port name,pin number,high or low);//to write high voltage or low voltage in a pin
	DIO_pin_read(port name,pin number);//to read the value on a pin return 1 if high or zero if low 
	DIO_toggelpin(port name,pin number);//to toggel the pin value
	DIO_set_portdir(port name,dir);//to set all port direction (dir is a value from 0(00000000) to 255(11111111))
	DIO_read_portval(port name);//read the value over the all port 
	DIO_write_allport(port name,val);//to write a value over the all port (val is a value from 0(00000000)all pins input to 255(11111111) all pins oiutput)
	DIO_port_toggel(port name);//to toggel all the port value
	void DIO_connect_pullup(char port,char pin,char val)//to activate internal pull up take port name pin number and takes 1 to enable pull up and zero to disable it
void write_lownibble(char port,char val);//to choose the low nibble (first 4 bit )takes port name and val 0
void write_lownibble(char port,char val);//to choose the low nibble (second four bits)takes port name and val 1

	*/


#endif /* DEF_H_ */