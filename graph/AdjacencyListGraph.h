#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H

#include "IGraph.h"
#include "GraphType.h"
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

struct Node {
    int id;
    bool isRoot;
    Node(int id, bool isRoot): id(id), isRoot(isRoot){}
};

class AdjacencyListGraph : public IGraph {

    private:
        unordered_map<int, Node> nodes;
        unordered_map<int, vector<pair<int, int>>> connections;
        GraphType graphType;

    public:

        explicit AdjacencyListGraph(GraphType type): graphType(type) {}

        void addNode(int id, bool isRoot) override;
        void addEdge(int from, int to, int weight) override;
        void printGraph() const override;

        unordered_map<int, vector<int>> depthFirstTraversal() override;
       // unordered_map<int, vector<int>> breadthFirstTravelsal() override;
};


#endif