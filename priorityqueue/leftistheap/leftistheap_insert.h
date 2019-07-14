/*********************************************************/
/*
 * 左式堆插入操作
 */
/*********************************************************/
#pragma once

template <typename T> void LeftistHeap<T>::insert(T& e)
{
    BinNodePosi(T) v = new BinNode<T>(e);
    this->_root = merge(this->_root, v);
    this->_size++;
}
