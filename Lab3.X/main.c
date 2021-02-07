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
//******************************************************************************
// Palabra de configuración
//******************************************************************************
// CONFIG1
//#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
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
uint8_t toggle = 0;
uint8_t valor_r = 0;
uint8_t valor_e = 0;
uint8_t pot1 = 0;
uint8_t pot2 = 0;
uint8_t terminal = 0;
uint8_t flag_T = 0;
uint8_t flag_T2 = 0;
uint8_t estado1 = 0;
uint8_t CONT = 0;


//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);
void ADC_LEER(void);
void debounce_T(void);

//******************************************************************************
// Vector de Interrupción
//******************************************************************************
void __interrupt() ISR(void){
    if (PIR1bits.ADIF == 1){
        PIR1bits.ADIF = 0;
        lec_ADC = ADRESH;
    }
    if (INTCONbits.TMR0IF == 1){
        INTCONbits.TMR0IF = 0;
        TMR0 = 236;
        go_adc++;
    }
    if (PIR1bits.RCIF == 1){
        terminal = RCREG; 
    }
    if (PIR1bits.TXIF == 1){
        TXREG = 0x30;
        PIE1bits.TXIE = 0;
    }
}
//******************************************************************************
// Ciclo principal
//******************************************************************************
void main(void) {
    TRISD = 0x00;
    initOsc(20);
    Setup();
    USARTconf();
    Lcd_Init();
    Lcd_Cmd(0x8A);
    ADCinit(11, 20);
    while (1){
        //Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("S1    S2    S3");
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("Voltajes:");
        ADC_LEER();
        if (terminal != 43 && terminal != 13 && terminal != 45){
            flag_T = 0;
            flag_T2 = 0;
        }
        debounce_T();
        //PORTA = CONT;
    }
}
//******************************************************************************
// Configuración
//******************************************************************************
void Setup(void){
    //CONFIG I&0
    PORTA = 0; //POT
    PORTB = 0; //Pantalla
    PORTC = 0; //nada
    PORTD = 0; //Pantalla
    ANSEL = 0;
    ANSELbits.ANS0 = 1;
    ANSELH = 0;
    TRISA = 0; //Output
    TRISB = 0b00011000; //Output Input
    TRISD = 0; //Output
    TRISC = 0b10000000;
    INTCONbits.TMR0IF = 0;
    PIR1bits.ADIF = 0;
    INTCONbits.RBIF = 0;
    
    
    OPTION_REG = 0b11010111; //Pullups, prescaler, y cosas del timer
    
    //CONFIG INTERRUPT
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    INTCONbits.RBIE = 0;
    PIE1bits.ADIE = 1;
    INTCONbits.T0IE = 1;
    TMR0 = 236;
    
    PIE1bits.RCIE = 1;
    PIE1bits.TXIE = 1;
    
}
//******************************************************************************
// ADC_LEER
//******************************************************************************
void ADC_LEER(void){
    if (go_adc > 5){
        go_adc = 0;
        ADCON0bits.GO_nDONE =1;
        if (toggle == 0){
            toggle = 1;
            ADCinit(1, 9); 
            pot1 = lec_ADC;
        }
        else{
            toggle = 0;
            ADCinit(1, 11);
            pot2 = lec_ADC;
        }
    }
}
//******************************************************************************
// Debounce_Terminal
//******************************************************************************
void debounce_T(void){
    if (terminal == 43){
        flag_T = 1;  
    }
    
    if (terminal == 13){
        if (flag_T == 1){
            flag_T = 0;
            CONT++;
        }
    }
    
    if (terminal == 45){
        flag_T2 = 1;
    }

    if(terminal ==13 && flag_T2 == 1){
        flag_T2 = 0;
        CONT--;
    }
}