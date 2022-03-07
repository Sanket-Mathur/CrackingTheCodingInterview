#include<iostream>
using namespace std;

class Tree {
public:
    int data;
    Tree* left;
    Tree* right;
    Tree* parent;

    Tree(int data, Tree* parent) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->parent = parent;
    }
};

Tree* findSuccessor(Tree* node) {
    if (node->right) {
        return node->right;
    }

    Tree* parent = node->parent;
    while (parent != NULL) {
        if (node == parent->left) {
            return parent;
        } else {
            node = parent;
            parent = node->parent;
        }
    }

    return node->right;
}

int main() {
    Tree* root = new Tree(20, NULL);
    root->left = new Tree(10, root);
    root->left->left = new Tree(4, root->left);
    root->left->right = new Tree(18, root->left);
    root->left->left->right = new Tree(6, root->left->left);
    root->right = new Tree(26, root);
    root->right->right = new Tree(40, root->right);
    root->right->right->left = new Tree(32, root->right->right);
    root->right->right->left->left = new Tree(30, root->right->right->left);
    root->right->right->left->right = new Tree(36, root->right->right->left);

    Tree* successor = findSuccessor(root->right->right->left->right);
    if (successor) {
        cout << successor->data << endl;
    } else {
        cout << "NULL" << endl;
    }

    return 0;
}