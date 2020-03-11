#include "Arduino.h"
#include "Dodecahedron.h"
#include "Edgeiterator.h"

EdgeIteratorBase *EdgeIteratorBase::getHamiltonianIterator(uint8_t vertex)
{
  return new EdgeIteratorBackward((vertex + (VERTICES - 1)) % VERTICES);
}

EdgeIteratorBase *EdgeIteratorBase::getNonHamiltonianIterator(uint8_t vertex)
{
  for (uint8_t i = VERTICES; i < EDGES; i++)
  {
    if (Dodecahedron::getStartVertex(i) == vertex)
        return new EdgeIteratorForward(i);
    if (Dodecahedron::getEndVertex(i) == vertex)
        return new EdgeIteratorBackward(i);
  }
  // this should never happen
  return 0;   
}