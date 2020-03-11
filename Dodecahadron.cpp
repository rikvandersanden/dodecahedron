#include "Arduino.h"
#include "Dodecahedron.h"

// constructor
// Dodecahedron::Dodecahedron()
// {

// }

uint8_t Dodecahedron::getStartVertex(uint8_t edge)
{
    if (edge < VERTICES)
        return edge;
    if (edge == VERTICES)
        return 0;
    int index = edge - VERTICES - 1;
    int previousEndVertex = _TerminalVertices[index];
    return previousEndVertex + _startVertexOffset(index);
}

uint8_t Dodecahedron::getEndVertex(uint8_t edge)
{
    if (edge < VERTICES)
        return (edge + 1) % VERTICES;
    return _TerminalVertices[edge - VERTICES];
}

uint8_t Dodecahedron::_startVertexOffset(uint8_t shift)
{
    if ((_START_VERTEX_BITMASK & 1 << shift) == 0)
        return 1;
    return -1;
}