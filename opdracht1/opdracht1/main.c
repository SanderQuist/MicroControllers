/*
 * opdracht1.c
 *
 * Created: 30-1-2019 10:37:03
 * Author : timvg
 */ 

#include <avr/io.h>
#include <util/delay.h>

// Define the SetLed function
void SetLed( char nLed );

// Define the SetPowerGauge function
void SetPowerGauge( int nPower );

// Define the main function
void main()
{
	PORTB &= 0xF8;	// set the lower 3 bits to 0, ie off
	DDRB  |= 0x07;	// set the lower 3 bits to 1, ie output
	
	// Start endless loop
	while( 1 )
	{
		// Start a for loop, counting from 0 to 5
		for ( char i = 0; i < 6; i++ )
		{
			// Turn on Led i
			SetLed( i );
			_delay_ms(1000);
		}
	}
}

// Switch the state of a LED, from on to off, or from off to on
void SetLed( char nLed )
{
	// Clear existing status, we can only drive on led at a time
	PORTB &= 0xF8;	// set the lower 3 bits to 0, ie off
	DDRB  |= 0x07;	// set the lower 3 bits to 1, ie output

	switch ( nLed )
	{
		case 0:
		DDRB  &= 0xFB;  // Disconnect the nr. 2 pin
		PORTB |= 0x01;  // Set pin 0 to high and pin 1 to low
		break;
		
		case 1:
		DDRB  &= 0xFB;  // Disconnect the nr. 2 pin
		PORTB |= 0x02;  // Set pin 1 to high and pin 0 to low
		break;
		
		case 2:
		DDRB  &= 0xFE;  // Disconnect the nr. 0 pin
		PORTB |= 0x02;  // Set pin 1 to high and pin 2 to low
		break;

		case 3:
		DDRB  &= 0xFE;  // Disconnect the nr. 0 pin
		PORTB |= 0x04;  // Set pin 2 to high and pin 1 to low
		break;
		
		case 4:
		DDRB  &= 0xFD;  // Disconnect the nr. 1 pin
		PORTB |= 0x01;  // Set pin 0 to high and pin 2 to low
		break;
		
		case 5:
		DDRB  &= 0xFD;  // Disconnect the nr. 1 pin
		PORTB |= 0x04;  // Set pin 2 to high and pin 0 to low
		break;
	}
}

// Set the power gauge to the assigned level
void SetPowerGauge( int nPower )
{
	// Clear the leds, set the lower 6 bits to 0, ie off
	PORTB &= 0xC0;
	
	// Start a for loop, counting from 0 to nPower
	for ( char i = 0; i < nPower; i++ )
	{
		// Turn on Led i
		SetLed( i );
	}
}