#include <xc.h>



void init_timer2(void)
{
    /* Selecting the scale as 1:16 */
    T2CKPS0 = 1;
    T2CKPS1 = 1;

    /* Loading the Pre Load register with 250 */
    PR2 = 250;  //TMR2 -> 0 to 250
    
    /* The timer interrupt is enabled */
    TMR2IE = 1;
       
    /* Switching off the Timer2 */
    TMR2ON = 0;
}