#include <iostream>
#include "imports/Tree.h"
using namespace std;

TreeNode<int>* buildTree(int arr[], int low, int high) {
    if (low > high) {
        return NULL;
    }

    int mid = low + (high - low) / 2;
    TreeNode<int>* node = new TreeNode<int>(arr[mid]);

    node->left = buildTree(arr, low, mid - 1);
    node->right = buildTree(arr, mid + 1, high);

    return node;
}

void printPreorder(TreeNode<int>* node) {
    if (!node) {
        return;
    }

    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    TreeNode<int>* root = buildTree(arr, 0, 6);

    printPreorder(root);
    cout << endl;

    return 0;
}