#ifndef ADJACENCY_LIST_GRAPH_H
#define ADJACENCY_LIST_GRAPH_H

#include "IGraph.h"
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

struct Node {
    int id;
    Node(int id) : id(id){}
};

class AdjacencyListGraph : public IGraph {

    private:
        unordered_map<int, Node> nodes;
        unordered_map<int, vector<pair<int, int>>> connections;

    public:
        void addNode(int id) override;
        void addEdge(int from, int to, int weight) override;
        void printGraph() const override;
};


#endif