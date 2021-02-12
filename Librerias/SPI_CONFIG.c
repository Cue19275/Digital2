#include "SPI_CONFIG.h"

void SPI_setup(uint8_t modo){
	switch(modo){
		case 0: //Master
		SSPCONbits.SSPM = 0b0000 ;
	

		break;
		case 1: //Master
		SSPCONbits.SSPM = 0b0001 ;
	

		break;
		case 2: //Master
		SSPCONbits.SSPM = 0b0010 ;
	

		break;				
		case 3://SLAVE
		SSPCONbits.SSPM = 0b0100 ;

		break;
		case 4://SLAVE
		SSPCONbits.SSPM = 0b0101 ;

		break;		
	}
	SSPCONbits.CKP = 0;
	SSPCONbits.SSPEN = 1;
	SSPSTATbits.CKE = 0;
	SSPSTATbits.SMP = 1;
}