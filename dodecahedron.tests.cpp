#ifndef ARDUINO

#include <iostream>
#include <vector>
#include <string>
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

void testBleeder()
{
    Bleeder sut(new EdgeIteratorForward(0));
    while(sut.moveNext())
    {
        EdgeIteratorBase** iterators = sut.getIterators();
        for(int i = 0; i < sut.count(); i++)
        {
            std::cout << int(iterators[i]->getEdge()) << " ";
        }
        std::cout << std::endl;
    }
}

uint32_t   Color(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
  }

uint32_t   Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
    return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

void testColors()
{
    uint32_t colors[3] = {
        Color(255,  0,  0),
        Color(  0,255,  0),
        Color(  0,  0,255),
    };
    uint32_t blue = Color(0,0,255);

    for(int i = 0; i < 3; i++)
    {
        uint32_t hasBlue = colors[i] & blue;
        uint32_t newColor = 0;
        if (hasBlue == 0)
        {
            newColor = colors[i] | blue;
        }
        else
        {
            newColor = colors[i] & ~blue;
        }
        std::cout << newColor << " ";
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

int main()
{
    testScan();
}
#endif