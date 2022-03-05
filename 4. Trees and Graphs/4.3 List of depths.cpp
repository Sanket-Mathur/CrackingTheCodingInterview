#include <iostream>
#include <vector>
#include "imports/Tree.h"
using namespace std;

void listOfDepths(TreeNode<int> *node, vector<int> &list, int depth = 0) {
    if (!node) {
        return;
    } else if (!node->left && !node->right) {
        list.push_back(depth);
        return;
    }

    listOfDepths(node->left, list, depth + 1);
    listOfDepths(node->right, list, depth + 1);
}

int main() {
    TreeNode<int>* root = new TreeNode<int> (5);
    root->left = new TreeNode<int> (20);
    root->left->left = new TreeNode<int> (4);
    root->left->right = new TreeNode<int> (8);
    root->left->left->right = new TreeNode<int> (24);
    root->right = new TreeNode<int> (16);
    root->right->right = new TreeNode<int> (7);
    root->right->right->left = new TreeNode<int> (146);
    root->right->right->left->left = new TreeNode<int> (73);
    root->right->right->left->right = new TreeNode<int> (1);

    vector<int> list;
    listOfDepths(root, list);

    for (int i : list) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}