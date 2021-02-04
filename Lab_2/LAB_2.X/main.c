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
#include "Osc.h"
#include "ADCLIB.h"
#include "DECODESSD.h"
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
uint8_t tiempo_mux = 0;
uint8_t sel_mux = 0;
uint8_t lec_ADC = 0;
uint8_t go_adc = 0;
uint8_t v = 1;
uint8_t can = 30;
uint8_t   estadoSalida;
uint8_t   estado;
uint8_t   estadoSalidaC2;
uint8_t   estadoC2;
uint8_t   nibbleH = 0;
uint8_t   nibbleL = 0;

#define BTN_1       PORTBbits.RB0
#define BTN_2       PORTBbits.RB1
//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);
void ADC_LEER(void);
void Alarma(void);
void nibbles(void);
//******************************************************************************
// Vector de Interrupción
//******************************************************************************
void __interrupt() ISR(void){
    if (INTCONbits.TMR0IF == 1){
        INTCONbits.TMR0IF = 0;
        TMR0 = 236;
        go_adc++;
        PORTEbits.RE1 = 0;
        PORTEbits.RE2 = 0;
        if (sel_mux == 0){
            sel_mux = 1;
            PORTEbits.RE1 = 1;
            nibbleH = (lec_ADC & 0b11110000) >> 4;
            tabla(nibbleH);
            
        }
        else{
            sel_mux = 0;
            PORTEbits.RE2 = 1;
            nibbleL = lec_ADC & 0b00001111;
            tabla(nibbleL);
        }
    }
    
    if (PIR1bits.ADIF == 1){
        PIR1bits.ADIF = 0;
        lec_ADC = ADRESH;
    }
    if (INTCONbits.RBIF == 1) {
        INTCONbits.RBIF = 0;
        //Aquí van los debounce de los dos botones
        estado = BTN_1 ;
        if (estado == 1){
            estadoSalida=1;
        }
    
        if (estadoSalida==1){
            if (estado == 0){
                PORTD++;
                estadoSalida = 0;
            }
        }
        estadoC2 = BTN_2 ;
        if (estadoC2 == 1){
            estadoSalidaC2=1;
        }
    
        if (estadoSalidaC2==1){
           if (estadoC2 == 0){
               PORTD--;
                estadoSalidaC2 =0;
            }
        }
    }  
        
    
}

//******************************************************************************
// Ciclo principal
//******************************************************************************
void main(void) { 
    initOsc(20);
    Setup();
    ADCinit(1, 20);
    while (1){
    ADC_LEER();
    Alarma();
    }
}
//******************************************************************************
// Configuración
//******************************************************************************
void Setup(void){
    //CONFIG I&0
    PORTA = 0; //POT
    PORTB = 0; //BOTONES
    PORTC = 0; //7SEG
    PORTD = 0; //CONT
    PORTE = 0; //Alarma & 2 Trans
    ANSEL = 0;
    ANSELbits.ANS0 = 1;
    ANSELH = 0;
    TRISA = 1; //Input
    TRISB = 0b11111111; //Intput
    TRISC = 0; //Output
    TRISD = 0; //Output
    TRISE = 0; //Output
    INTCONbits.TMR0IF = 0;
    PIR1bits.ADIF = 0;
    INTCONbits.RBIF = 0;
    
    
    OPTION_REG = 0b01010111; //Pullups, prescaler, y cosas del timer
    
    //CONFIG INTERRUPT
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    INTCONbits.RBIE = 1;
    WPUBbits.WPUB0 = 1;
    WPUBbits.WPUB1 = 1;
    IOCBbits.IOCB0 = 1;
    IOCBbits.IOCB1 = 1;
    PIE1bits.ADIE = 1;
    INTCONbits.T0IE = 1;
    TMR0 = 236;
    
    //TRISBbits.TRISB0 = 0;
    //PORTBbits.RB0 = 0;
}
//******************************************************************************
// ADC_LEER
//******************************************************************************
void ADC_LEER(void){
    if (go_adc > 5){
        go_adc = 0;
        ADCON0bits.GO_nDONE =1;
    }
}
//******************************************************************************
// Alarma
//******************************************************************************
void Alarma(void){
    if(lec_ADC > PORTD){
        PORTEbits.RE0 = 1;
    }
    else{
        PORTEbits.RE0 = 0;
    }
}
//******************************************************************************
// nibbles
//******************************************************************************
