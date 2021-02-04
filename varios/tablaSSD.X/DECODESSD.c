#include <xc.h>
#include <stdint.h>
#include <pic16f887.h>
#include "DECODESSD.h"
void tabla(uint8_t dec) {
    switch (dec){
        case 0:
            PORTC = 0b00111111;
            break;
        case 1:
            PORTC = 0b00000110;
            break;
    }
        
}
