

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __OSCILADOR_H_
#define	__OSCILADOR_H_

#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
//**************************************************************
// Prototipo de la funci�n para inicializar Oscilador Interno
// Parametros: Opci�n de frecuencia a utilizar ver p�g. 62 Manual
//**************************************************************
void initOsc(uint8_t frec);

#endif	/* XC_HEADER_TEMPLATE_H */