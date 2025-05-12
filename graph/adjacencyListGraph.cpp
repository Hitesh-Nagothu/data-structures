#include "AdjacencyListGraph.h"
#include<iostream>
#include<stdexcept>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;

void AdjacencyListGraph::addNode(int id, bool isRoot=false){

    auto existing_node = nodes.find(id);
    if(existing_node != nodes.end() && existing_node->second.isRoot != isRoot){
        throw logic_error("Node " + to_string(id) + " already exists with different root status");
    }

    nodes[id] = Node(id, isRoot);
}

void AdjacencyListGraph::addEdge(int from, int to, int weight=1){

    if(nodes.find(from) == nodes.end()){
        throw logic_error("Node " + to_string(from) + " does not exist");
    }

    if(nodes.find(to) == nodes.end()){
        throw logic_error("Node " + to_string(to) + " does not exist");
    }

    if(nodes[to].isRoot || (graphType == GraphType::DIRECTED && nodes[from].isRoot)){
        throw logic_error("Cannot add an incoming edge to root");
    }

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

unordered_map<int, vector<int>> AdjacencyListGraph::depthFirstTraversal(){
    
    unordered_map<int, vector<int>> result;
    unordered_set<int> visited;
    
    for(const auto& [id, node]: nodes){
        if(node.isRoot && visited.count(id)==0){
            // do the traversal for this root

            stack<int> to_visit;
            to_visit.push(id);

            // initialize the result set for this root node
            result[id] = {};

            while(!to_visit.empty()){
                int current = to_visit.top();
                to_visit.pop();

                // avoid duplicates (nodes stemmed from two roots) or a cycle
                if(visited.count(current)) continue;
                result[id].push_back(current);

                for(const auto& [next_node, weight] : connections[current]){
                    if(!visited.count(next_node)){
                        to_visit.push(next_node);
                    }
                }
            }

        }
    }

    return result;
}
