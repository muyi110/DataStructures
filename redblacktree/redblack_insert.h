/*****************************************************************/
/*
 * 红黑树插入操作
 */
/*****************************************************************/
#pragma once

template <typename T> BinNodePosi(T) RedBlack<T>::insert(const T& e)
{
    BinNodePosi(T) &x = this->search(e);
    if(x)
        return x;
    x = new BinNode<T>(e, this->_hot, nullptr, nullptr, -1); // 创建红节点x，其中黑高度为-1
    this->_size++;
    solveDoubleRed(x);
    return x ? x : this->_hot->parent;
} // 无论e是否在原树中，返回时候总有x->data=e
