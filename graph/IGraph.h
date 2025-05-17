#ifndef IGRAPH_H
#define IGRAPH_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class IGraph {
public:
    virtual void addNode(int id, bool isRoot = false) = 0;
    virtual void addEdge(int from, int to, int weight = 1) = 0;
    virtual void printGraph() = 0;

    virtual unordered_map<int, vector<int>> depthFirstTraversal() = 0;
    virtual unordered_map<int, vector<int>> breadthFirstTraversal() = 0;

    virtual ~IGraph() = default;
};

#endif

