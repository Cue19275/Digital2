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

//******************************************************************************
// Palabra de configuración
//******************************************************************************
// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
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
#define _XTAL_FREQ 8000000

//******************************************************************************
// Variables
//******************************************************************************
#define ROJO        PORTEbits.RE0
#define AMARILLO    PORTEbits.RE1
#define VERDE       PORTEbits.RE2
#define MRST        PORTCbits.RC5
#define BTN_1       PORTCbits.RC6
#define BTN_2       PORTCbits.RC7
#define IND_1       PORTCbits.RC0
#define IND_2       PORTCbits.RC1

unsigned char   estadoSalida;
unsigned char   estado;
unsigned char   estadoSalidaC2;
unsigned char   estadoC2;

//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);
void semaforo(void);
void debounceRC6 (void);
void debounceRC7 (void);

//******************************************************************************
// Ciclo principal
//******************************************************************************
void main(void) { 
    Setup();
    while (1){
        if (RC5 = 1){
            semaforo();
        }
        else if (PORTB > 0b01000000 ){
            IND_1 = 1;
            PORTE = 0;
            while(1){
                if (RC5 = 1){
                    semaforo();
                    break;
                }
            }
        }
        else if (PORTD > 0b01000000 ){
            IND_2 = 1;
            PORTE = 0;
            while(1){
                if (RC5 = 1){
                    semaforo();
                    break;
                }
            }
        }
        else if (VERDE == 1){
        debounceRC6(); 
        debounceRC7();
    }
        
}
}
//******************************************************************************
// Configuración
//******************************************************************************
void Setup(void){
    PORTB = 0; //Corredor 1
    PORTD = 0; //Corredor 2
    IND_1 = 0;
    IND_2 = 0;
    PORTE = 0; //Semaforo
    PORTC = 0; //Botones e Indicadores
    ANSEL = 0;
    ANSELH = 0;
    TRISB = 0; //Output Corredor 1
    TRISD = 0; //Output Corredor 2
    TRISE = 0; //Output Semaforo
    TRISC = 0b11100000; //Output/Input Botones e indicadores
    
    //TRISBbits.TRISB0 = 0;
    //PORTBbits.RB0 = 0;
}

//******************************************************************************
// semaforo
//******************************************************************************
void semaforo(void){
        ROJO = 0;
        AMARILLO = 0;
        VERDE = 0;
        PORTB = 0;
        PORTC = 0;
        PORTD = 0;
        
        
        
        __delay_ms(500);
       
       ROJO = 1;
       AMARILLO = 0;
       VERDE = 0;
       __delay_ms(500);
       
       ROJO = 0;
       AMARILLO = 1;
       VERDE = 0;
       __delay_ms(500);
       
       ROJO = 0;
       AMARILLO = 0;
       VERDE = 1;
       
}
//******************************************************************************
// Debounce_RC6
//******************************************************************************
void debounceRC6(void){ 
    estado = BTN_1 ;
    if (estado == 1){
        estadoSalida=1;
    }
    
    if (estadoSalida==1){
        if (estado == 0){
            if (PORTB == 0){
                PORTB = 1;
            }
            else {
                PORTB = PORTB << 1;
            }
            estadoSalida =0;
        }
    }
}
//******************************************************************************
// Debounce_RC7
//******************************************************************************
void debounceRC7(void){ 
    estadoC2 = BTN_2 ;
    if (estadoC2 == 1){
        estadoSalidaC2=1;
    }
    
    if (estadoSalidaC2==1){
        if (estadoC2 == 0){
            if (PORTD == 0){
                PORTD= 1;
            }
            else {
                PORTD = PORTD << 1;
            }
            estadoSalidaC2 =0;
        }
    }
}
