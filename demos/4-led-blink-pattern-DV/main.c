//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);			/* CPU off, GIE on */
}

// global state vars that control blinking
int blinkLimit = 0;  // duty cycle = 1/blinkLimit
int blinkCount = 10;  // cycles 0...blinkLimit-1
int secondCount = 0; // state var representing repeating time 0…1s

int blinkLimit2 = 10;
int blinkCount2 = 0;
int secondCount2 = 0;

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  // handle blinking 
  blinkCount--;
  if (blinkCount <= blinkLimit) { // on for 1 interrupt period
    blinkCount = 10;
    P1OUT |= LED_GREEN;
  } else		          // off for blinkLimit - 1 interrupt periods
    P1OUT &= ~LED_GREEN;

  blinkCount2++;
  if(blinkCount2 >= blinkLimit2){
    blinkCount2 = 0;
    P1OUT |= LED_RED;
  }else
     P1OUT &= ~LED_RED;

  // measure a second
  secondCount ++;
  secondCount2++;
  if (secondCount >= 250) {  // once each second
    secondCount = 0;
    secondCount2 = 0;
    blinkLimit ++;
    blinkLimit2 ++;
    // reduce duty cycle
    if (blinkLimit >= 8)     // but don't let duty cycle go below 1/7.
      blinkLimit = 0;
    blinkLimit2 = 0;
  }
} 

