#include "usart.h"

void USARTconf(void){
	//Setup enviar
	TXSTAbits.SYNC = 0;
	TXSTAbits.BRGH = 1;
	TXSTAbits.TX9 = 0;
	BAUDCTLbits.BRG16 = 0;
	SPBRGH = 0;
	SPBRG = 25;
	//SETUP RECIBIR
	RCSTAbits.SPEN = 1;
	RCSTAbits.RX9 = 0;
	RCSTAbits.CREN = 1;

	TXSTAbits.TXEN = 1;


}