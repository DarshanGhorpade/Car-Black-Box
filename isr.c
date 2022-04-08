#include <xc.h>
#include "main.h"
unsigned char sec,return_time;
void __interrupt() isr(void)
{
    static unsigned int count = 0;
    
    if (TMR2IF == 1)
    {
        if (++count == 1250) // 1sec
        {
            count = 0;
            if(sec>0)
            {
                sec--;
            }
            else if (sec== 0 && return_time>0)
                return_time--;
        
        }
        
        TMR2IF = 0;
    }
}