#ifndef ARDUINO

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include "assert.h"

#include "Edge.h"
#include "EdgeIterator.h"
#include "Vertex.h"
#include "Bleeder.h"
#include "Rotation.h"

void printVertices()
{
    std::cout << "Vertices:" << std::endl;
    for (int i = 0; i<20; i++)
    {
        Vertex v(i);
        std::cout << int(v.getDefaultEdge()) << " " << int(v.getHamiltonianEdge()) << " " << int(v.getNonHamiltonianEdge());
        std::cout << std::endl;
    }
}

void printEdges()
{
    std::cout << "Edges:" << std::endl;
    for (int i = 0; i<30; i++)
    {
        Edge e(i);
        std::cout << int(e.getStartVertex()) << " " << int(e.getEndVertex());
        std::cout << std::endl;
    }
}

void testIterators()
{
    const int numberOfCycles = 4;

    EdgeIteratorBase* iterators[1 << numberOfCycles] = { new EdgeIteratorForward(0) };
    for (int cycle = 0; cycle < numberOfCycles; cycle++)
    {
        int numberOfIterators = 1 << cycle;
        for (int i = 0; i < numberOfIterators; i++)
        {
            std::cout << int(iterators[i]->getEdge()) << " ";
        }
        std::cout << std::endl;

        int index = numberOfIterators;
        for (int i = 0; i < numberOfIterators; i++)
        {
            EdgeIteratorBase *previous = iterators[i];
            iterators[index] = previous->getNextA();
            index = (index+1) % (numberOfIterators*2);
            iterators[index] = previous->getNextB();
            index = (index+1) % (numberOfIterators*2);
            delete previous;
        }
    }
    for (int i = 0; i < (1 << numberOfCycles); i++)
    {
        std::cout << int(iterators[i]->getEdge()) << " ";
    }
    std::cout << std::endl;
}

void testBleeders()
{
  Bleeder bleeders[3] = {
    new EdgeIteratorForward(0),
    EdgeIteratorBase::getHamiltonianIterator(0),
    EdgeIteratorBase::getNonHamiltonianIterator(0)
  };

    bool iterationsRemaining = true;

  while(iterationsRemaining)
  {
    for (int b = 0; b < 3; b++)
    {
      iterationsRemaining = bleeders[b].moveNext() && iterationsRemaining;
    }
    // for each edge in each bleeder, light up the next led until the edges are full
    bool ledsRemaining = true;
   
    do
    {
      for (int b = 0; b < 3; b++)
      {
        for (int i = 0; i < bleeders[b].count(); i++)
        {
          if (bleeders[b].getIterators()[i]->moveNext())
          {
            std::cout << int(bleeders[b].getIterators()[i]->getCurrentLed()) << " ";
          }
          else
          {
              ledsRemaining = false;
          }
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    } while (ledsRemaining);
  }
}

void testScan()
{
  for(int i = 0; i < 65536; i+=256)
  {
    std::cout << "Angle: " << i;
    std::cout << std::endl;
    for(int l = 0; l < 210; l++)
    {
      int angleDifference = (1<<15) - abs(abs(ANGLES[l] - i) - (1<<15));
      int brightness = 255 - (angleDifference/4);
      if (brightness > 0)
      {
        std::cout << "LED: " << l << " Brightness: " << brightness << " ";
        std::cout << std::endl;
      }
    }
  }
}

void testAngleDifference()
{
    uint16_t angles[] = { 35000, 65000, 65535, 0, 255, 30000, 32767, 32768};
    uint16_t angle = 0;
    for (int i = 0; i < 8; i++)
    {
        int16_t diff = angle - angles[i];
        std::cout << typeid(diff).name() << ": " << diff;
        std::cout << std::endl;
    }
    int16_t x = -32768;
    int16_t brightness = abs(x);
    std::cout << "brightnes:" << brightness;
}

void testCoordinates()
{
    for(int e=0; e < EDGES; e++)
    {
        Edge edge(e);
        std::cout << "Edge #" << e << " from vertex " << (int)edge.getStartVertex() << " to " << (int)edge.getEndVertex();
        std::cout << std::endl;
        for(int led=0; led < LEDS_PER_EDGE; led++)
        {
            std::cout << "LED #" << led << ": " << edge.getX(led) << "," << edge.getY(led) << "," << edge.getZ(led);
            std::cout << std::endl;
            
            uint8_t saturation = abs(edge.getZ(led)) < 24000
              ? 255
              : 255 - (((uint16_t)abs(edge.getZ(led))) >> 5);
            std::cout << "Saturation: " <<  (int)(saturation);
            std::cout << std::endl;
        }
    }
}



int main()
{
    testCoordinates();
}
#endif