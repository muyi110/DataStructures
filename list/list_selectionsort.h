/**********************************************************/
/*
 * 链表的选择排序
 */
/**********************************************************/
#pragma once

template <typename T> void List<T>::selectionSort(ListNodePosi(T) p, int n){
    ListNodePosi(T) head = p->pred;
    ListNodePosi(T) tail = p;
    for(int i = 0; i < n; ++i){ // 获取排序区间(head, tail)
        tail = tail->succ;
    }
    while(1 < n){
        ListNodePosi(T) max = selectMax(head->succ, n);
        insertB(tail, remove(max));
        --n;
        tail = tail->pred; // 更新查找空间规模
    }
}
