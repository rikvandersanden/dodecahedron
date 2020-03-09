#include "Arduino.h"
#include "Dodecahedron.h"

// constructor
Dodecahedron::Dodecahedron()
{

}

int Dodecahedron::getStartVertex(int edge)
{
    if (edge < VERTICES)
        return edge;
    if (edge == VERTICES)
        return 0;
    int index = edge - VERTICES - 1;
    int previousEndVertex = _TerminalVertices[index];
    return previousEndVertex + _startVertexOffset(index);
}

int Dodecahedron::getEndVertex(int edge)
{
    if (edge < VERTICES)
        return (edge + 1) % VERTICES;
    return _TerminalVertices[edge - VERTICES];
}

int Dodecahedron::getHamiltonianEdge(int vertex)
{
    return invert((vertex + (VERTICES - 1)) % VERTICES);
}

int Dodecahedron::getNonHamiltonianEdge(int vertex)
{
    // find non-Hamiltonian edge which starts or ends at given vertex
    for (int i = VERTICES; i < EDGES; i++)
    {
        if (getStartVertex(i) == vertex)
            return i; // should go forward
        if (getEndVertex(i) == vertex)
            return invert(i); // should go backwards
    }
    // this should never happen
    return 0;
}

int Dodecahedron::invert(int edge) {
    return -edge - 1;
}

int Dodecahedron::_startVertexOffset(int shift)
{
    if ((_START_VERTEX_BITMASK & 1 << shift) == 0)
        return 1;
    return -1;
}