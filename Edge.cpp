//include "Arduino.h"
#include <cstdint>
#include "Dodecahedron.h"
#include "Edge.h"
#include "Vertex.h"

const uint8_t Edge::_TerminalVertices[] = {4, 7, 15, 10, 2, 11, 19, 5, 16, 13};
const uint8_t Edge::_START_VERTEX_BITMASK = 93;

uint8_t Edge::startVertex()
{
    if (_edge < VERTICES)
        return _edge;
    if (_edge == VERTICES)
        return 0;
    
    int index = _edge - VERTICES - 1;
    int previousEndVertex = _TerminalVertices[index];
    return previousEndVertex + _startVertexOffset(index);
}

uint8_t Edge::endVertex()
{
    if (_edge < VERTICES)
        return (_edge + 1) % VERTICES;
    return _TerminalVertices[_edge - VERTICES];
}

uint8_t Edge::_startVertexOffset(uint8_t shift)
{
    if ((_START_VERTEX_BITMASK & 1 << shift) == 0)
        return 1;
    return -1;
}
