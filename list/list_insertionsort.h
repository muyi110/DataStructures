/*************************************************/
/*
 * 插入排序算法
 */
/*************************************************/
#pragma once

template <typename T> void List<T>::insertionSort(ListNodePosi(T) p, int n){
    for(int r = 0; r < n; ++r){ // r 表示前驱有序链表长度
        insertA(search(p->data, r, p), p->data);
        p = p->succ;
        remove(p->pred);
    }
}
