/*****************************************/
/*
 * 删除链表对应的节点
 */
/*****************************************/
#pragma once

template <typename T> T List<T>::remove(ListNodePosi(T) p){ // 删除合法节点 p ，返回其数值
    T e = p->data; // 备份删除的数值（假设类型T何以直接赋值）
    p->pred->succ = p->succ; // 后继
    p->succ->pred = p->pred; // 前驱
    delete p;
    _size--; // 调整删除后链表的大小
    return e; // 返回删除节点的数据
}
