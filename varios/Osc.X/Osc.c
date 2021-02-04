#include <stdint.h>
#include <pic16f887.h>
#include "Osc.h"
//**************************************************************
// Funci�n para inicializar Oscilador Interno
// Parametros: Opci�n de frecuencia a utilizar ver p�g. 62 Manual
//**************************************************************
void initOsc(uint8_t frec){
    switch(frec){
        case 0:                             // 31 KHz
            OSCCONbits.IRCF0 = 0;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 0;
            break;
        case 1:                             // 125 KHz
            OSCCONbits.IRCF0 = 1;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF2 = 0;
            break;
            
            /*************************************************** 
             * Ac� se deber�a de programar para todas las dem�s 
             * frecuencias, colocando un caso por cada una de 
             * las opciones que tiene el microcontrolador            
             ***************************************************/
           
        case 7:                             // 8 MHz
            OSCCONbits.IRCF0 = 1;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF2 = 1;
            break;
        default:                            // 4 MHz
            OSCCONbits.IRCF0 = 0;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF2 = 1;
            break; 
    }
    //En adc configurarlo, velocidad y canal
    //Tabla hacer cases: Cae 0 = 
    
    OSCCONbits.SCS = 1;      // Se utilizar� el reloj interno para el sistema
}