/********************************************************/
/*
 * quadlist 插入操作
 */
/********************************************************/
#pragma once

template <typename T> 
QListNodePosi(T) QuadList<T>::insertAfterAbove(const T& e, QListNodePosi(T) p, QListNodePosi(T) b)
{
    _size++;
    return p->insertAsSuccAbove(e, b);
}
