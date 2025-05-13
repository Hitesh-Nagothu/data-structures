#ifndef NODE_H
#define NODE_H

struct Node {
    int id;
    bool isRoot;

    Node(int id, bool isRoot) : id(id), isRoot(isRoot) {}
};


#endif