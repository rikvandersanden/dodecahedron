#include <iostream>
#include <vector>
#include <string>
#include "assert.h"

#include "Edge.h"
#include "EdgeIterator.h"
#include "Vertex.h"

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

int main()
{
    // vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    
    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;

    testIterators();
}