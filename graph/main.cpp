#include "AdjacencyListGraph.h"
#include "GraphType.h"
#include <iostream>

using namespace std;

int main() {
    AdjacencyListGraph graph(GraphType::DIRECTED);

    graph.addNode(1, true);
    graph.addNode(2, false);
    graph.addNode(3, false);

    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 1);

    auto traversal = graph.depthFirstTraversal();
    for(const auto& [node, path] : traversal) {
        cout << "Node " << node << ": ";
        for (int id : path) {
            cout << id << " ";
        }
        cout << endl;
    }
}
