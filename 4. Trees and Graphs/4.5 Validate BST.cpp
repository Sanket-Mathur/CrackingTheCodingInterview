#include <iostream>
#include "imports/Tree.h"
using namespace std;

bool checkBST(TreeNode<int> *root, int minVal = INT32_MIN, int maxVal = INT32_MAX) {
    if (!root) {
        return true;
    } else if (root->data < minVal || root->data > maxVal) {
        return false;
    }

    return checkBST(root->left, minVal, root->data) && checkBST(root->right, root->data, maxVal);
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

    if (checkBST(root)) {
        cout << "Valid BST" << endl;
    } else {
        cout << "Invalid BST" << endl;
    }

    return 0;
}