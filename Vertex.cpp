#ifdef ARDUINO
  #include "Arduino.h"
#else
  #include <cstdint>
#endif

#include "Dodecahedron.h"
#include "Edge.h"
#include "Vertex.h"

int8_t Vertex::getDefaultEdge()
{
    return _vertex;
}
int8_t Vertex::getHamiltonianEdge()
{
    return (_vertex + (VERTICES - 1)) % VERTICES;
}
int8_t Vertex::getNonHamiltonianEdge()
{
    for (int8_t i = VERTICES; i < EDGES; i++)
    {
        Edge edge(i);
        if (edge.getStartVertex() == _vertex)
            return i;
        if (edge.getEndVertex() == _vertex)
            return i;
    }
    // this should never happen
    return 0;
}