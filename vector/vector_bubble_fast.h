/*************************************************/
/*
 * 起泡排序算法时间复杂度最好为O(n)，最坏为O(n^2)
 */
/*************************************************/
#pragma once

template <typename T> void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
// 此版本会记录最右侧逆序对的位置，若之后的范围有序，直接将排序范围缩小到记录到的逆序位置
template <typename T> Rank Vector<T>::bubble(Rank lo, Rank hi){ // 一趟扫描交换
    Rank last = lo; // 最右侧逆序对初始化为[lo-1, lo]
    while(++lo < hi){ // 自左向右开始扫描相邻元素
        if(_elem[lo-1] > _elem[lo]){
            last = lo; // 更新逆序对最右侧位置
            swap(_elem[lo-1], _elem[lo]);
        }
    }
    return last;
}
