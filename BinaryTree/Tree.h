#ifndef TREE_H_
#define TREE_H_
#define NULL_NODE_FLAG 0x7fffffff

#include <vector>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val), left(_left), right(_right) {}
};

std::pair<bool, TreeNode*> createTree(std::vector<int>& value);
std::pair<bool, TreeNode*> createTree(int value[], int size);

#endif