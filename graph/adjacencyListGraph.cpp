#include "AdjacencyListGraph.h"
#include<iostream>
using namespace std;

void AdjacencyListGraph::addNode(int id){
    nodes[id] = Node(id);
}

void AdjacencyListGraph::addEdge(int from, int to, int weight=1){
    pair<int, int> connection(to, weight);
    connections[from].emplace_back(connection);
}

void AdjacencyListGraph::printGraph() const {

    for(const auto& [nodeId, neighbors] : connections) {
        cout << "Node " << nodeId << "->";
        for(const auto& [to, weight] : neighbors){
            cout << "(" << to << ", w=" << weight << ") ";
        }
        cout << "\n";
    }
}
