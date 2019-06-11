/************************************************************/
/*
 * BST 的插入操作
 */
/************************************************************/
#pragma once

template <typename T> BinNodePosi(T) BST<T>::insert(const T& e)
{
    BinNodePosi(T) &x = search(e);
    if(x)
        return x;
    x = new BinNode<T>(e, _hot); // 创建新节点 x , 以e为关键码，以_hot 为父
    this->_size++; // 更新树的规模
    this->updateHeightAbove(x); // 更新x及历代祖先的高度
    return x;
}
