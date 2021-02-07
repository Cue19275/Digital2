//Librería extraída de Electrosome
#ifndef LCD8_H
#define LCD8_H

#include <xc.h>
#include <stdint.h>
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 40000000
#endif
#ifndef EN 
#define EN PORTBbits.RB0
#endif	
#ifndef RS 
#define RS PORTBbits.RB1
#endif	
#ifndef RW 
#define RW PORTBbits.RB2
#endif	

void Lcd_Port(char a);	
void Lcd_Cmd(char a);
void Lcd_Clear(void);
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init(void);
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right(void);
void Lcd_Shift_Left(void);
#endif