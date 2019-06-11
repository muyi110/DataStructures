#include <iostream>
#include "bst.h"

using namespace std;

int main(int argc, char *argv[])
{
    BST<int> bst;
    vector<int> vec = {55, 6, 44, 76, 62, 96};
    for(int elem : vec)
    {
        bst.insert(elem);
    }
    cout << "BST size: " << bst.size() << endl;
    cout << "BST root: " << bst.root()->data << endl;
    cout << "BST height: " << bst.root()->height << endl;
    // 搜索操作
    cout << "Searching for 44 " << endl;
    BinNode<int>* &p = bst.search(44);
    p ? cout << "Found with " << p->data << endl : cout << "not found" << endl;
    cout << "Searching for 100 " << endl;
    BinNode<int>* &p1 = bst.search(100);
    p1 ? cout << "Found with " << p1->data << endl : cout << "not found" << endl;
    // 删除操作
    cout << "removing 44 " << endl;
    bst.remove(44);
    cout << "searching for 44 " << endl;
    BinNode<int>* &p2 = bst.search(44);
    p2 ? cout << "Found with " << p2->data << endl : cout << "not found" << endl;
    return 0;
}
