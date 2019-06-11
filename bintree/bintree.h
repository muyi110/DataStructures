/**************************************************************/
/*
 * 二叉树类实现
 */
/**************************************************************/
#pragma once
#include "binnode.h"
template <typename T> class BinTree{
protected:
    int _size; // 树的规模
    BinNodePosi(T) _root; // 根节点
    virtual int updateHeight(BinNodePosi(T) x); // 更新节点的高度
    void updateHeightAbove(BinNodePosi(T) x); // 更新节点及其祖先的高度
public:
    BinTree():_size(0), _root(NULL){} // 默认构造函数
    ~BinTree(){ // 析构函数
        if (0 < _size)
            remove(_root);
    }
    int size() const{return _size;} // 树规模
    int size(BinNodePosi(T) x) const; // 子树规模
    bool empty() const{return !_root;} // 判断树是否为空
    BinNodePosi(T) root() const{return _root;} // 访问树根节点
    BinNodePosi(T) insertAsRoot(const T& e); // 作为根节点进行插入
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, const T& e); // 作为节点x的左孩子进行插入
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, const T& e); // 作为节点x的右孩子进行插入
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>*& t); // T作为节点x的左子树接入
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>*& t); // T作为节点x的右子树接入
    int remove(BinNodePosi(T) x); // 删除以x为根的子树，返回该子树原来的规模
    BinTree<T>* secede(BinNodePosi(T) x); // 摘除子树x，并将其转换为一颗独立子树
    // 操作器
    template <typename VST> void travLevel(VST& visit){
        if(_root)
            _root->travLevel(visit);
    }
    template <typename VST> void travPre(VST& visit){
        if(_root)
            _root->travPre(visit);
    }
    template <typename VST> void travIn(VST& visit){
        if(_root)
            _root->travIn(visit);
    }
    template <typename VST> void travPost(VST& visit){
        if(_root)
            _root->travPost(visit);
    }
    // 重载运算符
    bool operator< (const BinTree<T>& t) const{ // 存疑？？？？
        return _root && t._root && (_root < t._root);
    }
    bool operator== (const BinTree<T>& t) const{ // 存疑？？？？
        return _root && t._root && (_root == t._root);
    }
    void stretchToLPath() {stretchByZag(_root);} // 作为左向单链
    void stretchToRPath() {stretchByZig(_root, _size);} // 作为右向单链
};
#include "bintree_implementation.h"
