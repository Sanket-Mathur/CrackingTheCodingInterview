#include <iostream>
#include "imports/Tree.h"
using namespace std;

void checkBalanced(TreeNode<int> *node, int &minD, int &maxD, int depth = 0) {
    if (!node) {
        return;
    } else if (!node->left && !node->right) {
        if (depth < minD) {
            minD = depth;
        } 
        if (depth > maxD) {
            maxD = depth;
        }
    } else {
        checkBalanced(node->left, minD, maxD, depth + 1);
        checkBalanced(node->right, minD, maxD, depth + 1);
    }
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
    // root->right->right->left->left = new TreeNode<int> (73);
    // root->right->right->left->right = new TreeNode<int> (1);

    int minD = INT32_MAX, maxD = INT32_MIN;
    checkBalanced(root, minD, maxD);

    if (maxD - minD > 1) {
        cout << "Not Balanced" << endl;
    } else {
        cout << "Balanced" << endl;
    }

    return 0;
}