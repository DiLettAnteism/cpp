#include "Tree.h"
#include <vector>
#include <queue>
#include <utility>

std::pair<bool, TreeNode*> createTree(std::vector<int>& value) {
    int n = value.size();
    if (n <= 0) return {false, nullptr};

    if (value[0] == NULL_NODE_FLAG) {
        if (n > 1) {
            return {false, nullptr};
        } else {
            return {true, nullptr};
        }
    }

    std::queue<TreeNode*> qu;
    int index = 0;
    TreeNode* rootPtr = new TreeNode(value[index++]);
    qu.push(rootPtr);
    while (index < n) {
        int quSize = qu.size();
        if (quSize <= 0) return {false, nullptr};
        for (int i = 0; i < quSize && index < n; ++i) {
            TreeNode* curNodePtr = qu.front();
            qu.pop();

            if (value[index] == NULL_NODE_FLAG) {
                curNodePtr -> left = nullptr;
            } else {
                TreeNode* nodePtr = new TreeNode(value[index]);
                qu.push(nodePtr);
                curNodePtr -> left = nodePtr;
            }
            ++index;
            if (index >= n) break;
            if (value[index] == NULL_NODE_FLAG) {
                curNodePtr -> right = nullptr;
            } else {
                TreeNode* nodePtr = new TreeNode(value[index]);
                qu.push(nodePtr);
                curNodePtr -> right = nodePtr;
            }
            ++index;
        }
    }
    
    return {true, rootPtr};
}

std::pair<bool, TreeNode*> createTree(int value[], int size) {
    if (size <= 0) return {false, nullptr};

    if (value[0] == NULL_NODE_FLAG) {
        if (size > 1) {
            return {false, nullptr};
        } else {
            return {true, nullptr};
        }
    }

    std::queue<TreeNode*> qu;
    int index = 0;
    TreeNode* rootPtr = new TreeNode(value[index++]);
    qu.push(rootPtr);
    while (index < size) {
        int quSize = qu.size();
        if (quSize <= 0) return {false, nullptr};
        for (int i = 0; i < quSize && index < size; ++i) {
            TreeNode* curNodePtr = qu.front();
            qu.pop();
            
            if (value[index] == NULL_NODE_FLAG) {
                curNodePtr -> left = nullptr;
            } else {
                TreeNode* nodePtr = new TreeNode(value[index]);
                qu.push(nodePtr);
                curNodePtr -> left = nodePtr;
            }
            ++index;
            if (index >= size) break;
            if (value[index] == NULL_NODE_FLAG) {
                curNodePtr -> right = nullptr;
            } else {
                TreeNode* nodePtr = new TreeNode(value[index]);
                qu.push(nodePtr);
                curNodePtr -> right = nodePtr;
            }
            ++index;
        }
    }
    
    return {true, rootPtr};
}