// Created by Brendan Matkin (c)2014. MIT License.
// Thanks to Nick Gammon http://gammon.com.au/interrupts
// This code is tested with the arduino-tiny core: https://code.google.com/p/arduino-tiny/
// choose the ATtiny8x 8MHz (internal oscillator, BOD disabled or 1.9v BOD) BOD uses lots of standby power
// Built for the ATtiny84 and common anode RGB LED
// Other info available at https://github.com/brendanmatkin/ATtiny_Workshop


#include <avr/sleep.h>
#include <avr/power.h>      // reduce power consumption even more (uncomment power_all_enable() & power_all_disable())
#define rd 3                // red pin - PWM
#define gn 4                // green pin - PWM
#define bl 5                // blue pin - PWM



// interrupt service routine:
void wake() {
  sleep_disable();               // make sure we don't go back to sleep
  detachInterrupt(0);            // immediately stop external interrupt
  power_all_enable();          // reduce standby from ~15uA to 500nA
}

void sleepNow() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  noInterrupts();                // disable interrupts so that we can re-enable and guarantee one more instruction
  power_all_disable();         // sleep power reduction
  sleep_enable();                // enable sleep
  attachInterrupt(0,wake,LOW);   // wake up on low level
  interrupts();                  // always guranteed one more instruction after re-enabling interrupts
  sleep_cpu();                   // go to sleep (in this case the very last command). 
}

void setup() {
  ADCSRA &= ~(1<<ADEN);  // disable ADC to save power!
  digitalWrite(2, HIGH); // pullup interrupt
}

void loop() {
  // Code goes here. It will run once when the processor wakes up
  xFade(5);              // common anode LED
  //xFadeCathode(5);     // common cathode LED
  sleepNow();
}


void xFade(int fadeSpeed){
  for(int i = 0; i < 255; i++){
    analogWrite(rd,255-i);
    delay(fadeSpeed);
  }
  for(int i = 0; i<255; i++){
    analogWrite(rd,i);
    analogWrite(gn,255-i);
    delay(fadeSpeed);
  }
  for(int i = 0; i<255; i++){
    analogWrite(gn,i);
    analogWrite(bl,255-i);
    delay(fadeSpeed);
  }
  for(int i = 0; i<255; i++){
    analogWrite(bl,i);
    analogWrite(rd,255-i);
    delay(fadeSpeed);
  }
  for(int i = 0; i<255; i++){
    analogWrite(rd,i);
    delay(fadeSpeed);
  }
  // make sure all LEDs are off
  digitalWrite(rd,HIGH);
  digitalWrite(gn,HIGH);
  digitalWrite(bl,HIGH);
}

void xFadeCathode(int fadeSpeed){
  for(int i = 0; i < 255; i++){
    analogWrite(rd,i);
    delay(fadeSpeed);
  }
  for(int i = 0; i<255; i++){
    analogWrite(rd,255-i);
    analogWrite(gn,i);
    delay(fadeSpeed);
  }
  for(int i = 0; i<255; i++){
    analogWrite(gn,255-i);
    analogWrite(bl,i);
    delay(fadeSpeed);
  }
  for(int i = 0; i<255; i++){
    analogWrite(bl,255-i);
    analogWrite(rd,i);
    delay(fadeSpeed);
  }
  for(int i = 0; i<255; i++){
    analogWrite(rd,255-i);
    delay(fadeSpeed);
  }
  // make sure all LEDs are off
  digitalWrite(rd,LOW);
  digitalWrite(gn,LOW);
  digitalWrite(bl,LOW);
}


