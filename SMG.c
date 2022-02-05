#include <reg52.h>
sbit ADDR0 = P1^0;
sbit ADDR1 = P1^1;
sbit ADDR2 = P1^2;
sbit ADDR3 = P1^3;
sbit ENLED = P1^4;
sbit ENSEG = P1^5; 
sbit BUZZER = P1^6;
sbit KEYIN1 = P4^3;
sbit KEYIN2 = P3^2;
sbit KEYOUT1 = P2^4;
void main()
{char led[] = {0x03, 0x9f, 0x25, 0x0d, 0x99, 0x49, 0x41, 0x1f,0x01, 0x09, 0x11, 0xc1, 0x63, 0x85, 0x61, 0x71};
	int i = 0;
int j = 0;
 ENLED = 0;
	ENSEG = 0;
 ADDR3 = 1;
 ADDR2 = 1;
 ADDR1 = 1;
 ADDR0 = 1;
BUZZER = 1;
KEYOUT1 = 0;
	while (1)
	{if (KEYIN1 == 0)
		j = 1;
		else if (KEYIN2 == 0)
			j = 0;
		else j = 2;
		switch(j)
		{case 0:P0 = led[0];BUZZER = 0;break;
		case 1:P0 = led[1];BUZZER = 0;break;
			case 2:P0 = 0xFF;BUZZER = 1;break;
			default: break;}
	}
}