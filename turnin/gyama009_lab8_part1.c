/*	Author: gyama009
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #8 Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Set port A to input
	DDRB = 0xFF; PORTB = 0x00; // Set port B to output
	DDRD = 0xFF; PORTD = 0x00; // Set port D to output
	ADC_init();
	while (1) {
		unsigned short my_short = ADC;
        	unsigned char Bout = (char) my_short; // my_char = 0xCD
        	unsigned char Dout = (char) (my_short >> 8); // my_char = 0xBC
		PORTB = Bout;
		PORTD = Dout;
	}
	return 0;
}
