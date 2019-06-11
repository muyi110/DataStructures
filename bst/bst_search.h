/*******************************************************/
/*
 * BST 搜索实现
 */
/*******************************************************/
#pragma once

template <typename T> BinNodePosi(T)& BST<T>::search(const T& e)
{
    return searchin(this->_root, e, _hot=NULL);
}
