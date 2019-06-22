#include <iostream>
#include "btree.h"

void printBtree(BTree<int>& bt)
{
    auto v = bt.root()->child[1];
    for(int i = 0; i < v->key.size(); ++i)
    {
        std::cout << v->key[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    BTree<int> bt(4); // 4阶B树
    std::vector<int> vec = {50, 60, 65, 75, 43, 20, 49, 80, 63, 45, 55, 44};
    for(auto elem : vec)
    {
        bt.insert(elem);
    }
    std::cout << "----------------------------执行插入操作-----------------------" << std::endl;
    std::cout << "B Tree size: " << bt.size() << std::endl;
    std::cout << "B Tree root size and left child: " << bt.root()->key.size() << " " << bt.root()->key[0] << std::endl;
    std::cout << "B Tree root's childs size: " << bt.root()->child.size() << std::endl;
    std::cout << "root's left child's first key: " << bt.root()->child[0]->key[0] << std::endl;
    printBtree(bt);
    std::cout << "----------------------------执行查找操作-----------------------" << std::endl;
    std::cout << "search 55: " << (bt.search(55) ? "Found" : "Not Found") << std::endl;
    std::cout << "search 95: " << (bt.search(95) ? "Found" : "Not Found") << std::endl;
    std::cout << "----------------------------执行删除操作-----------------------" << std::endl;
    std::cout << "remove 49: " << (bt.remove(49) ? "success" : "failed") << std::endl;
    std::cout << "B Tree size: " << bt.size() << std::endl;
    std::cout << "B Tree root size and left child: " << bt.root()->key.size() << " " << bt.root()->key[0] << std::endl;
    std::cout << "B Tree root's childs size: " << bt.root()->child.size() << std::endl;
    std::cout << "root's left child's first key: " << bt.root()->child[0]->key[0] << std::endl;
    printBtree(bt);
    return 0;
}
