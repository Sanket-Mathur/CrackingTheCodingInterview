#include <iostream>
#include <queue>
#include <vector>
#include "imports/Graph.h"
using namespace std;

bool routeExists(Node<int> *node, Node<int> *dest) {
    if (node == NULL) {
        return false;
    }

    queue<Node<int>*> nodeQueue;
    vector<bool> visited(10, false);

    nodeQueue.push(node);
    node->visited = true;

    while (!nodeQueue.empty()) {
        Node<int> *front = nodeQueue.front();
        nodeQueue.pop();
        
        if (front == dest) {
            return true;
        }

        for (auto i : front->neighbors) {
            if (!i->visited) {
                nodeQueue.push(i);
                i->visited = true;
            }
        }
    }

    return false;
}

int main() {
    Graph<int> s(10);
    for (int i = 0; i < 10; ++i) {
        s.graph[i].data = i;
    }

    s.graph[0].neighbors.push_back(&s.graph[1]);
    s.graph[0].neighbors.push_back(&s.graph[2]);
    s.graph[1].neighbors.push_back(&s.graph[0]);
    s.graph[1].neighbors.push_back(&s.graph[2]);
    s.graph[1].neighbors.push_back(&s.graph[4]);
    s.graph[2].neighbors.push_back(&s.graph[0]);
    s.graph[2].neighbors.push_back(&s.graph[1]);
    s.graph[2].neighbors.push_back(&s.graph[3]);
    s.graph[3].neighbors.push_back(&s.graph[2]);
    s.graph[4].neighbors.push_back(&s.graph[1]);
    s.graph[4].neighbors.push_back(&s.graph[5]);
    s.graph[4].neighbors.push_back(&s.graph[6]);
    s.graph[5].neighbors.push_back(&s.graph[4]);
    s.graph[5].neighbors.push_back(&s.graph[6]);
    s.graph[6].neighbors.push_back(&s.graph[4]);
    s.graph[6].neighbors.push_back(&s.graph[5]);
    s.graph[7].neighbors.push_back(&s.graph[8]);
    s.graph[8].neighbors.push_back(&s.graph[7]);
    s.graph[8].neighbors.push_back(&s.graph[9]);
    s.graph[9].neighbors.push_back(&s.graph[8]);

    if (routeExists(&s.graph[3], &s.graph[5])) {
        cout << "Path Exists" << endl;
    } else {
        cout << "Path does not exists" << endl;
    }

    return 0;
}