#include "Arduino.h"
#include "Edge.h"

uint8_t _state;

EdgeIteratorBase::EdgeIteratorBase(uint8_t edge)
{
    _state = (edge << 3);
}

uint8_t EdgeIteratorBase::edge()
{
    return _state >> 3;
}

bool EdgeIteratorBase::moveNext()
{
    uint8_t current = _state & LED_COUNT;
    if (current == 7)
      return false;

    _state++;
    return true; 
}