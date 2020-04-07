#ifdef ARDUINO
  #include "Arduino.h"
#else
  #include <cstdint>
#endif

#include "Dodecahedron.h"
#include "Edge.h"
#include "Vertex.h"

#ifndef EdgeIterator_h
#define EdgeIterator_h

class EdgeIteratorBase
{
  public:
    EdgeIteratorBase(uint8_t edge) {
        _state = edge << 3;
    }
    uint8_t getEdge()
    {
      return _state >> 3;
    }
    void reset()
    {
      _state = getEdge() << 3;
    }
    bool moveNext()
    {
      uint8_t current = _state & LEDS_PER_EDGE;
      if (current == LEDS_PER_EDGE)
        return false;
      _state++;
 
       return true; 
    }
    virtual uint8_t getCurrentLed() = 0;
    virtual uint8_t begin() = 0;
    virtual uint8_t end() = 0;
    virtual uint8_t getStartVertex() = 0;
    virtual uint8_t getEndVertex() = 0;
    // EdgeIteratorBase *operator ++ (){
    //   moveNext();
    //   return this;
    // }
    virtual EdgeIteratorBase *getNextA() = 0;
    virtual EdgeIteratorBase *getNextB() = 0;
    static EdgeIteratorBase *getHamiltonianIterator(uint8_t vertex);
    static EdgeIteratorBase *getNonHamiltonianIterator(uint8_t vertex);
  protected:
    uint8_t _state;
};

class EdgeIteratorForward : public EdgeIteratorBase
{
  public:
    EdgeIteratorForward(uint8_t edge) : EdgeIteratorBase(edge) {}
    uint8_t getCurrentLed() override {
      return (getEdge() * LEDS_PER_EDGE) + (_state & LEDS_PER_EDGE) - 1;
    }
    uint8_t begin() override {
      return getEdge() * LEDS_PER_EDGE;
    }
    uint8_t end() override {
      return getEdge() * (LEDS_PER_EDGE + 1) - 1;
    }
    uint8_t getStartVertex() override {
      Edge foo(getEdge());
      return foo.getStartVertex();
    }
    uint8_t getEndVertex() override {
      Edge foo(getEdge());
      return foo.getEndVertex();
    }
    EdgeIteratorBase *getNextA() override {
      return new EdgeIteratorForward(getEndVertex());
    }
    EdgeIteratorBase *getNextB() override {
    
      if (getEdge() < VERTICES)
      {
        return getNonHamiltonianIterator(getEndVertex());
      }
      else
      {
        return getHamiltonianIterator(getEndVertex());
      }
    }
};

class EdgeIteratorBackward : public EdgeIteratorBase
{
  public:
    EdgeIteratorBackward(uint8_t edge) : EdgeIteratorBase(edge) {}
    uint8_t getCurrentLed() override {
      return ((getEdge() + 1) * LEDS_PER_EDGE) - (_state & LEDS_PER_EDGE);
    }
    uint8_t begin() override {
      return getEdge() * (LEDS_PER_EDGE + 1) -1;
    }
    uint8_t end() override {
      return getEdge() * LEDS_PER_EDGE;
    }
    uint8_t getStartVertex() override {
      Edge foo(getEdge());
      return foo.getEndVertex();
    }
    uint8_t getEndVertex() override {
      Edge foo(getEdge());
      return foo.getStartVertex();
    }
    EdgeIteratorBase *getNextA() override {
      return getHamiltonianIterator(getEndVertex());
    }
    EdgeIteratorBase *getNextB() override {
      if (getEdge() < VERTICES)
      {
        return getNonHamiltonianIterator(getEndVertex());
      }
      else
      {
        return new EdgeIteratorForward(getEndVertex());
      }
    }
};

#endif