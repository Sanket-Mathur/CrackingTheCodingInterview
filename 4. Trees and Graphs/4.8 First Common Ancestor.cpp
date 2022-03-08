#include <iostream>
#include "imports/Tree.h"
using namespace std;

bool covers(TreeNode<int> *root, TreeNode<int>* node) {
    if (!root) {
        return NULL;
    } else if (root == node) {
        return true;
    }

    return covers(root->left, node) || covers(root->right, node);
}

TreeNode<int>* ancestorHelper(TreeNode<int> *root, TreeNode<int>* a, TreeNode<int>* b) {
    if (!root) {
        return NULL;
    } else if (root == a || root == b) {
        return root;
    }

    bool aOnLeft = covers(root->left, a);
    bool bOnLeft = covers(root->left, b);

    if (aOnLeft != bOnLeft) {
        return root;
    }

    TreeNode<int>* child = aOnLeft ? root->left : root->right;
    return ancestorHelper(child, a, b);
}

TreeNode<int>* firstCommonAncestor(TreeNode<int> *root, TreeNode<int>* a, TreeNode<int>* b) {
    if (!root) {
        return NULL;
    } else if (!covers(root, a) || !covers(root, b)) {
        return NULL;
    }

    return ancestorHelper(root, a, b);
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

    TreeNode<int>* anc = firstCommonAncestor(root, root->left->right, root->left->left->right);
    if (anc) {
        cout << anc->data << endl;
    } else {
        cout << "Not possible" << endl;
    }

    return 0;
}