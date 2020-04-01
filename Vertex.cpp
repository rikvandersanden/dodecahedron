//#include "Arduino.h"
#include <cstdint>
#include "Dodecahedron.h"
#include "Edge.h"
#include "Vertex.h"

int8_t Vertex::defaultEdge()
{
    return _vertex;
}
int8_t Vertex::hamiltonianEdge()
{
    return (_vertex + (VERTICES - 1)) % VERTICES;
}
int8_t Vertex::nonHamiltonianEdge()
{
    for (int8_t i = VERTICES; i < EDGES; i++)
    {
        Edge edge(i);
        if (edge.startVertex() == _vertex)
            return i;
        if (edge.endVertex() == _vertex)
            return i;
    }
    // this should never happen
    return 0;
}