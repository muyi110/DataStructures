#include <iostream>
#include "bintree.h"

using namespace std;

template <typename T> struct Visit{
    void operator()(T& e){
        cout << e << " ";
    }
};

template <typename T> void insert(BinTree<T>& bintree, T& e){
    if(bintree.empty())
        bintree.insertAsRoot(e); // 如果为空树，作为根节点插入
    else{
        BinNode<T>* binnode = bintree.root();
        while(binnode){
            if(e < binnode->data){ // 深入左子树
                if(!(binnode->lc)) bintree.insertAsLC(binnode, e);
                binnode = binnode->lc;
            }
            else if(e > binnode->data){ // 深入右子树
                if(!(binnode->rc)) bintree.insertAsRC(binnode, e);
                binnode = binnode->rc;
            }
            else return; // 相等，忽略该元素
        }
    }
}

int main(int argc, char* argv[]){
    BinTree<int> bintree;
    // 构建一个二叉树
    vector<int> vec = {41, 20, 65, 11, 15, 50, 91, 72, 99, 29, 32};
    for(auto& elem : vec){
        insert(bintree, elem);
    }
    cout << "Bintree size: " << bintree.size() << endl;
    cout << "Bintree root: " << bintree.root()->data << endl;
    cout << "Bintree height: " << bintree.root()->height << endl;
    // 遍历操作算法
    Visit<int> visit;
    bintree.travLevel(visit);
    cout << endl;
    bintree.travPre(visit);
    cout << endl;
    bintree.travIn(visit);
    cout << endl;
    bintree.travPost(visit);
    cout << endl;
    // 删除操作
    //cout << bintree.remove(bintree.root()->lc) << endl;
    //bintree.travIn(visit);
    //cout << endl;
    // 单链操作
    bintree.stretchToLPath();
    cout << "Bintree root: " << bintree.root()->data << endl;
    BinNode<int>* binnode_temp = bintree.root();
    while(binnode_temp){
        cout << binnode_temp->data << " ";
        binnode_temp = binnode_temp->lc;
    }
    cout << endl;
    bintree.stretchToRPath();
    cout << "Bintree root: " << bintree.root()->data << endl;
    cout << "Bintree height: " << bintree.root()->height << endl;
    BinNode<int>* binnode_tem = bintree.root();
    while(binnode_tem){
        cout << binnode_tem->data << " ";
        binnode_tem = binnode_tem->rc;
    }
    cout << endl;

    return 0;
}
