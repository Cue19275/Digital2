/*
 * File:   ADCLIB.c
 * Author: Carlo
 *
 * Created on 2 de febrero de 2021, 12:22
 */
#include <xc.h>
#include <stdint.h>
#include <pic16f887.h>
#include "ADCLIB.h"

void ADCinit(uint8_t vel, uint8_t chan){
    switch(vel){
        case 1: //Este es el que usamos siempre 
            ADCON0bits.ADCS0 = 1;
            ADCON0bits.ADCS1 = 0;
            break;
        case 2:
            ADCON0bits.ADCS0 = 0;
            ADCON0bits.ADCS1 = 1;
            break;
        case 3:
            ADCON0bits.ADCS0 = 1;
            ADCON0bits.ADCS1 = 1;
            break;
        default:
            ADCON0bits.ADCS0 = 0;
            ADCON0bits.ADCS1 = 0;
            break;
            
    }
    switch(chan){
        default:
            ADCON0bits.CHS0 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 0;
            break;
        case 1:
            ADCON0bits.CHS0 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 0;
            break;
        case 2:
            ADCON0bits.CHS0 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 0;
            break;
        case 3:
            ADCON0bits.CHS0 = 1;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 0;
            break;
        case 4:
            ADCON0bits.CHS0 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS3 = 0;
            break;
        case 5:
            ADCON0bits.CHS0 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS3 = 0;
            break;
        case 6:
            ADCON0bits.CHS0 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS3 = 0;
            break;
        case 7:
            ADCON0bits.CHS0 = 1;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS3 = 0;
            break;
        case 8:
            ADCON0bits.CHS0 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 1;
            break;
        case 9:
            ADCON0bits.CHS0 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 1;
            break;
        case 10:
            ADCON0bits.CHS0 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 1;
            break;
        case 11:
            ADCON0bits.CHS0 = 1;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 1;
            break;
        case 12:
            ADCON0bits.CHS0 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS3 = 1;
            break;    
        case 13:
            ADCON0bits.CHS0 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 1;
            ADCON0bits.CHS3 = 1;
            break; 
    }
    ADCON0bits.GO_nDONE =0;
    ADCON0bits.ADON = 1;
    ADCON1 = 0;
    
}
