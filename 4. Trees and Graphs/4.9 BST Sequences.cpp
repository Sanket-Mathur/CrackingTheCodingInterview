#include <iostream>
#include <vector>
#include "imports/Tree.h"
using namespace std;

vector<vector<int>> weave(vector<int> seq1, vector<int> seq2, vector<int> prefix) {
    vector<vector<int>> result;

    if (seq1.size() == 0) {
        prefix.insert(prefix.end(), seq2.begin(), seq2.end());
        result.push_back(prefix);
    } else if (seq2.size() == 0) {
        prefix.insert(prefix.end(), seq1.begin(), seq1.end());
        result.push_back(prefix);
    } else {
        prefix.push_back(*seq1.begin());
        vector<vector<int>> seq1Weaves = weave(vector<int> (seq1.begin() + 1, seq1.end()), seq2, prefix);
        prefix.pop_back();
        prefix.push_back(*seq2.begin());
        vector<vector<int>> seq2Weaves = weave(seq1, vector<int> (seq2.begin() + 1, seq2.end()), prefix);
        prefix.pop_back();

        result.insert(result.end(), seq1Weaves.begin(), seq1Weaves.end());
        result.insert(result.end(), seq2Weaves.begin(), seq2Weaves.end());
    }

    return result;
}

vector<vector<int>> bstSequences(TreeNode<int>* root) {
    if (!root) {
        return vector<vector<int>> ();
    }

    vector<vector<int>> leftSeq = bstSequences(root->left);
    vector<vector<int>> rightSeq = bstSequences(root->right);

    vector<vector<int>> result;
    vector<int> prefix = {root->data};
    
    if (leftSeq.size() == 0 && rightSeq.size() == 0) {
        result.push_back(prefix);
        return result;
    }

    for (vector<int> left : leftSeq) {
        for (vector<int> right : rightSeq) {
            vector<vector<int>> res = weave(left, right, prefix);
            result.insert(result.end(), res.begin(), res.end());
        }
    }

    if (result.size() == 0) {
        for (vector<int> left : leftSeq) {
            vector<vector<int>> res = weave(left, vector<int> (), prefix);
            result.insert(result.end(), res.begin(), res.end());
        }
        for (vector<int> right : rightSeq) {
            vector<vector<int>> res = weave(vector<int> (), right, prefix);
            result.insert(result.end(), res.begin(), res.end());
        }
    }
    
    return result;
}

int main() {
    TreeNode<int>* root = new TreeNode<int> (2);
    root->left = new TreeNode<int> (1);
    root->right = new TreeNode<int> (3);

    vector<vector<int>> result = bstSequences(root);

    for (vector<int> seq : result) {
        for (int item : seq) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}