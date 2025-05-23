#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H

#include "IGraph.h"
#include "graph_type.h"
#include "node.h"
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

class AdjacencyListGraph : public IGraph {

    private:
        unordered_map<int, Node> nodes;
        unordered_map<int, vector<pair<int, int>>> connections;
        const GraphType graphType;

    public:

        explicit AdjacencyListGraph(GraphType type): graphType(type) {}

        void addNode(int id, bool isRoot) override;
        void addEdge(int from, int to, int weight) override;
        void printGraph() override;

        unordered_map<int, vector<int>> depthFirstTraversal() override;
        unordered_map<int, vector<int>> breadthFirstTraversal() override;
};


#endif