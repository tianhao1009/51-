#include <reg52.h>
sbit ADDR0 = P1^0;
sbit ADDR1 = P1^1;
sbit ADDR2 = P1^2;
sbit ADDR3 = P1^3;
sbit ENLED = P1^4;
sbit ENSEG = P1^5; 
sbit BUZZER = P1^6;
sbit KEYIN1  = P4^3;
sbit KEYIN2  = P3^2;
sbit KEYIN3  = P4^1;
sbit KEYIN4  = P2^3;
sbit KEYOUT1 = P2^7;
sbit KEYOUT2 = P2^6;
sbit KEYOUT3 = P2^5;
sbit KEYOUT4 = P2^4;
char led[] = {0xff,0x03, 0x9f, 0x25, 0x0d, 0x99, 0x49, 0x41, 0x1f,0x01, 0x09, 0x11, 0xc1, 0x63, 0x85, 0x61, 0x71};
int a = 0,b = 0,c = 0,d = 0,e =0 ,f = 0,g = 0,h = 0,keyout = 0;
void main()
{
	EA = 1;
	TMOD = 0x01;
	TH0  = 0xFF;
	TL0  = 0xFF;
	ET0  = 1;
	TR0 = 1;
	ENSEG = 0;
	KEYOUT1 = 0;
while(1)	
{
	for(keyout=0;keyout<4;keyout++)
	{if((KEYIN1 && KEYIN2 && KEYIN3 && KEYIN4) == 0)
	{h = g;g = f; f = e;e = d;d = c;c = b;b = a;}
	while((KEYIN1 && KEYIN2 && KEYIN3 && KEYIN4) ==0)
	{if (KEYIN1 == 0)
		{a = (keyout * 4+1);BUZZER = 0;}
		else if (KEYIN2 == 0)
		{a = (keyout * 4 + 2);BUZZER = 0;}
		else if (KEYIN3 == 0)
		{a = (keyout * 4 + 3);BUZZER = 0;}
		else if (KEYIN4 == 0)
		{a = (keyout * 4 + 4);BUZZER = 0;}
		}BUZZER = 1;
	switch (keyout)
			{case 0: KEYOUT1 = 1; KEYOUT2 = 0; break;
        case 1: KEYOUT2 = 1; KEYOUT3 = 0; break;
        case 2: KEYOUT3 = 1; KEYOUT4 = 0; break;
				case 3: KEYOUT4 = 1; KEYOUT1 = 0; break;
        default: break;}}
	
}
}
void InterruptTimer() interrupt 1
{
	TH0 = 0XFF;
	TL0 = 0XFF;
	ADDR0 = 0;ADDR1 = 0;ADDR2 = 0;ADDR3 = 1;P0 = led[a];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[b];ENSEG = 0;ENSEG = 1;
		ADDR0 = 0;ADDR1 = 1;P0 = led[c];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[d];ENSEG = 0;ENSEG = 1;
		ADDR0 = 0;ADDR1 = 0;ADDR2 = 1;P0 = led[e];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[f];ENSEG = 0;ENSEG = 1;
		ADDR0 = 0;ADDR1 = 1;P0 = led[g];ENSEG = 0;ENSEG = 1;
		ADDR0 = 1;P0 = led[h];ENSEG = 0;ENSEG = 1;
}