/********************************************************/
/*
 * 排序算法汇总
 */
/********************************************************/
#pragma once

template <typename T> void List<T>::sort(ListNodePosi(T) p, int n){
    const int m = 3;
    switch (m){
        case 0:
            insertionSort(p, n); // 插入排序
            break;
        case 1:
            selectionSort(p, n); // 选择排序
            break;
        default:
            mergeSort(p, n); // 归并排序
            break;
    }
}
