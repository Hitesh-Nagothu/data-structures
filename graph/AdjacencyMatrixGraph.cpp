#include "AdjacencyMatrixGraph.h"

void AdjacencyMatrixGraph::addNode(int id, bool isRoot) {

    if(id < 0 || id >= maxNodes) {
        throw out_of_range("Node ID out of range");
    }
    if(adjacencyMatrix.empty()) {
        adjacencyMatrix.resize(maxNodes, vector<int>(maxNodes, 0));
    }

    auto existing_node = nodes.find(id);
    if(existing_node != nodes.end() && existing_node->second.isRoot != isRoot) {
        throw logic_error("Node " + to_string(id) + " already exists with different root status");
    }
    nodes.insert({id, Node(id, isRoot)});
}

void AdjacencyMatrixGraph::addEdge(int from, int to, int weight) {
    
    if(from < 0 || from >= maxNodes || to < 0 || to >= maxNodes) {
        throw out_of_range("Node ID out of range");
    }

    auto from_node = nodes.find(from);
    auto to_node = nodes.find(to);

    if(from_node == nodes.end()) {
        throw logic_error("Node " + to_string(from) + " does not exist");
    }

    if(to_node == nodes.end()) {
        throw logic_error("Node " + to_string(to) + " does not exist");
    }

    if(to_node->second.isRoot || (graphType == GraphType::UNDIRECTED && from_node->second.isRoot)) {
        throw logic_error("Cannot add an incoming edge to root");
    }

    if(graphType == GraphType::UNDIRECTED) {
        // add the reverse edge
        adjacencyMatrix[to][from] = weight;
    }

    adjacencyMatrix[from][to] = weight;
}

void AdjacencyMatrixGraph::printGraph() {
    for(int i = 0; i < maxNodes; ++i) {
        cout << "Node " << i << "->";
        for(int j = 0; j < maxNodes; ++j) {
            if(adjacencyMatrix[i][j] != 0) {
                cout << "(" << j << ", w=" << adjacencyMatrix[i][j] << ") ";
            }
        }
        cout << "\n";
    }
}

unordered_map<int, vector<int>> AdjacencyMatrixGraph::depthFirstTraversal() {

    unordered_map<int, vector<int>> result;
    unordered_set<int> visited; 

    for(const auto& [id, node]: nodes) {
        if(node.isRoot && visited.count(id)==0){
            stack<int> to_visit;
            to_visit.push(id);
            visited.insert(id);

            result[id] = vector<int>();
            result[id].push_back(id);

            while(!to_visit.empty()){
                int current = to_visit.top(); 
                to_visit.pop();

                for(int j = 0; j < maxNodes; ++j) {
                    if(adjacencyMatrix[current][j] != 0 && visited.count(j) == 0) {
                        to_visit.push(j);
                        visited.insert(j);
                        result[id].push_back(j);
                    }
                }
            }
        }
    }

    return result;
}

unordered_map<int, vector<int>> AdjacencyMatrixGraph::breadthFirstTraversal(){

    unordered_map<int, vector<int>> result;
    queue<int> q;

    for (const auto& [id, node] : nodes) {
        if (node.isRoot) {
            unordered_set<int> localVisited;
            queue<int> q;
            q.push(id);
            localVisited.insert(id);
            result[id] = vector<int>();
    
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                result[id].push_back(current);
    
                for (int j = 0; j < maxNodes; ++j) {
                    if (adjacencyMatrix[current][j] != 0 && localVisited.count(j) == 0) {
                        q.push(j);
                        localVisited.insert(j);
                    }
                }
            }
        }
    }
    
    return result;
}
