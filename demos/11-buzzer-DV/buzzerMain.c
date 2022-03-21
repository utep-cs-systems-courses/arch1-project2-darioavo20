#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main() {
    configureClocks();
    enableWDTInterrupts();
    
    buzzer_init();
    buzzer_set_period(150);	/* start buzzing!!! 2MHz/1000 = 2kHz*/
    or_sr(0x18);     //CPU off, GIE on
}
int beepLimit = 1000;
int beepCount = 0;
int secondCount = 0;
void __interrupt_vec(WDT_VECTOR) WDT()
    {
      beepCount += 200;
      if(beepCount >= beepLimit)
	{
	  beepCount = 0;
	}else
	buzzer_set_period(beepCount);

      secondCount++;
      if(secondCount >= 250)
	{
	  secondCount = 0;
	  beepLimit += 100;
	  if(beepLimit >= 1000)
	    {
	      beepLimit = 0;
	    }
	}
    }

