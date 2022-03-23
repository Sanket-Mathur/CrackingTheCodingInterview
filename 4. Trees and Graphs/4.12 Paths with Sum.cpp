#include <iostream>
#include "imports/Tree.h"
using namespace std;

int helper(TreeNode<int>* node, int targetSum, int currentSum) {
    if (!node) {
        return 0;
    }

    currentSum += node->data;

    int paths = 0;
    if (currentSum == targetSum) {
        ++paths;
    }

    paths += helper(node->left, targetSum, currentSum);
    paths += helper(node->right, targetSum, currentSum);

    return paths;
}

int pathsWithSums(TreeNode<int>* node, int sum) {
    if (!node) {
        return 0;
    }

    int currCnt = helper(node, sum, 0);

    int leftCnt = pathsWithSums(node->left, sum);
    int rightCnt = pathsWithSums(node->right, sum);

    return currCnt + leftCnt + rightCnt;
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

    cout << pathsWithSums(root, 20) << endl;

    return 0;
}