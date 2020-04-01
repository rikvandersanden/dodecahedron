//include "Arduino.h"
#include <cstdint>
#include "Dodecahedron.h"
#include "Edge.h"
#include "Vertex.h"

const uint8_t Edge::_startVertices[] = { 0, 3, 8,14, 9, 1,12,18, 6,17};
const uint8_t Edge::_endVertices[]   = { 4, 7,15,10, 2,11,19, 5,16,13};

uint8_t Edge::getStartVertex()
{
    if (_edge < VERTICES)
        return _edge;
    
    return _startVertices[_edge - VERTICES];
}

uint8_t Edge::getEndVertex()
{
    if (_edge < VERTICES)
        return (_edge + 1) % VERTICES;

    return _endVertices[_edge - VERTICES];
}

