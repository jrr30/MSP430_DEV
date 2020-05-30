/*
 * ADC.c
 *
 *  Created on: May 28, 2020
 *      Author: Jesus
 */

#include <msp430g2553.h>

/*
    ADC10CTL0 &= ~ENC;
    ADC10CTL0 |=   SREF_0 + ADC10SHT_2 + REFON + ADC10ON + ADC10IE + REF2_5V;
    ADC10CTL1 |= CONSEQ_0 +INCH_10 + SHS_0 + ADC10SSEL_3;
    ADC10CTL1 &= ~ADC10DF;
*/

/*
        ADC10CTL0 |= ADC10SC + ENC;
        Convert_Temp(&valor, celsius);
*/
float valor = 0;

typedef enum type_temp_T
{
    celsius,
    fahrenheit

} type_temp_T;

void Convert_Temp(float* temp_var, type_temp_T temp);


void Convert_Temp(float* temp_var, type_temp_T temp)
{
    if(celsius == temp)
    {
        *temp_var = ((((*temp_var - 673) * 423) / 1024));
    }
    else if(fahrenheit == temp)
    {
        *temp_var = (((*temp_var - 630) * 761) / 1024);
    }
}


#pragma vector=ADC10_VECTOR
__interrupt void ADC_ISR(void)
{
   valor = ADC10MEM;
}
