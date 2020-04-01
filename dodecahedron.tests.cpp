#include <iostream>
#include <vector>
#include <string>
#include "assert.h"

#include "Edge.h"
#include "Vertex.h"

void printVertices()
{
    std::cout << "Vertices:" << std::endl;
    for (int i = 0; i<20; i++)
    {
        Vertex v(i);
        std::cout << int(v.defaultEdge()) << " " << int(v.hamiltonianEdge()) << " " << int(v.nonHamiltonianEdge());
        std::cout << std::endl;
    }
}

void printEdges()
{
    std::cout << "Edges:" << std::endl;
    for (int i = 0; i<30; i++)
    {
        Edge e(i);
        std::cout << int(e.startVertex()) << " " << int(e.endVertex());
        std::cout << std::endl;
    }
}

int main()
{
    // vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    
    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;

    printEdges();
}