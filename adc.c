#include <xc.h>

void init_adc(void)
{
    /* Selecting Right Justification */
    ADFM = 1;
    
    /* Starting the ADC Module */
    ADON = 1;
}

unsigned short read_adc(void)
{
    unsigned short adc_reg_val; // 2bytes
    
    /* Start the ADC conversion */
    GO = 1;
    
    /* Wait for the conversion to complete */
    while (nDONE); //nDONE = 0 GO = 0
  
    adc_reg_val = (unsigned short)(ADRESH << 8) | ADRESL;  // 11 1111 1111 -> 1023
    
    return adc_reg_val; // 0 to 1023
    
}
