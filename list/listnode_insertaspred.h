/*******************************************************/
/*
 * 列表节点类的前驱插入操作
 */
/*******************************************************/
#pragma once

template <typename T> ListNodePosi(T) ListNode<T>::insertAsPred(const T& e){
    // 将e紧靠当前节点之前插入当前节点所属于列表
    ListNodePosi(T) x = new ListNode(e, pred, this); // 创建新的节点
    pred->succ = x;
    pred = x;
    return x;
}
