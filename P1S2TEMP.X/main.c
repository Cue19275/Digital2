//******************************************************************************
/*
 * File:   main.c
 * Author: Carlos Cuellar
 *
 * Fecha: 
 */
//******************************************************************************
// Importaci�n de Librer�as
//******************************************************************************

#include <xc.h>
#include <stdint.h>
#define _XTAL_FREQ 40000000

#include "Osc.h"
#include "ADCLIB.h"
#include "SPI.h"


//******************************************************************************
// Palabra de configuraci�n
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
uint8_t lec_ADC = 0;
uint8_t flt = 0;


//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);
void ADC_LEER(void);

//******************************************************************************
// Vector de Interrupci�n
//******************************************************************************
void __interrupt() isr(void){
   if(SSPIF == 1){
        spiWrite(lec_ADC);
        SSPIF = 0;
    }
   if (PIR1bits.ADIF == 1){
        PIR1bits.ADIF = 0;
        lec_ADC = ADRESH;
    }
    if (INTCONbits.TMR0IF == 1){
        INTCONbits.TMR0IF = 0;
        TMR0 = 236;
        go_adc++;
    }
}
//******************************************************************************
// Ciclo principal
//******************************************************************************

    void main(void) {
    initOsc(20);
    Setup();
    ADCinit(1, 0);
    //*************************************************************************
    // Loop infinito
    //*************************************************************************
    while(1){
        ADC_LEER();
        PORTB = lec_ADC;
        flt = lec_ADC;
        if(flt < 100){
            PORTD=1;
        }
        if(flt >= 100 && flt <= 114){
            PORTD=2;
        }
        if(flt > 114){
            PORTD=4;
        }
       
    }

}
//******************************************************************************
// Configuraci�n Setup
//******************************************************************************

void Setup(void) {
    ANSEL = 0;
    ANSELbits.ANS0 = 1;
    ANSELH = 0;
    TRISA = 1;
    TRISB = 0;
    TRISD = 0;
    TRISC = 0b00001000;
    PORTB = 0;
    PORTD = 0;
    
    OPTION_REG = 0b11010111;
    
    INTCONbits.GIE = 1;         // Habilitamos interrupciones
    INTCONbits.PEIE = 1;        // Habilitamos interrupciones PEIE
    PIR1bits.SSPIF = 0;         // Borramos bandera interrupci�n MSSP
    PIE1bits.SSPIE = 1;         // Habilitamos interrupci�n MSSP
    TRISAbits.TRISA5 = 1;       // Slave Select
    
    PIE1bits.ADIE = 1;
    INTCONbits.T0IE = 1;
    TMR0 = 236;
   
    spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);


}
//******************************************************************************
// ADC_LEER
//******************************************************************************
void ADC_LEER(void){
    if (go_adc > 10){
        go_adc = 0;
        ADCON0bits.GO_nDONE =1;
}
}