/*
 * Opdracht 1.c
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
	
	DDRD = 0b11111111;			// All pins PORTD are set to output
	
	while (1)
	{
		PORTD = 0x80;			// Write 10101010b PORTD
		wait(500);
		PORTD = 0x40;			// Write 01010101b PORTD
		wait(500);
	}

	return 1;
}

