#include "FiveButton.h"

#define BUTTON_PIN A0

// Create a new FiveButton object on pin A0 with internal pullup.
FiveButton myButton(BUTTON_PIN, true);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int event = myButton.checkButton();

  switch (event) {
    case 1:
      Serial.println("Single click");
      break;
    case 2:
      Serial.println("Double click");
      break;
    case 3:
      Serial.println("Triple click");
      break;
    case 4:
      Serial.println("Hold");
      break;
    case 5:
      Serial.println("Long hold");
      break;
  }
}
