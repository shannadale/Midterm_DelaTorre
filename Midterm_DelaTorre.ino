/*====================================================
              IR COUNTER MIDTERM EXAM
======================================================
Description:
 This program uses two IR sensors to control a counter
 displayed on seven-segment.
  
Programmer:
  Dela Torre, Shanna Dale R.

Date:
  28 October 2026
------------------------------------------------------*/
/#include "decoder.h"

// GPIOS
const byte Ir_A = 36;
const byte Ir_B = 39;
const byte rst = 34;

// Variables
int counter = 0;
int inputAdd = 0;
int inputSub = 0;
int rstIn = 0;

void setup() {
  pinMode(Ir_A, INPUT);
  pinMode(Ir_B, INPUT);
  pinMode(rst, INPUT_PULLUP);
  // Initialize 7-segment display pins
  initDisplay();

  Serial.begin(9600);
}

void loop() {
rstIn = digitalRead(rst);
if (rstIn == HIGH){

  inputAdd = digitalRead(Ir_A);
  if (inputAdd == 0) {
    if (counter < 99) {
      counter++;
    }
    delay(300);
  }

  inputSub = digitalRead(Ir_B);
  if (inputSub == 0) {
    if (counter > 0) {
      counter--;
    }
    delay(300);
  }

  displayCounter(counter);
} else {
  counter = 8;
  }
  delay(50);
}