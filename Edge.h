#include "Arduino.h"

#ifndef Edge_h
#define Edge_h

static const byte LED_COUNT = 7;

class EdgeIteratorBase
{
  public:
    EdgeIteratorBase(uint8_t edge);
    uint8_t edge();
    bool moveNext();
    virtual uint8_t currentLed() = 0;
    void reset();
  protected:
    uint8_t _state;
};

class EdgeIteratorForward : public EdgeIteratorBase
{
  public:
    virtual uint8_t currentLed() {
        return (edge() * LED_COUNT) + (_state & LED_COUNT) - 1;
    }
};

class EdgeIteratorBackward : public EdgeIteratorBase
{
  public:
    virtual uint8_t currentLed() {
        return ((edge() + 1) * LED_COUNT) - (_state & LED_COUNT);
    }
};

#endif