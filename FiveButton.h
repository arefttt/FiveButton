#ifndef FiveButton_h
#define FiveButton_h

#include "Arduino.h"

class FiveButton {
  public:
    FiveButton(int pin, bool useInternalPullup);
    int checkButton();
  private:
    int _pin;
    bool _useInternalPullup;
    bool isButtonPressed;
    bool wasButtonPressed;
    bool isWaitingForDoubleClick;
    bool isDoubleClickOnNextRelease;
    bool isTripleClickOnNextRelease;
    bool isSingleClickAllowed;
    long buttonPressTime;
    long buttonReleaseTime;
    bool ignoreButtonRelease;
    bool didHoldEventHappen;
    bool didLongHoldEventHappen;

    const int DEBOUNCE_TIME = 20;
    const int DOUBLE_CLICK_GAP = 250;
    const int TRIPLE_CLICK_GAP = 500;
    const int HOLD_TIME = 1000;
    const int LONG_HOLD_TIME = 3000;
};

#endif
