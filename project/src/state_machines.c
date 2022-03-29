#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "buzzer_notes.h"
#include "state_machines.h"




// SWITCH 1
void play_song_1()
{
  static char curr_note = 0;
  static int  ledBool =0;
  // All notes of song, 0s are for break in between notes
  int notes[4] = {B3_FLAT, B3_FLAT, B3_FLAT, F3_SHARP };
  int n = 4;

  if (curr_note < n){
      buzzer_set_period(notes[curr_note]);
      curr_note++;
      if(ledBool){
	swap_leds(ledBool);
	ledBool =0;
      }
      else{
	swap_leds(ledBool);
	ledBool =1;
      }
	
  }
  else {
    curr_note = 0;
  }
  
}

// switch 2
void play_song_2(){
  static char curr_note = 0;
  static int  ledBool =0;
  // All notes of song, 0s are for break in between notes
  //thorugh the wire - kanye west
  int notes[40] = {B2, C3, A2, B2, C3, G3, A3, G3, A3, G3, A3,G3, A2, B2, C3, A2, B2, C3, C3, E3, D3, C3,B2, A2, G2, F3, F3, F3, F3, F3, E3, E3, C3, D3, E3, E3, G3, E3, F3, E3}; 
  int n = 40;
  if (curr_note < n){
      buzzer_set_period(notes[curr_note]);
      curr_note++;
      if(ledBool){
	swap_leds(ledBool);
	ledBool =0;
      }
      else{
	swap_leds(ledBool);
	ledBool =1;
      }
	
  }
  else {
    curr_note = 0;
  }
  
}
