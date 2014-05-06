// Created by Brendan Matkin (c)2014. MIT License.
// Thanks to Nick Gammon http://gammon.com.au/interrupts
// This code is tested with the arduino-tiny code: https://code.google.com/p/arduino-tiny/
// choose the ATtiny8x 8MHz (internal oscillator, BOD disabled or 1.9v BOD)
// Built for the ATtiny84 and common anode RGB LED
// Other info available at https://github.com/brendanmatkin/ATtiny_Workshop


#include <avr/sleep.h>
#define rd 3 // red pin - PWM
#define gn 4 // green pin - PWM
#define bl 5 // blue pin - PWM

int c,c2,lum,lum2;

void wake() {
  sleep_disable();
  detachInterrupt(0);
}

void sleepNow() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  noInterrupts();
  sleep_enable();
  attachInterrupt(0,wake,LOW);
  interrupts();
  sleep_cpu();
}

void setup() {
  ADCSRA &= ~(1<<ADEN);  // disable ADC to save power!
  digitalWrite(2, HIGH); // pullup interrupt
}

void loop() {
  // Code goes here. It will run once when the processor wakes up
  xFade(5);          // common anode LED
  //xFadeCathode(5); // common cathode LED
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


