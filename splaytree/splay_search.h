/*********************************************************/
/*
 * 伸展树搜索
 */
/*********************************************************/
#pragma once

template <typename T> BinNodePosi(T) & SPlay<T>::search(const T& e)
{
    BinNodePosi(T) p = searchin(this->_root, e, this->_hot = nullptr);
    this->_root = splay(p ? p : this->_hot); // 将最后一个被访问的节点伸展到根
    return this->_root;
} // 无论查找成功与否，_root都指向最后被访问的节点
