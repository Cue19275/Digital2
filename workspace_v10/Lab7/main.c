#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

/*
 * Interrupciones
 */

/*
 * Variables
 */
uint8_t variable = 0;
uint8_t LED=0;
uint8_t    viene=0;
uint8_t anterior=1;

/*
 * Prototipado de funciones
 */
void funcion1(void);
void funUART(void);

//main.c
int main(void)
{
    //****************************************************
    //*******************Setup****************************
    //****************************************************
    //OSC
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    IntMasterEnable();
    //UART
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    //GPIOPinConfigure(GPIO_PA1_U0TX);
    //GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0|GPIO_PIN_1);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE);
    UARTFIFOEnable(UART0_BASE);
    UARTIntEnable(UART0_BASE, UART_INT_RX|UART_INT_RT);
    UARTIntRegister(UART0_BASE, funUART);

    UARTEnable(UART0_BASE);
    IntEnable(INT_UART0);

    //DIGITAL_OUTPUT
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    //TIMER0 DE 32 BITS
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER0_BASE, TIMER_A, ((SysCtlClockGet()/2)-1));
    IntEnable(INT_TIMER0A);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

    TimerEnable(TIMER0_BASE, TIMER_A);





    //******************Loop****************************
    while(1){

    }
}

void funcion1(void){
    TimerIntClear(TIMER0_BASE, TIMER_A);
    variable++;
    if (variable==1){
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, LED);
    }
    else if (variable==2){
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
        variable=0;
        }

}

void funUART(void){
    UARTIntClear(UART0_BASE, UART_INT_RX|UART_INT_RT);
    viene=UARTCharGet(UART0_BASE);
    if(viene==anterior){
        LED=0;
        anterior=0;
    }
    else{
        if(viene==114){
            LED=2;
        }
        else if(viene==103){
            LED=8;
        }
        else if(viene==98){
            LED=4;
        }
        anterior=viene;
    }

}
