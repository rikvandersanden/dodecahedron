#ifdef ARDUINO
  #include "Arduino.h"
#else
  #include <cstdint>
#endif

#ifndef Vertex_h
#define Vertex_h

class Vertex
{
  public:
    Vertex(uint8_t vertex)
    {
      _vertex = vertex;
    }
    int8_t getDefaultEdge();
    int8_t getHamiltonianEdge();
    int8_t getNonHamiltonianEdge();
  private:
    uint8_t _vertex;
};

#endif