/*	Author: gyama009
 *  Partner(s) Name: 
 *	Lab Section: 022
 *	Assignment: Lab #8 Exercise #4
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
		unsigned char x = ADC;
		PORTB = ((x >= 18) << 0)+ ((x >= 36) << 1) + ((x >= 54) << 2) + ((x >= 72) << 3) + ((x >= 90) << 4) + ((x >= 108) << 5) + ((x >= 126) << 6) + ((x >= 144) << 7);
		PORTD = ((x >= 162) << 0) + ((x >= 180) << 1);
	}
	return 0;
}
