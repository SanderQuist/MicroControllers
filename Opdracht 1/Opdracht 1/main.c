/*
 * Opdracht 2.c
 *
 * Created: 30-1-2019 10:35:53
 * Author : Sander
 */ 

#include <avr/io.h>
#include <util/delay.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms(1);		// library function (max 30 ms at 8MHz)
	}
}

int main( void )
{
	DDRD |= (1<<PD7); //Makes first pin of PORTC as Output
	// OR DDRC = 0x01;
	DDRC &= ~(1<<PC0);//Makes firs pin of PORTD as Input
	// OR DDRD = 0x00; //Makes all pins of PORTD input
	while(1) //infinite loop
	{
		if(PINC & (1<<PC0) == 1) //If switch is pressed
		{
			PORTD |= (1<<PD7); //Turns ON LED
			_delay_ms(3000); //3 second delay
			PORTD &= ~(1<<PD7); //Turns OFF LED
		}
	}
}

