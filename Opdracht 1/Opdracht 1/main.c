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
	char lampjes[10] = {1<<PD0,1<<PD1,1<<PD2,1<<PD3,1<<PD4,1<<PD5,1<<PD4,1<<PD3,1<<PD2,1<<PD1};
	char lampjes2[10] = {1<<PD7,1<<PD6,1<<PD5,1<<PD4,1<<PD3,1<<PD2,1<<PD3,1<<PD4,1<<PD5,1<<PD6};
	char lampjes3[10] = {1<<PC0,1<<PC1,1<<PC2,1<<PC3,1<<PC4,1<<PC5,1<<PC4,1<<PC3,1<<PC2,1<<PC1};
	while(1){
		int i;
		for(i = 0; i < 10;i++){
			PORTD |= lampjes[i];
			PORTD |= lampjes2[i];
			PORTC |= lampjes3[i];
			wait(1000);
			PORTD &= ~lampjes[i];
			PORTD &= ~lampjes2[i];
			PORTC &= ~lampjes3[i];
		}
	}
	
}

