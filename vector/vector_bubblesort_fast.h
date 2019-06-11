/**********************************************/
/*
 * 起泡排序算法改进版(fast版)
 */
/**********************************************/
#pragma once

template <typename T> void Vector<T>::bubbleSort(Rank lo, Rank hi){ // assert: 0 <= lo < hi <= _size
    while(lo < hi){
        hi = bubble(lo, hi);
    }
}
