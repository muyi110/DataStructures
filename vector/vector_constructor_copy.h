/****************************************************/
/*
 * 用与向量类的构造函数 （copyFrom实现）
 */
/****************************************************/
#pragma once
template<typename T> void Vector<T>::copyFrom(const T* A, Rank lo, Rank hi){ // 将区间[lo, hi)元素复制到向量中
    _elem = new T[_capacity = 2*(hi-lo)]; // 分配一段内存
    _size = 0; // 向量元素个数初始化为0
    while(lo < hi){ // 将数组元素拷贝到向量中
        _elem[_size++] = A[lo++];
    }
}
