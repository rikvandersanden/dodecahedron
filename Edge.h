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
    uint8_t startVertex();
    uint8_t endVertex();
  private:
    int8_t _edge;
    uint8_t _startVertexOffset(uint8_t shift);
    const static uint8_t _TerminalVertices[];
    const static uint8_t _START_VERTEX_BITMASK;
};

#endif