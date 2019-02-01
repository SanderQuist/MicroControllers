/*
 * Opdracht 2.c
 *
 * Created: 30-1-2019 10:35:53
 * Author : Sander
 */ 

#include <avr/io.h>
#include <util/delay.h>

int state;

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
	state = 1;
	while(1){
		
		if(PINC & (1<<PC0) == 1 && state == 1){
			state = 2;
		}
		else if (PINC & (1<<PC0) ==1 && state == 2){
			state = 1;
		
		}
		 if(state == 1){
				 PORTD |= (1<<PD7);
				 wait(1000);
				 PORTD &= ~(1<<PD7);
				 wait(1000);
				 
		
		}else if(state == 2){
		
			PORTD |= (1<<PD7);
			wait(4000);
			PORTD &= ~(1<<PD7);
			wait(4000);
		}
	}
	
}

