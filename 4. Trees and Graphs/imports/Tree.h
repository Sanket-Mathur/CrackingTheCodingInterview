#ifndef TREE_IMPORT
#define TREE_IMPORT

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
};

#endif