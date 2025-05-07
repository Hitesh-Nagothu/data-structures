#ifndef IGRAPH_H
#define IGRAPH_H

#include <string>

class IGraph {
public:
    virtual void addNode(int id) = 0;
    virtual void addEdge(int from, int to, int weight = 1) = 0;
    virtual void printGraph() const = 0;

    virtual ~IGraph() = default;
};

#endif

