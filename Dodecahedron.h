#include "Arduino.h"

#ifndef Dodecahedron_h
#define Dodecahedron_h

static const uint8_t EDGES = 30;
static const uint8_t VERTICES = 20;
static const uint8_t LEDS_PER_EDGE = 7;
static const uint8_t _TerminalVertices[10] = {4, 7, 15, 10, 2, 11, 19, 5, 16, 13};
static const byte _START_VERTEX_BITMASK = 93;

// find a way to encode angles for LEDS for creating rotating patterns.

class Dodecahedron
{
  public:
    static uint8_t getStartVertex(uint8_t edge);
    static uint8_t getEndVertex(uint8_t edge);
  private:
    static uint8_t _startVertexOffset(uint8_t shift);
};

class Vertex
{
  public:
    Vertex(uint8_t vertex)
    {
      _vertex = vertex;
    }
    uint8_t defaultEdge()
    {
      return _vertex;
    }
    uint8_t hamiltonianEdge()
    {
      return (_vertex + (VERTICES - 1)) % VERTICES;
    }
    uint8_t nonHamiltonianEdge()
    {
      // how to communicate direction?
      for (uint8_t i = VERTICES; i < EDGES; i++)
      {
        if (Dodecahedron::getStartVertex(i) == _vertex)
            return i;
        if (Dodecahedron::getEndVertex(i) == _vertex)
            return i;
      }
      // this should never happen
      return 0;
    }
  private:
    uint8_t _vertex;
};

class Edge
{
  public:
    Edge(uint8_t edge) 
    {
      _edge = edge;
    }
    uint8_t startVertex()
    {
      return Dodecahedron::getStartVertex(_edge);
    }
    uint8_t endVertex()
    {
      return Dodecahedron::getEndVertex(_edge);
    }
  private:
    uint8_t _edge;
};

#endif