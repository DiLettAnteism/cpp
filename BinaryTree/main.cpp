#include "Tree.h"
#include "Morris.h"
#include "DFS.h"
#include "NonRecursive.h"
#include <iostream>

int main() {
    int value[13] = {1, 2, 3, 4, NULL_NODE_FLAG, 6, 7, NULL_NODE_FLAG, 9, 12, NULL_NODE_FLAG, 14, 15};
    auto res = createTree(value, 13);
    if(res.first) {
        std::cout << "以下是用Morris遍历实现的" << std::endl;
        std::cout << "前序遍历" << '\t';
        morrisPreorder(res.second);
        std::cout << std::endl;
        std::cout << "中序遍历" << '\t';
        morrisInorder(res.second);
        std::cout << std::endl;
        std::cout << "后序遍历" << '\t';
        morrisPostorder(res.second);
        std::cout << std::endl;
        std::cout << "以下是用递归实现的" << std::endl;
        std::cout << "前序遍历" << '\t';
        preorder(res.second);
        std::cout << std::endl;
        std::cout << "中序遍历" << '\t';
        inorder(res.second);
        std::cout << std::endl;
        std::cout << "后序遍历" << '\t';
        postorder(res.second);
        std::cout << std::endl;
        std::cout << "以下是用栈实现的" << std::endl;
        std::cout << "前序遍历" << '\t';
        nrPreorder(res.second);
        std::cout << std::endl;
        std::cout << "中序遍历" << '\t';
        nrInorder(res.second);
        std::cout << std::endl;
        std::cout << "后序遍历" << '\t';
        nrPostorder(res.second);
        std::cout << std::endl;
    } else {
        std::cout << "出错了" << std::endl;
    }
    return 0;
}