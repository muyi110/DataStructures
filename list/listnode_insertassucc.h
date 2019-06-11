/******************************************************/
/*
 * 列表节点类的后继插入操作
 */
/******************************************************/
#pragma once

template <typename T> ListNodePosi(T) ListNode<T>::insertAsSucc(const T& e){
    // 将e紧靠当前节点之后插入当前节点所属链表
    // succ 是当前节点中的成员变量
    ListNodePosi(T) x = new ListNode(e, this, succ); //创建新节点
    succ->pred = x;
    succ = x;
    return x;
}
