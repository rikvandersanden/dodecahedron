#include "Arduino.h"
#include "Dodecahedron.h"

#ifndef EdgeIterator_h
#define EdgeIterator_h

class EdgeIteratorBase
{
  public:
    EdgeIteratorBase(uint8_t edge) {
        _state = edge << 3;
    }
    uint8_t edge()
    {
      return _state >> 3;
    }
    void reset()
    {
      _state = edge() << 3;
    }
    bool moveNext()
    {
      uint8_t current = _state & LEDS_PER_EDGE;
      if (current == LEDS_PER_EDGE)
        return false;
      _state++;
 
       return true; 
    }
    virtual uint8_t currentLed() = 0;
    virtual uint8_t startVertex() = 0;
    virtual uint8_t endVertex() = 0;
    static EdgeIteratorBase *getHamiltonianIterator(uint8_t vertex);
    static EdgeIteratorBase *getNonHamiltonianIterator(uint8_t vertex);
  protected:
    uint8_t _state;
};

class EdgeIteratorForward : public EdgeIteratorBase
{
  public:
    EdgeIteratorForward(uint8_t edge) : EdgeIteratorBase(edge) {}
    virtual uint8_t currentLed() {
        return (edge() * LEDS_PER_EDGE) + (_state & LEDS_PER_EDGE) - 1;
    }
    virtual uint8_t startVertex() {
        return Dodecahedron::getStartVertex(edge());
    }
    virtual uint8_t endVertex() {
        return Dodecahedron::getEndVertex(edge());
    }
};

class EdgeIteratorBackward : public EdgeIteratorBase
{
  public:
    EdgeIteratorBackward(uint8_t edge) : EdgeIteratorBase(edge) {}
    virtual uint8_t currentLed() {
      return ((edge() + 1) * LEDS_PER_EDGE) - (_state & LEDS_PER_EDGE);
    }
    virtual uint8_t startVertex() {
      return Dodecahedron::getEndVertex(edge());
    }
    virtual uint8_t endVertex() {
      return Dodecahedron::getStartVertex(edge());
    }
};

#endif