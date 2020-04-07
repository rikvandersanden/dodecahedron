#ifdef ARDUINO
  #include "Arduino.h"
#else
  #include <cstdint>
#endif

#ifndef Edge_h
#define Edge_h

class Edge
{
  public:
    Edge(uint8_t edge) 
    {
      _edge = edge;
    }
    uint8_t getEdge();
    uint8_t getStartVertex();
    uint8_t getEndVertex();
  private:
    uint8_t _edge;
    const static uint8_t _endVertices[];
    const static uint8_t _startVertices[];
};

#endif