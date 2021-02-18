

#include "LCD8BIT.h"

void Lcd_Port(char a)
{
	PORTD = a;
}

void Lcd_Init()
{
    __delay_ms(15);
    Lcd_Port(0x00);
    __delay_ms(20);
    Lcd_Cmd(0x30);
    __delay_ms(5);
    Lcd_Cmd(0x30);
    __delay_us(160);
    Lcd_Cmd(0x30);
    //**************************************************************************
    Lcd_Cmd(0x38);  //2 LINEAS | 5x8
    Lcd_Cmd(0x10);  
    Lcd_Cmd(0x01);
    Lcd_Cmd(0x06);  //INCREMENTO | DESPLAZAMIENTO DESACTIVADO
    //Lcd_Cmd(0x0F);
    Lcd_Cmd(0x0C);

}

void Lcd_Cmd(char a)
{
	RS = 0;     // => RS = 0
	Lcd_Port(a);
	EN  = 1;    // => E = 1
    __delay_ms(10);
    EN  = 0;    // => E = 0
}

void Lcd_Clear(void)
{
	Lcd_Cmd(0);
	Lcd_Cmd(1);
}

void Lcd_Set_Cursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
	  temp = 0x80 + b - 1;
		z = temp;
		Lcd_Cmd(z);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b - 1;
		z = temp;
		Lcd_Cmd(z);
	}
}


void Lcd_Write_Char(char a)
{
   RS = 1;             // => RS = 1
   Lcd_Port(a);             //Data transfer
   EN = 1;
   __delay_us(40);
   EN = 0;
   RS = 0;
}

void Lcd_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	   Lcd_Write_Char(a[i]);
}

void Lcd_Shift_Right()
{
	Lcd_Cmd(0x1C);
}

void Lcd_Shift_Left()
{
	Lcd_Cmd(0x018);
}

