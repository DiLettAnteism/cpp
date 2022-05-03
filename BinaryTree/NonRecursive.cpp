#include "NonRecursive.h"
#include <iostream>
#include <stack>
using std::cout;
using std::stack;

void nrPreorder(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> st;
    while (!st.empty() || root != nullptr) {
        while (root != nullptr) {
            st.push(root);
            cout << root -> val << '\t';
            root = root -> left;
        }
        root = st.top() -> right;
        st.pop();
    }
}

void nrInorder(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> st;
    while (!st.empty() || root != nullptr) {
        while (root != nullptr) {
            st.push(root);
            root = root -> left;
        }
        cout << st.top() -> val << '\t';
        root = st.top() -> right;
        st.pop();
    }
}

// 后序遍历与前序遍历和中序遍历相比有一定的区别
void nrPostorder(TreeNode* root) {
    if (root == nullptr) return;
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* previousVisit = nullptr;
    while (!st.empty()) {
        TreeNode* curNodePtr = st.top();
        if ((curNodePtr -> left == nullptr && curNodePtr -> right == nullptr) || (previousVisit != nullptr && (previousVisit == curNodePtr -> left || previousVisit == curNodePtr -> right))) {
            cout << curNodePtr -> val << '\t';
            previousVisit = curNodePtr;
            st.pop();
        } else {
            // 要先将右结点进栈
            if (curNodePtr -> right != nullptr) {
                st.push(curNodePtr -> right);
            }
            if (curNodePtr -> left != nullptr) {
                st.push(curNodePtr -> left);
            }
        }
    }
}