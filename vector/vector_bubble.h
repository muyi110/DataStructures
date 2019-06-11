/*************************************************/
/*
 * 起泡排序算法时间复杂度最好为O(n)，最坏为O(n^2)
 */
/*************************************************/
#pragma once

template <typename T> void swap(T &a, T &b){
    auto temp = a;
    a = b;
    b = temp;
}

template <typename T> bool Vector<T>::bubble(Rank lo, Rank hi){ // 一趟扫描交换
    bool sorted = true; // 假设整体是有序的
    while(++lo < hi){ // 自左向右开始扫描
        if(_elem[lo-1] > _elem[lo]){ // 检查是否逆序
            sorted = false; // 整体不是有序
            swap(_elem[lo-1], _elem[lo]);
        }
    }
    return sorted;
} // 此版本若检测到已经有序，可以提前终止
