
#include <io430g2553.h> 

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR|=BIT6; //select p1.6 as output
    P1OUT&=~(BIT6); //toggle off
    P1SEL|=BIT6;  //select 2nd function

    TACCR0=64000; //Setting up the PWM Frequency
    TACCR1=32000; //Initialising the Duty cycle to 50%
    TACCTL1|=OUTMOD_7; //Using Reset/Set mode to generate PWM wave
    TACTL|=TASSEL_2+MC_1; //Configuring the timer to use SMCLK and count in UP mode

}



/* 
int pwm=0,l=100; //Initializing required variables
while(1)
{ 
  __delay_cycles(5000); //Wait before changing the duty cycles, for smooth variation
    pwm+=l; //Change the duty cycle
    if(pwm==10000) l=-100;//If duty cycle is at maximum, start decreasing it
    if(pwm==0) l=100; //If duty cycle is at minimum, start increasing it
    TACCR1=pwm; //Set the duty cycles in the Capture/compare module

}
*/
