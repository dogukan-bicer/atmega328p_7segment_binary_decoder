#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
volatile uint8_t deger;
int main(void)
{
	DDRB &= 0B00111100; //b2-b5 giris
	DDRD = 0B01111111;  //d0-d6 cıkıs
	while (1)
	{
		_delay_ms(100); //debounce ı önlemek için
		deger=(PINB & 0x3c);//çoklu okuma icin maskeleme
		switch (deger)
		{
			case 4:
			PORTD=0b00110000;/////////////////////1
			break;
			
			case 8:
			PORTD=0b01101101;/////////////////////2
			break;
			
			case 12:
			PORTD=0b01111001;/////////////////////3
			break;
			
			case 16:
			PORTD=0b00110011;/////////////////////4
			break;
			
			case 20:
			PORTD=0b01011011;/////////////////////5
			break;
			
			case 24:
			PORTD=0b01011111;/////////////////////6
			break;
			
			case 28:
			PORTD=0b01110000;/////////////////////7
			break;
			
			case 32:
			PORTD=0b01111111;/////////////////////8
			break;
			
			case 36:
			PORTD=0b1111011;/////////////////////9
			break;
			
			default:
			PORTD=0b11111110;////////////////////0

		}
	}
	
}
