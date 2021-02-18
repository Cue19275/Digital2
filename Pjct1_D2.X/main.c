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
char CONT_U = 0x30;
char CONT_D = 0x30;
char CONT_C = 0x30;
char POT1_U = 0x30;
char POT1_D = 0x30;
char POT1_C = 0x30;
char POT2_U = 0x30;
char POT2_D = 0x30;
char POT2_C = 0x30;
char SIGN = 0X30;
uint8_t CONT = 0;
uint8_t temp2 = 0;
uint8_t temp3 = 0;
uint8_t pot2 = 0;
uint8_t var = 0;
uint8_t lec_ADC = 0;
uint8_t toggleS = 0;
uint8_t toggleTX = 0;

//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);
void slave1(void);
void slave3(void);
void slave2(void);
void map_pot1(void);
void map_pot2(void);
void map_cont(void);
const char* conver(void);
void slaveT (void);
void envio(void);

//******************************************************************************
// Vector de Interrupción
//******************************************************************************

void __interrupt() ISR(void) {
if (PIR1bits.TXIF == 1){
        toggleTX++;
        envio();
        PIE1bits.TXIE = 0;
    }
if (INTCONbits.TMR0IF == 1){
        INTCONbits.TMR0IF = 0;
        TMR0 = 100;
        var++;
        if(var == 2){
            PIE1bits.TXIE=1;
            var = 0;
        }
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
    spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
    
    
    
    Lcd_Init();
    //Lcd_Cmd(0x8A);
    while(1){
        toggleS++;
       
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("S1    S2    S3");
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String(conver());
        map_pot1();
        map_cont();
        map_pot2();
        slaveT();
        
        
        

       

    }
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
    TRISB = 0b00000000; //Output Input
    TRISD = 0; //Output
    TRISC = 0b00010000;
    PORTCbits.RC2 = 1;
    INTCONbits.TMR0IF = 0;
    PIR1bits.ADIF = 0;
    INTCONbits.RBIF = 0;


    OPTION_REG = 0b11010111; //Pullups, prescaler, y cosas del timer

    //CONFIG INTERRUPT
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.T0IE = 1;
    TMR0 = 250;

   

    PIE1bits.TXIE = 1;

    

}
//******************************************************************************
// Slave 1
//******************************************************************************
void slave1(void){
           PORTCbits.RC2 = 0;       //Slave Select
       __delay_ms(1);
       
       spiWrite(basura); //Es necesario para limipiar el buffer y habilitar SPI
       lec_ADC = spiRead(); //Mete al puerto lo que lee del SPI
       
       __delay_ms(1);
       PORTCbits.RC2 = 1;       //Slave Deselect 
}
//******************************************************************************
// Slave 3
//******************************************************************************
void slave3(void){
           PORTCbits.RC0 = 0;       //Slave Select
       __delay_ms(1);
       
       spiWrite(basura); //Es necesario para limipiar el buffer y habilitar SPI
       CONT = spiRead(); //Mete al puerto lo que lee del SPI
       
       __delay_ms(1);
       PORTCbits.RC0 = 1;       //Slave Deselect 
}
//******************************************************************************
// Slave 2
//******************************************************************************
void slave2(void){
           PORTCbits.RC1 = 0;       //Slave Select
       __delay_ms(1);
       
       spiWrite(basura); //Es necesario para limipiar el buffer y habilitar SPI
       pot2 = spiRead(); //Mete al puerto lo que lee del SPI
       
       __delay_ms(1);
       PORTCbits.RC1 = 1;       //Slave Deselect 
}
//******************************************************************************
// Mapeo Pot1
//******************************************************************************
void map_pot1(void){
    temp2 = lec_ADC;
    POT1_C = ((temp2*100)/51)/100;
    POT1_D = (((temp2*100)/51)-(POT1_C*100))/10;
    POT1_U = (((temp2*100)/51)-(POT1_C*100)-(POT1_D*10));
    POT1_C = num_ascii(POT1_C);
    POT1_D = num_ascii(POT1_D);
    POT1_U = num_ascii(POT1_U);
    
}
//******************************************************************************
// Mapeo Pot2
//******************************************************************************
void map_pot2(void){
    temp3 = pot2;
    if(temp3 >= 69){
    temp3 = ((temp3-69)*150)/186;
    POT2_C = (temp3/100);
    POT2_D = (temp3-(POT2_C*100))/10;
    POT2_U = (temp3-(POT2_C*100)-(POT2_D*10));
    POT2_C = num_ascii(POT2_C);
    POT2_D = num_ascii(POT2_D);
    POT2_U = num_ascii(POT2_U); 
    SIGN = 0x20;
    }
    else{
        temp3 = -((temp3-69)*55)/69;
    POT2_C = (temp3/100);
    POT2_D = (temp3-(POT2_C*100))/10;
    POT2_U = (temp3-(POT2_C*100)-(POT2_D*10));
    POT2_C = num_ascii(POT2_C);
    POT2_D = num_ascii(POT2_D);
    POT2_U = num_ascii(POT2_U); 
    SIGN = 0x2D;
    }
    
}
//******************************************************************************
// Mapeo Contador
//******************************************************************************
void map_cont(void){
   CONT_C =  CONT/100;
   CONT_D =  (CONT-(CONT_C*100))/10;
   CONT_U =  (CONT-(CONT_C*100)-(CONT_D*10));
   CONT_C = num_ascii(CONT_C);
   CONT_D = num_ascii(CONT_D);
   CONT_U = num_ascii(CONT_U);
}

//******************************************************************************
// Conv_Str
//******************************************************************************
const char* conver(void){
    char temporal[16];
    temporal[0] = CONT_C;
    temporal[1] = CONT_D;
    temporal[2] = CONT_U;
    temporal[3] = 0x20;
    temporal[4] = 0x20;
    temporal[5] = POT1_C;
    temporal[6] = 0x2E;
    temporal[7] = POT1_D;
    temporal[8] = POT1_U;
    temporal[9] = 0x76;
    temporal[10] = 0x20;
    temporal[11] = SIGN;
    temporal[12] = POT2_C;
    temporal[13] = POT2_D;
    temporal[14] = POT2_U;
    temporal[15] = 67;
    return temporal;
}
//******************************************************************************
// Slave Toggle
//******************************************************************************
void slaveT(void){
    if(toggleS == 1){
        slave1();
    }
    if(toggleS == 3){
        slave2();
    }
    if(toggleS == 5){
        slave3();
        toggleS = 0;
    }
}
//******************************************************************************
// Envio
//******************************************************************************
void envio(void){
    if (toggleTX == 1){ //c
        TXREG = CONT_C;
    }
    if (toggleTX == 2){ //u
        TXREG = CONT_D;
    }
    if (toggleTX == 3){ //d
        TXREG = CONT_U;
    }
    if (toggleTX == 4){ //,
        TXREG = 0x2C;
    }
    if (toggleTX == 5){ //spc
        TXREG = 0x20;
    }
    if (toggleTX == 6){ //c
        TXREG = POT1_C;
    }
    if (toggleTX == 7){ //.
        TXREG = 0x2E;
    }
    if (toggleTX == 8){//d
        TXREG = POT1_D;
    }
    if (toggleTX == 9){ //u
        TXREG = POT1_U;
    }
    if (toggleTX == 10){ //,
        TXREG = 0x2C;
    }
    if (toggleTX == 11){ //spc
        TXREG = 0x20;
    }
    if (toggleTX == 12){ //c
        TXREG = SIGN;
    }
    if (toggleTX == 13){ //.
        TXREG = POT2_C;
    }
    if (toggleTX == 14){ //u
        TXREG = POT2_D;
    }
    if (toggleTX == 15){ //d
        TXREG = POT2_U;
    }    
    if (toggleTX == 16){ //brk
        TXREG = 13;
        toggleTX = 0;
    }
    
    
}