#include <msp430.h>
#include "switches.h"

//Switches on P2

void __interrupt_vec(PORT2_VECTOR) PORT_2()
{
  if(P2IFG & SWITCHES) // did a button cause this interrupt
    {
      P2IFG &= ~SWITCHES; // clear pending sw interrupts
      switch_interrupt_handler(); // SIngle handler for all switches
    }
}
