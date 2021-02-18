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
uint8_t   estadoSalida;
uint8_t   estado;
uint8_t   estadoSalidaC2;
uint8_t   estadoC2;
#define BTN_1       PORTBbits.RB0
#define BTN_2       PORTBbits.RB1


//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);


//******************************************************************************
// Vector de Interrupción
//******************************************************************************
void __interrupt() isr(void){
   if(SSPIF == 1){
        spiWrite(PORTD);
        SSPIF = 0;
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
//*************************************************************************
// Loop infinito
//*************************************************************************
    while(1){
             
    }

}
//******************************************************************************
// Configuración Setup
//******************************************************************************

void Setup(void) {
    ANSEL = 0;
    ANSELH = 0;
    TRISB = 3; //Input dos botones
    TRISA = 0; //Luces cont
    TRISD = 0;
    TRISC = 0b00001000;
    PORTB = 0;
    PORTD = 0;
    
    OPTION_REGbits.nRBPU = 0;
    
    INTCONbits.GIE = 1;         // Habilitamos interrupciones
    INTCONbits.PEIE = 1;        // Habilitamos interrupciones PEIE
    PIR1bits.SSPIF = 0;         // Borramos bandera interrupción MSSP
    PIE1bits.SSPIE = 1;         // Habilitamos interrupción MSSP
    TRISAbits.TRISA5 = 1;       // Slave Select
    
    INTCONbits.RBIE = 1;
    WPUBbits.WPUB0 = 1;
    WPUBbits.WPUB1 = 1;
    IOCBbits.IOCB0 = 1;
    IOCBbits.IOCB1 = 1;

   
    spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);


}
