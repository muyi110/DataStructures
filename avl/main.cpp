#include <iostream>
#include "avl.h"

using namespace std;

int main(int argc, char *argv[])
{
    AVL<int> avl;
    //vector<int> vec = {41, 20, 65, 11, 29, 50, 91, 32, 72, 99};
    vector<int> vec = {41, 20, 11, 29, 32, 65, 50, 91, 72, 99};
    cout << "Insert starting....." << endl;
    for(int elem : vec)
    {
        avl.insert(elem);
    }
    cout << "Insert ending...." << endl;
    cout << "AVL size: " << avl.size() << endl;
    cout << "AVL root: " << avl.root()->data << endl;
    cout << "AVL height: " << avl.root()->height << endl;
    // 搜索操作
    cout << "Searching for 29 " << endl;
    BinNode<int>* &p = avl.search(29);
    p ? cout << "Found with " << p->data << endl : cout << "no found" << endl;
    cout << "Searching for 64 " << endl;
    BinNode<int>* &p1 = avl.search(64);
    p1 ? cout << "Found with " << p1->data << endl : cout << "no found" << endl;
    // 删除操作
    cout << "Remove 32 " << endl;
    avl.remove(32);
    cout << "searching for 32" << endl;
    BinNode<int>* &p2 = avl.search(32);
    p2 ? cout << "Found with " << p2->data << endl : cout << "no found" << endl;
    return 0;
}
