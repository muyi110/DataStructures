/*************************************************/
/*
 * quadlist 初始化操作
 */
/*************************************************/
#pragma once

template <typename T> void QuadList<T>::init()
{
    header = new QuadListNode<T>;
    trailer = new QuadListNode<T>;
    header->succ = trailer;
    header->pred = nullptr;
    trailer->pred = header;
    trailer->succ = nullptr;
    header->above = trailer->above = nullptr;
    header->below = trailer->below = nullptr;
    _size = 0;
}
