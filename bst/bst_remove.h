/*******************************************************/
/*
 * BST 的删除操作
 */
/*******************************************************/
#pragma once

template<typename T> bool BST<T>::remove(const T& e)
{
    BinNodePosi(T) &x = search(e);
    if(!x)
        return false;
    removeAt(x, _hot);
    this->_size--;
    this->updateHeightAbove(_hot);
    return true;
}
