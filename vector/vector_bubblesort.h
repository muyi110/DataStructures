/*********************************************/
/*
 * 起泡排序，通过每次扫描返回的向量的有序标志
 * 判断是否需要近一步扫描
 */
/*********************************************/
#pragma once

template <typename T> void Vector<T>::bubbleSort(Rank lo, Rank hi){ // assert: 0 <= lo < hi <= _size
    while(!bubble(lo, hi--));
}
