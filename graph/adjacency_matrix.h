#ifndef ADJACENCY_MATRIX_GRAPH_H
#define ADJACENCY_MATRIX_GRAPH_H

#include "IGraph.h"
#include "node.h"
#include "graph_type.h"
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <stack>


using namespace std;

class AdjacencyMatrixGraph : public IGraph {

    private: 
        unordered_map<int, Node> nodes;
        vector<vector<int>> adjacencyMatrix;
        const GraphType graphType;
        int nodeCount;
        // TODO: Try resizing the adjacency matrix dynamically
        int maxNodes = 100; 
    
    public:

        explicit AdjacencyMatrixGraph(GraphType type) : graphType(type) {}

        void addNode(int id, bool isRoot) override;
        void addEdge(int from, int to, int weight) override;
        void printGraph() override;

        unordered_map<int, vector<int>> depthFirstTraversal() override;
        unordered_map<int, vector<int>> breadthFirstTraversal() override;

};


#endif
