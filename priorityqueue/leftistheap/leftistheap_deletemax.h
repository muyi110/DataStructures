/*************************************************************/
/*
 * 左式堆删除最大值操作
 */
/*************************************************************/
#pragma once

template <typename T> T LeftistHeap<T>::deleteMax()
{
    BinNodePosi(T) lHeap = this->_root->lc;
    BinNodePosi(T) rHeap = this->_root->rc;
    T e = this->_root->data;
    delete this->_root;
    this->_size--;
    this->_root = merge(lHeap, rHeap);
    return e;
}
