#include <iostream>
#include <vector>
#include <stack>
#include "imports/Graph.h"
using namespace std;

void topoligicalUtil(Graph<int> s, int V, vector<bool> &visited, stack<int> &stack, int curr) {
    for (int i = 0; i < s.graph[curr].neighbors.size(); ++i) {
        if (!visited[s.graph[curr].neighbors[i]->data]) {
            visited[s.graph[curr].neighbors[i]->data] = true;
            topoligicalUtil(s, V, visited, stack, s.graph[curr].neighbors[i]->data);
        }
    }
    stack.push(s.graph[curr].data);
}

void buildOrder(Graph<int> s, int V) {
    vector<bool> visited(V, false);
    stack<int> stack;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            visited[s.graph[i].data] = true;
            topoligicalUtil(s, V, visited, stack, i);
        }
    }

    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}

int main() {
    Graph<int> s(10);
    for (int i = 0; i < 10; ++i) {
        s.graph[i].data = i;
    }

    s.graph[0].neighbors.push_back(&s.graph[1]);
    s.graph[0].neighbors.push_back(&s.graph[2]);
    s.graph[1].neighbors.push_back(&s.graph[2]);
    s.graph[1].neighbors.push_back(&s.graph[4]);
    s.graph[2].neighbors.push_back(&s.graph[3]);
    s.graph[4].neighbors.push_back(&s.graph[5]);
    s.graph[4].neighbors.push_back(&s.graph[6]);
    s.graph[5].neighbors.push_back(&s.graph[6]);
    s.graph[7].neighbors.push_back(&s.graph[8]);
    s.graph[8].neighbors.push_back(&s.graph[9]);

    buildOrder(s, 10);

    return 0;
}