#include "Dodecahedron.h"
#include "EdgeIterator.h"
#include "Edge.h"

EdgeIteratorBase *EdgeIteratorBase::getHamiltonianIterator(uint8_t vertex)
{
  return new EdgeIteratorBackward((vertex + (VERTICES - 1)) % VERTICES);
}

EdgeIteratorBase *EdgeIteratorBase::getNonHamiltonianIterator(uint8_t vertex)
{
  for (uint8_t i = VERTICES; i < EDGES; i++)
  {
    Edge edge(i);
    if (edge.getStartVertex() == vertex)
        return new EdgeIteratorForward(i);
    if (edge.getEndVertex() == vertex)
        return new EdgeIteratorBackward(i);
  }
  // this should never happen
  return 0;   
}