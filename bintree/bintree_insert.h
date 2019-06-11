/****************************************************/
/*
 * 插入节点
 */
/****************************************************/
#pragma once

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(const T& e){ // 作为根节点插入(前提二叉树是空的)
    _size = 1;
    return _root = new BinNode<T>(e);
}

template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, const T& e){ //左孩子插入
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, const T& e){ //右孩子插入
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}
