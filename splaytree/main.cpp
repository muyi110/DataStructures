#include <iostream>
#include <vector>
#include "splay.h"

int main(int argc, char *argv[])
{
    SPlay<int> splay;
    std::vector<int> vec = {32, 35, 34, 25, 29, 45, 39, 33};
    for(int elem : vec)
    {
        splay.insert(elem);
    }
    std::cout << "构造伸展数" << std::endl;
    std::cout << "树大小: " << splay.size() << std::endl;
    std::cout << "根节点: " << splay.root()->data << std::endl;
    std::cout << "高度: " << splay.root()->height << std::endl;
    std::cout << "左孩子: " << ((splay.root()->lc) ? splay.root()->lc->data : 0) << std::endl;
    std::cout << "右孩子: " << ((splay.root()->rc) ? splay.root()->rc->data : 0) << std::endl;
    std::cout << "-----------------------搜索节点25------------------ " << std::endl;
    std::cout << splay.search(25)->data << std::endl;
    std::cout << "-----------------------移除节点25------------------ " << std::endl;
    std::cout << splay.remove(25) << std::endl;
    std::cout << "-----------------------搜索节点25------------------ " << std::endl;
    std::cout << "构造伸展数" << std::endl;
    std::cout << "树大小: " << splay.size() << std::endl;
    std::cout << "根节点: " << splay.root()->data << std::endl;
    std::cout << "高度: " << splay.root()->height << std::endl;
    std::cout << "左孩子: " << ((splay.root()->lc) ? splay.root()->lc->data : 0) << std::endl;
    std::cout << "右孩子: " << ((splay.root()->rc) ? splay.root()->rc->data : 0) << std::endl;
    std::cout << splay.search(25)->data << std::endl;

    return 0;
}
