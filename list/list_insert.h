/******************************************/
/*
 * 链表的插入操作
 */
/******************************************/
#pragma once

template <typename T> ListNodePosi(T) List<T>::insertAsFirst(const T& e){
    _size++;
    return header->insertAsSucc(e);
}

template <typename T> ListNodePosi(T) List<T>::insertAsLast(const T& e){
    _size++;
    return trailer->insertAsPred(e);
}

template <typename T> ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, const T& e){
    _size++;
    return p->insertAsSucc(e);
} // 将e当作p的后继插入

template <typename T> ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, const T& e){
    _size++;
    return p->insertAsPred(e);
} // 将e当作p的前驱插入
