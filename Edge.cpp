#ifdef ARDUINO
  #include "Arduino.h"
#else
  #include <cstdint>
#endif

#include "Dodecahedron.h"
#include "Edge.h"
#include "Vertex.h"

const uint8_t Edge::_startVertices[] = { 0, 3, 8,14, 9, 1,12,18, 6,17};
const uint8_t Edge::_endVertices[]   = { 4, 7,15,10, 2,11,19, 5,16,13};

uint8_t Edge::getEdge()
{
    return _edge;
}

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

int16_t Edge::getX(uint8_t led)
{
    Vertex start(getStartVertex());
    Vertex end(getEndVertex());
    
    int32_t diff = end.getX() - start.getX();
    int16_t relative = (diff * (1 + led)) / 8;
    return start.getX() + relative;
}

int16_t Edge::getY(uint8_t led)
{
    Vertex start(getStartVertex());
    Vertex end(getEndVertex());
    
    int32_t diff = end.getY() - start.getY();
    int16_t relative = (diff * (1 + led)) / 8;
    return start.getY() + relative;
}

int16_t Edge::getZ(uint8_t led)
{
    Vertex start(getStartVertex());
    Vertex end(getEndVertex());
    
    int32_t diff = end.getZ() - start.getZ();
    int16_t relative = (diff * (1 + led)) / 8;
    return start.getZ() + relative;
}

