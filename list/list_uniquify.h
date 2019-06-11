/**********************************************************/
/*
 * 有序列表的唯一化操作
 */
/**********************************************************/
#pragma once

template <typename T> int List<T>::uniquify(){ // 返回删除元素的个数
    if(_size < 2) return 0;
    int oldSize = _size;
    ListNodePosi(T) p = first(); // p 为首节点
    ListNodePosi(T) q; // q 为后继节点
    while(trailer != (q = p->succ)){ // 考察紧临的节点对
        if(p->data != q->data)
            p = q;
        else
            remove(q);
    }
    return oldSize - _size;
}
