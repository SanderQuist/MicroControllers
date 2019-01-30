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
	DDRD = 0b11111111;
	while(1){
		PORTD |= (1<<PD0);
		wait(1000);
		PORTD &= ~(1<<PD0);
		PORTD |= (1<<PD1);
		wait(1000);
		PORTD &= ~(1<<PD1);
		PORTD |= (1<<PD2);
		wait(1000);
		PORTD &= ~(1<<PD2);
		PORTD |= (1<<PD3);
		wait(1000);
		PORTD &= ~(1<<PD3);
		PORTD |= (1<<PD4);
		wait(1000);
		PORTD &= ~(1<<PD4);
		PORTD |= (1<<PD5);
		wait(1000);
		PORTD &= ~(1<<PD5);
		PORTD |= (1<<PD6);
		wait(1000);
		PORTD &= ~(1<<PD6);
		PORTD |= (1<<PD7);
		wait(1000);
		PORTD &= ~(1<<PD7);
	}
	
}

