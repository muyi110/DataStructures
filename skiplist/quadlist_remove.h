/****************************************************/
/*
 * quadlist 删除操作
 */
/****************************************************/
#pragma once

template <typename T> T QuadList<T>::remove(QListNodePosi(T) p)
{
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    _size--;
    T e = p->entry;
    delete p;
    return e; // 返回被删除的词条
}

template <typename T> int QuadList<T>::clear() // 情空quadlist
{
    size_t oldSize = _size;
    while(0 < _size)
    {
        remove(header->succ);
    }
    return oldSize;
}
