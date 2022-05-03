#include <iostream>
#include "Morris.h"
#include "Tree.h"

static TreeNode* getPrecursorPtr(TreeNode* root) {
    // 假设root != nullptr && root -> left != nullptr
    TreeNode* precursorPtr = root -> left;
    while (precursorPtr -> right != nullptr && precursorPtr -> right != root) {
        precursorPtr = precursorPtr -> right;
    }
    return precursorPtr;
}

void morrisPreorder(TreeNode* root) {
    while (root != nullptr) {
        if (root -> left != nullptr) {
            TreeNode* precursorPtr = getPrecursorPtr(root);
            if (precursorPtr -> right == nullptr) {
                std::cout << root -> val << '\t';
                precursorPtr -> right = root;
                root = root -> left;
            } else if (precursorPtr -> right == root) {
                precursorPtr -> right = nullptr;
                root = root -> right;
            }
        } else {
            std::cout << root -> val << '\t';
            root = root -> right;
        }
    }
}

void morrisInorder(TreeNode* root) {
    while (root != nullptr) {
        if (root -> left != nullptr) {
            TreeNode* precursorPtr = getPrecursorPtr(root);
            if (precursorPtr -> right == nullptr) {
                precursorPtr -> right = root;
                root = root -> left;
            } else if (precursorPtr -> right == root) {
                std::cout << root -> val << '\t';
                precursorPtr -> right = nullptr;
                root = root -> right;
            }
        } else {
            std::cout << root -> val << '\t';
            root = root -> right;
        }
    }
}

// 后序遍历比较特殊
static TreeNode* reverseNode(TreeNode* node) {
    TreeNode* pre = nullptr;
    TreeNode* next = nullptr;
    while (node != nullptr) {
        next = node -> right;
        node -> right = pre;
        pre = node;
        node = next;
    }
    return pre;
}

static void print(TreeNode* node) {
    TreeNode* head = reverseNode(node);
    TreeNode* cur = head;
    while (cur != nullptr) {
        std::cout << cur -> val << '\t';
        cur = cur -> right;
    }
    reverseNode(head);
}

void morrisPostorder(TreeNode* root) {
    if (root == nullptr) return;
    TreeNode* temp = root;
    while (root != nullptr) {
        if (root -> left != nullptr) {
            TreeNode* precursorPtr = getPrecursorPtr(root);
            if (precursorPtr -> right == nullptr) {
                precursorPtr -> right = root;
                root = root -> left;
            } else if (precursorPtr -> right == root) {
                precursorPtr -> right = nullptr;
                print(root -> left);
                root = root -> right;
            }
        } else {
            root = root -> right;
        }
    }
    print(temp);
}