#include <iostream>
#include "imports/Tree.h"
using namespace std;

bool checkTree(TreeNode<int>* node1, TreeNode<int>* node2) {
    if (!node1 && !node2) {
        return true;
    } else if ((!node1 || !node2) || node1->data != node2->data) {
        return false;
    }
    return checkTree(node1->left, node2->left) && checkTree(node1->right, node2->right);
}

bool findPreorder(TreeNode<int>* node1, TreeNode<int>* node2) {
    if (!node1) {
        return false;
    }

    if (node1->data == node2->data && checkTree(node1, node2)) {
        return true;
    }
    return findPreorder(node1->left, node2) || findPreorder(node1->right, node2);
}

bool checkSubtree (TreeNode<int>* node1, TreeNode<int>* node2) {
    return findPreorder(node1, node2);
}

int main() {
    TreeNode<int>* root = new TreeNode<int> (20);
    root->left = new TreeNode<int> (10);
    root->left->left = new TreeNode<int> (4);
    root->left->right = new TreeNode<int> (18);
    root->left->left->right = new TreeNode<int> (6);
    root->right = new TreeNode<int> (26);
    root->right->right = new TreeNode<int> (40);
    root->right->right->left = new TreeNode<int> (32);
    root->right->right->left->left = new TreeNode<int> (30);
    root->right->right->left->right = new TreeNode<int> (36);

    TreeNode<int>* subtree = new TreeNode<int> (40);
    subtree->left = new TreeNode<int> (32);
    subtree->left->left = new TreeNode<int> (30);
    // subtree->left->right = new TreeNode<int> (36);

    if (checkSubtree(root, subtree)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}