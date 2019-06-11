/************************************************************/
/*
 * 链表的归并排序算法
 * 对起始位置为p的n个元素
 */
/************************************************************/
#pragma once

template <typename T> void List<T>::mergeSort(ListNodePosi(T)& p, int n){ // 注意这里是对指针p的引用
    if(n < 2) return;
    int m = n >> 1; // 取中点为界限
    ListNodePosi(T) q = p;
    for(int i = 0; i < m; ++i){ // 将链表进行划分
        q = q->succ;
    }
    mergeSort(p, m);
    mergeSort(q, n-m);
    merge(p, m, *this, q, n-m); // 归并处理
}
