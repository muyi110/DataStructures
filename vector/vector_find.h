/********************************************************/
/*
 * 无序向量的查找
 */
/********************************************************/
#pragma once

template<typename T> Rank Vector<T>::find(const T& e, Rank lo, Rank hi) const{ // 返回最后一个原始e的位置
    // 0 <= lo < hi <= _size
    while((lo < hi--) && (e != _elem[hi])); // 从后往前进行查找
    return hi; // 若 hi < lo，查找失败
}
