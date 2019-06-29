#include <iostream>
#include "redblack.h"
#include <vector>
using namespace std;

template <typename T> void print(T root)
{
    if(!root)
        return;
    print(root->lc);
    std::cout << " " << root->data;
    print(root->rc);
}

int main(int argc, char* argv[])
{
    vector<int> vec = {45, 43, 48, 50, 49, 40, 39};
    RedBlack<int> rb;
    for(int elem : vec)
    {
        rb.insert(elem);
    }
    cout << "-------------------------红黑树插入操作-----------------------" << endl;
    cout << "root: " << rb.root()->data << endl;
    cout << "size: " << rb.size() << endl;
    cout << "root's height: " << rb.root()->height << endl;
    cout << "root's left child: " << rb.root()->lc->data << endl;
    cout << "root's right child: " << rb.root()->rc->data << endl;
    cout << "rb tree:" << endl;
    print(rb.root());
    cout << endl;
    cout << "-------------------------红黑树删除操作-----------------------" << endl;
    cout <<"search 49: " << (rb.search(49) ? "found" : "no found") << endl;
    cout << "remove 49: " << endl; 
    rb.remove(49);
    cout << "root: " << rb.root()->data << endl;
    cout << "size: " << rb.size() << endl;
    cout << "root's height: " << rb.root()->height << endl;
    cout << "root's left child: " << rb.root()->lc->data << endl;
    cout << "root's right child: " << rb.root()->rc->data << endl;
    return 0;
}
