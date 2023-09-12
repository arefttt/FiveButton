#include "Arduino.h"
#include "FiveButton.h"

FiveButton::FiveButton(int pin, bool useInternalPullup) {
  _pin = pin;
  _useInternalPullup = useInternalPullup;

  if (_useInternalPullup) {
    pinMode(_pin, INPUT_PULLUP);
  } else {
    pinMode(_pin, INPUT);
  }

  isButtonPressed = HIGH;
  wasButtonPressed = HIGH;
  isWaitingForDoubleClick = false;
  isDoubleClickOnNextRelease = false;
  isTripleClickOnNextRelease = false;
  isSingleClickAllowed = true;
}

int FiveButton::checkButton() {
  int event = 0;
  isButtonPressed = digitalRead(_pin);
  
  // Button pressed down
  if (isButtonPressed == LOW && wasButtonPressed == HIGH && (millis() - buttonReleaseTime) > DEBOUNCE_TIME)
  {
    buttonPressTime = millis();
    ignoreButtonRelease = false;
    
    if ((millis() - buttonReleaseTime) < DOUBLE_CLICK_GAP && !isDoubleClickOnNextRelease && isWaitingForDoubleClick)
      isDoubleClickOnNextRelease = true;
    else if ((millis() - buttonReleaseTime) < TRIPLE_CLICK_GAP && !isTripleClickOnNextRelease && isWaitingForDoubleClick)
      isTripleClickOnNextRelease = true;
      
    isWaitingForDoubleClick = false;
  }
  
  // Button released
  else if (isButtonPressed == HIGH && wasButtonPressed == LOW && (millis() - buttonPressTime) > DEBOUNCE_TIME)
  {
    if (!ignoreButtonRelease)
    {
      buttonReleaseTime = millis();
      
      if (!isTripleClickOnNextRelease && !isDoubleClickOnNextRelease)
        isWaitingForDoubleClick = true;

      else if (isTripleClickOnNextRelease)
      {
        event = 3; // Triple click event
        isTripleClickOnNextRelease = false;
        isWaitingForDoubleClick = false;
        isSingleClickAllowed = false;
      }
      
      else if (isDoubleClickOnNextRelease)
      {
        event = 2; // Double click event
        isTripleClickOnNextRelease = false;
        isWaitingForDoubleClick = false;
        isSingleClickAllowed = false;
      }
      
      // Test for normal click event: DOUBLE_CLICK_GAP expired
      if (isWaitingForDoubleClick && !isTripleClickOnNextRelease && !isDoubleClickOnNextRelease &&
          isSingleClickAllowed && event != 2)
      {
        event = 1; // Single click event
        isWaitingForDoubleClick = false;
      }
      
      // Test for hold
      if ((millis() - buttonPressTime) >= HOLD_TIME)
      {
        // Trigger "normal" hold
        if (!didHoldEventHappen)
        {
          event = 4; // Hold event
          ignoreButtonRelease = true;
          didHoldEventHappen = true;

          return event; // Return immediately to avoid long hold detection below
        }
        
        // Trigger "long" hold
        if ((millis() - buttonPressTime) >= LONG_HOLD_TIME) {
          if (!didLongHoldEventHappen)
          {
            event = 5; // Long hold event
            didLongHoldEventHappen = true;

            return event; // Return immediately to avoid further processing
          }
        }
        
      }
      
    }
    
  }

  
  wasButtonPressed = isButtonPressed;

  
}
