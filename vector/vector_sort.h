/***********************************************************/
/*
 * 排序算法汇总
 */
/***********************************************************/
#pragma once

template <typename T> void Vector<T>::sort(Rank lo, Rank hi){
    const int m = 0;
    switch (m){
        case 0:
            bubbleSort(lo, hi); // 起泡排序
            break;
        case 1:
            mergeSort(lo, hi); // 归并排序
            break;
        default:
            mergeSort(lo, hi);
            break;
    }
}
