#include <iostream>
#include <time.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    static int nodeCount;

    Node(int data) {
        this->data = data;
        left =  NULL;
        right = NULL;
        nodeCount++;
    }
    ~Node() {
        nodeCount--;
    }
};
int Node::nodeCount;

Node* getRandomNode(Node* root, int &size) {
    if (!root) {
        return NULL;
    }

    Node* left = getRandomNode(root->left, size);
    if (left) {
        return left;
    }

    if (rand() % size-- == 0) {
        return root;
    }

    Node* right = getRandomNode(root->right, size);
    return right;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->left->left = new Node(4);
    root->left->right = new Node(18);
    root->left->left->right = new Node(6);
    root->right = new Node(26);
    root->right->right = new Node(40);
    root->right->right->left = new Node(32);
    root->right->right->left->left = new Node(30);
    root->right->right->left->right = new Node(36);

    srand(time(NULL));

    int size = root->nodeCount;
    Node* node = getRandomNode(root, size);

    cout << node->data << endl;

    return 0;
}