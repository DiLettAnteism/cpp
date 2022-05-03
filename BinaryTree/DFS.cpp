#include "DFS.h"
#include <iostream>

void preorder(TreeNode* root) {
    if (root == nullptr) return;
    std::cout << root -> val << '\t';
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root -> left);
    std::cout << root -> val << '\t';
    inorder(root -> right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root -> left);
    postorder(root -> right);
    std::cout << root -> val << '\t';
}