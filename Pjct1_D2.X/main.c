//******************************************************************************
/*
 * File:   main.c
 * Author: Carlos Cuellar
 *
 * Fecha: 
 */
//******************************************************************************
// Importación de Librerías
//******************************************************************************

#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 40000000

#include "Osc.h"
#include "ADCLIB.h"
#include "LCD8BIT.h"
#include "usart.h"
#include "ASCII_NUM.h"
#include "SPI.h"

//******************************************************************************
// Palabra de configuración
//******************************************************************************
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)



//******************************************************************************
// Variables
//******************************************************************************
uint8_t go_adc = 0;
uint8_t basura = 0;

//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);
void slave1(void);

//******************************************************************************
// Vector de Interrupción
//******************************************************************************

void __interrupt() ISR(void) {


}
//******************************************************************************
// Ciclo principal
//******************************************************************************

void main(void) {
    TRISD = 0x00;
    initOsc(20);
    Setup();
    spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);

    Lcd_Init();
    Lcd_Cmd(0x8A);
    while(1){
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("S1    S2    S3");
        Lcd_Set_Cursor(2,1);
        slave1();
       
       

    }
    return;
}
//******************************************************************************
// Configuración Setup
//******************************************************************************

void Setup(void) {
    //CONFIG I&0
    PORTA = 0; //POT
    PORTB = 0; //Pantalla
    PORTC = 0; //nada
    PORTD = 0; //Pantalla
    ANSEL = 0;
    ANSELbits.ANS0 = 1;
    ANSELH = 0;
    TRISA = 0b00000000; //Output
    TRISB = 0b00011000;
    TRISD = 0; //Output
    TRISC = 0b00010000;
    PORTCbits.RC2 = 1;
    INTCONbits.TMR0IF = 0;
    PIR1bits.ADIF = 0;
    INTCONbits.RBIF = 0;


    OPTION_REG = 0b11010111; //Pullups, prescaler, y cosas del timer

    //CONFIG INTERRUPT
    INTCONbits.GIE = 0;
    INTCONbits.PEIE = 0;

    INTCONbits.RBIE = 0;
    PIE1bits.ADIE = 1;
    INTCONbits.T0IE = 1;
    TMR0 = 236;

    PIE1bits.TXIE = 1;

    PIE1bits.SSPIE = 1;

}
//******************************************************************************
// Slave 1
//******************************************************************************
void slave1(void){
    PORTCbits.RC2 = 0;       //Slave Select
       __delay_ms(1);
       
       spiWrite(basura); //Es necesario para limipiar el buffer y habilitar SPI
       PORTA = spiRead(); //Mete al puerto lo que lee del SPI
       
       __delay_ms(1);
       PORTCbits.RC2 = 1;       //Slave Deselect 
    
}