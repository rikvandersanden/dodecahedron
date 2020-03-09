#include "Arduino.h"

#ifndef Dodecahedron_h
#define Dodecahedron_h

static const int EDGES = 30;
static const int VERTICES = 20;
static const int LEDS_PER_EDGE = 7;
static const int _TerminalVertices[10] = {4, 7, 15, 10, 2, 11, 19, 5, 16, 13};
static const byte _START_VERTEX_BITMASK = 93;

class Dodecahedron
{
  public:
    Dodecahedron();
    int getStartVertex(int edge);
    int getEndVertex(int edge);
    int invert(int edge);
    int getHamiltonianEdge(int vertex);
    int getNonHamiltonianEdge(int vertex);
  private:
    int _startVertexOffset(int shift);
};

// class Edge
// {
//   public:
//     Edge(int startVertex, int endVertex);
//     int startVertex();
//     int endVertex();
//     int firstLed();
//     int lastLed();
//   private:
//     int _startVertex;
//     int _endVErtex;
// };

// class Vertex
// {
//   public:
//     Vertex(int )
// }

#endif