#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

int main(void)
{
    // Habilitar los periféricos para los puertos N y J
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);

    // Asegurarse de que los periféricos estén listos
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION))
    {
    }
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOJ))
    {
    }

    // Configurar PN1 como salida (LED)
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);

    // Configurar PJ1 como entrada (interruptor)
    GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_1);

    // Habilitar resistencia pull-up en PJ1
    GPIOPadConfigSet(GPIO_PORTJ_BASE, GPIO_PIN_1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    while(1)
    {
        // Leer el estado del interruptor PJ1
        uint8_t switchState = GPIOPinRead(GPIO_PORTJ_BASE, GPIO_PIN_1);

        if(switchState == 0) // El interruptor está presionado
        {
            // Encender el LED en PN1
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
        }
        else // El interruptor no está presionado
        {
            // Apagar el LED en PN1
            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);
        }
    }
}
