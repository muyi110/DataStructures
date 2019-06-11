/*****************************************/
/*
 * 链表初始化操作
 */
/*****************************************/
#pragma once

template <typename T> void List<T>::init(){
    header = new ListNode<T>; // 创建哨兵头节点
    trailer = new ListNode<T>; // 创建哨兵尾节点
    header->succ = trailer;
    header->pred = NULL;
    trailer->pred = header;
    trailer->succ = NULL;
    _size = 0; // 链表初始化规模
}
