#include "AdjacencyListGraph.h"
#include "GraphType.h"
#include <iostream>

using namespace std;

int main() {
    AdjacencyListGraph graph(GraphType::DIRECTED);

    graph.addNode(1, true);
    graph.addNode(2, false);
    graph.addNode(3, false);
    graph.addNode(4, false);

    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 1);

    auto traversal = graph.depthFirstTraversal();
    for(const auto& [node, path] : traversal) {
        cout << "Root " << node << ": ";
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) {
                cout << " -> ";
            }
        }        
        cout << endl;
    }
}
