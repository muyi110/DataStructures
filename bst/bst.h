/**********************************************************************
 *
 * 二叉搜索树实现(BST)
 *
 *********************************************************************/
#pragma once

#include "../bintree/bintree.h"

template <typename T> class BST : public BinTree<T>
{
protected:
    BinNodePosi(T) _hot; // 命中节点的父亲
    BinNodePosi(T) connect34(BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), 
                             BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
    BinNodePosi(T) rotateAt(BinNodePosi(T) x); // 对 x 及其父亲，祖父做统一旋转调整
public:
    virtual BinNodePosi(T)& search(const T& e);
    virtual BinNodePosi(T) insert(const T& e);
    virtual bool remove(const T& e);
};
#include "bst_implementation.h"
