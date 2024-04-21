#include "stdio.h"
#include "pico/stdlib.h"
#include "hardware/timer.h"

#include "McuLib.h"
#include "McuWait.h"
#include "McuGPIO.h"

#include "uart_communication.h"
#include "motor_ansteuerung.h"
#include "FreeRtosPren.h"
#include "aktoren.h"

#include "McuRB.h"

#define DEBUG (1)

//Ringbuffer
McuRB_Handle_t Ringbuffer = NULL;
McuRB_Handle_t UartReceiveBuffer = NULL;

//Hubmagnete
McuGPIO_Handle_t Hubmagnet1_Pin;
McuGPIO_Handle_t Hubmagnet2_Pin;
McuGPIO_Handle_t Hubmagnet3_Pin;
McuGPIO_Handle_t Hubmagnet4_Pin;

//Endschalter
McuGPIO_Handle_t Endschalter1_Pin;
McuGPIO_Handle_t Endschalter2_Pin;

//Lautsprecher
McuGPIO_Handle_t Lautsprecher_Pin;

//MCUwait
uint32_t SystemCoreClock = 120000000;


int main(void) {

     #if DEBUG
          timer_hw->dbgpause = 0;
     #endif
     Ringbuffer = NULL;

    stdio_init_all();
    McuWait_Init();

    /*INIT*/
    //Motor Init
    Motor_Ansteuerung_Init();
    //uart
    uart_Communication_Init();
    //aktoren
    aktorenInit();

    FreeRtosInit();
    vTaskStartScheduler();

    for(;;) {}
    return 0;
}