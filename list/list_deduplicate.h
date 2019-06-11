/*************************************************/
/*
 * 删除无序链表中的重复节点
 */
/*************************************************/
#pragma once

template <typename T> int List<T>::deduplicate(){ // 返回删除元素个数
    if(_size < 2) return 0;
    int oldSize = _size;
    ListNodePosi(T) p = header;
    Rank r = 0; // 从首元素开始查找
    while(trailer != (p = p->succ)){ // 判断是否到达链表结尾
        ListNodePosi(T) q = find(p->data, r, p); // 在 p 开始的 r 的真前驱查找雷同者
        q ? remove(q) : ++r;
    }
    return oldSize - _size;
}
