/*************************************************/
/*
 * 链表拷贝方法（内部方法）
 */
/*************************************************/
#pragma once

template <typename T> void List<T>::copyNodes(ListNodePosi(T) p, int n){ // p合法，至少含有n-1个后继节点
    init(); // 初始化，创建头尾哨兵
    while(n--){ // 将n个节点依次作为末节点插入
        insertAsLast(p->data);
        p = p->succ;
    }
}
