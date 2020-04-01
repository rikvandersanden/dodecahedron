#include <cstdint>

#ifndef Edge_h
#define Edge_h

class Edge
{
  public:
    Edge(int8_t edge) 
    {
      _edge = edge;
    }
    uint8_t getStartVertex();
    uint8_t getEndVertex();
  private:
    int8_t _edge;
    const static uint8_t _endVertices[];
    const static uint8_t _startVertices[];
};

#endif