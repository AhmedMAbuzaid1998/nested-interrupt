/*
 * bitmask.h
 *
 * Created: 12/21/2023 7:57:53 AM
 *  Author: Ahmed Abuzaid
 */ 


#ifndef BITMASK_H_
#define BITMASK_H_

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    (reg|=(1<<bit))
#define TOG_BIT(reg,bit)    (reg^=(1<<bit))
#define CLC_BIT(reg,bit)    (reg&=~(1<<bit))
#define READ_BIT(reg,bit)   ((reg>>bit)&1)





#endif /* BITMASK_H_ */