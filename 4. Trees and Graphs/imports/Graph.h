#ifndef GRAPH_IMPORT
#define GRAPH_IMPORT
#include <vector>

template <typename T>
class Node {
public:
    T data;
    bool visited;
    std::vector<Node*> neighbors;

    Node() {
        this->data = T();
        this->visited = false;
    }
    Node(T data) {
        this->data = data;
        this->visited = false;
    }
};

template <typename T>
class Graph {
public:
    Node<T>* graph;

    Graph(int n) {
        graph = new Node<T>[n];
    }
};

#endif