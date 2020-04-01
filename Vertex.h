//#include "Arduino.h"
#include <cstdint>

#ifndef Vertex_h
#define Vertex_h

class Vertex
{
  public:
    Vertex(uint8_t vertex)
    {
      _vertex = vertex;
    }
    int8_t defaultEdge();
    int8_t hamiltonianEdge();
    int8_t nonHamiltonianEdge();
  private:
    uint8_t _vertex;
};

#endif