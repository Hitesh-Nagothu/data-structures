#include "adjacency_list.h"
#include<iostream>
#include<stdexcept>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;

void AdjacencyListGraph::addNode(int id, bool isRoot=false){

    auto existing_node = nodes.find(id);
    if(existing_node != nodes.end() && existing_node->second.isRoot != isRoot){
        throw logic_error("Node " + to_string(id) + " already exists with different root status");
    }

    nodes.insert({id, Node(id, isRoot)});
}

void AdjacencyListGraph::addEdge(int from, int to, int weight=1){

    auto from_node = nodes.find(from);
    auto to_node = nodes.find(to);

    if(from_node == nodes.end()){
        throw logic_error("Node " + to_string(from) + " does not exist");
    }

    if(to_node == nodes.end()){
        throw logic_error("Node " + to_string(to) + " does not exist");
    }

    if(to_node->second.isRoot || (graphType == GraphType::UNDIRECTED && from_node->second.isRoot)){
        throw logic_error("Cannot add an incoming edge to root");
    }

    if(graphType == GraphType::UNDIRECTED){
        // add the reverse edge
        auto reverse_connection = make_pair(from, weight);
        connections[to].emplace_back(reverse_connection);
    }

    pair<int, int> connection(to, weight);
    connections[from].emplace_back(connection);
}

void AdjacencyListGraph::printGraph() {

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
                visited.insert(current);
            }

        }
    }

    return result;
}

unordered_map<int, vector<int>> AdjacencyListGraph::breadthFirstTraversal() {

    unordered_map<int, vector<int>> result;
    queue<int> q;

    // push all the roots to the queue
    for(const auto& [id, node]: nodes){
        if(node.isRoot){

            // maintain a set per root, and not global
            unordered_set<int> localVisited;

            q.push(id);
            localVisited.insert(id);

            result[id]= vector<int>();

            while(!q.empty()){

                int current_node = q.front();
                q.pop();

                result[id].push_back(current_node);
        
                for(const auto& [next_node, weight]:connections[current_node]){
                    q.push(next_node);
                    localVisited.insert(next_node);
                }
        
            }
    
        }
    }

    return result;
}