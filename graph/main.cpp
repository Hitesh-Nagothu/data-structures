#include "AdjacencyListGraph.h"
#include "AdjacencyMatrixGraph.h"
#include "GraphType.h"
#include <iostream>

using namespace std;

int main() {
   // TODO Use dependency injection to choose between AdjacencyListGraph and AdjacencyMatrixGraph
   // AdjacencyListGraph graph(GraphType::DIRECTED);
   AdjacencyMatrixGraph graph(GraphType::DIRECTED);

    graph.addNode(1, true);
    graph.addNode(2, false);
    graph.addNode(3, false);
    graph.addNode(4, false);
    graph.addNode(5, true);
    graph.addNode(6, false);

    /*
    Bread First Traversal
    Input:
            1    5
           / \  /
          2---3
         /     \
        4       6

    Output: 
        Root 1: 1 -> 2 -> 3 -> 4 -> 6
        Root 5: 5 -> 3 -> 6
    */
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 4, 1);
    graph.addEdge(2, 3, 1);
    graph.addEdge(5, 3, 1);
    graph.addEdge(3, 6, 1);

    auto traversal = graph.breadthFirstTraversal();
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
