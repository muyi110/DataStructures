/*********************************************************/
/*
 * BinNode 节点插入操作
 */
/*********************************************************/
#pragma once

template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(const T& e){ // 作为左孩子插入
    return lc = new BinNode(e, this); // 作为当前节点左孩子插入二插树
}

template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(const T& e){ // 作为右孩子插入
    return rc = new BinNode(e, this);
}
