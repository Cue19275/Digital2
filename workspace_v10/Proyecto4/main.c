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
#include "driverlib/adc.h"
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
uint32_t ADC0Value;
uint8_t disponibles=0;
uint8_t p1=0;
uint8_t p2=0;
uint8_t p3=0;
uint8_t p4= 0;


/*
 * Prototipado de funciones
 */
void funcion1(void);

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
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);
    GPIOPinConfigure(GPIO_PB0_U1RX);
    GPIOPinConfigure(GPIO_PB1_U1TX);
    GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1);
    //GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0);
    UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 115200, UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE);
    //UARTFIFOEnable(UART1_BASE);
    /*UARTIntEnable(UART0_BASE, UART_INT_RX|UART_INT_RT);
    UARTIntRegister(UART0_BASE, funUART);*/
    UARTEnable(UART1_BASE);


    //DIGITAL_INPUT
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);


    //DIGITAL_OUTPUT
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_1|GPIO_PIN_2);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_2|GPIO_PIN_3);
    GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_6|GPIO_PIN_7);
    //TIMER0 DE 32 BITS
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER0_BASE, TIMER_A, ((SysCtlClockGet()/300)-1));
    IntEnable(INT_TIMER0A);
    TimerIntRegister(TIMER0_BASE, TIMER_A, funcion1);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

    TimerEnable(TIMER0_BASE, TIMER_A);





    //******************Loop****************************
    while(1){

    if(GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_1)==2){
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, GPIO_PIN_7);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 0);
        p1=48;
                }
    else{
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 0);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PIN_6);
        p1=49;
    }
    if(GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_0)==1){
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, 0);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, GPIO_PIN_2);
        p2=48;
                }
    else{
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_1, GPIO_PIN_1);
        GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_2, 0);
        p2=49;
    }
    if(GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_3)==8){
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4);
        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, 0);
        p3=48;
                }
    else{
        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_7, 0);
        GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_6, GPIO_PIN_6);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0);
        p3=49;
    }
    if(GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_2)==4){
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, GPIO_PIN_3);
        p4=48;
                }
    else{
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, GPIO_PIN_2);
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0);
        p4=49;
    }


    }
}

void funcion1(void){
    TimerIntClear(TIMER0_BASE, TIMER_A);
    UARTCharPutNonBlocking(UART1_BASE, p3);
    UARTCharPutNonBlocking(UART1_BASE, p4);
    UARTCharPutNonBlocking(UART1_BASE, p1);
    UARTCharPutNonBlocking(UART1_BASE, p2);
    UARTCharPutNonBlocking(UART1_BASE, 10);
        //GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 2);


}


