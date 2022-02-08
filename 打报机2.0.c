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
{char led[] = {0x03, 0x9f, 0xFF};
int j = 0,a = 2,b = 2,c = 2,d = 2,e =2 ,f = 2,g = 2,h = 2;
 ENLED = 1;
	ENSEG = 0;
KEYOUT1 = 0;
while(1)	
{ADDR0 = 0;ADDR1 = 0;ADDR2 = 0;ADDR3 = 1;P0 = led[a];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[b];ENSEG = 0;ENSEG = 1;
		ADDR0 = 0;ADDR1 = 1;P0 = led[c];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[d];ENSEG = 0;ENSEG = 1;
		ADDR0 = 0;ADDR1 = 0;ADDR2 = 1;P0 = led[e];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[f];ENSEG = 0;ENSEG = 1;
		ADDR0 = 0;ADDR1 = 1;P0 = led[g];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[h];ENSEG = 0;ENSEG = 1;
	if((KEYIN1 && KEYIN2) == 0)
	{h = g;g = f; f = e;e = d;d = c;c = b;b = a;}
	while((KEYIN1 && KEYIN2) ==0)
	{if (KEYIN1 == 0)
		{j = 1;BUZZER = 0;}
		else if (KEYIN2 == 0)
		{j = 0;BUZZER = 0;}a = j;
	}
		BUZZER = 1;
		ADDR0 = 0;ADDR1 = 0;ADDR2 = 0;ADDR3 = 1;P0 = led[a];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[b];ENSEG = 0;ENSEG = 1;
		ADDR0 = 0;ADDR1 = 1;P0 = led[c];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[d];ENSEG = 0;ENSEG = 1;
		ADDR0 = 0;ADDR1 = 0;ADDR2 = 1;P0 = led[e];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[f];ENSEG = 0;ENSEG = 1;
		ADDR0 = 0;ADDR1 = 1;P0 = led[g];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[h];ENSEG = 0;ENSEG = 1;
	}
}