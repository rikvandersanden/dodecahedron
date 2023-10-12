#ifdef ARDUINO
  #include "Arduino.h"
#else
  #include <cstdint>
#endif

#include "Dodecahedron.h"
#include "Edge.h"
#include "Vertex.h"

const int16_t Vertex::COORDINATES[] = {
0, 0, -32767, 
-21845, 0, -24423, 
-24423, 18918, -10922, 
-4172, 30610, -10922, 
10922, 18918, -24423, 
28595, 11692, -10922, 
24423, 18918, 10922, 
4172, 30610, 10922, 
-10922, 18918, 24423, 
-28595, 11692, 10922, 
-28595, -11692, 10922, 
-24423, -18918, -10922, 
-4172, -30610, -10922, 
4172, -30610, 10922, 
-10922, -18918, 24423, 
0, 0, 32767, 
21845, 0, 24423, 
24423, -18918, 10922, 
28595, -11692, -10922, 
10922, -18918, -24423};

int16_t Vertex::getX()
{
    return Vertex::COORDINATES[_vertex * 3];
}

int16_t Vertex::getY()
{
    return Vertex::COORDINATES[(_vertex * 3) + 1];
}

int16_t Vertex::getZ()
{
    return Vertex::COORDINATES[(_vertex * 3) + 2];
}

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