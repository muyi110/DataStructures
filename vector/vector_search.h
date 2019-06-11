/***************************************************/
/*
 * 有序向量的查找算法
 * 二分查找，Fibonacci 查找，插值查找（未实现，假设
 * 数据满足一定的规律）
 * 大规模数据：插值查找
 * 中等规模：二分查找
 * 小规模：顺序查找
 * 实际中可以先通过插值将范围缩小再使用二分查找
 */
/***************************************************/
#pragma once

template <typename T> Rank Vector<T>::search(const T& e, Rank lo, Rank hi) const{ // assert: 0 <= lo < hi <= _size
    binSearch_C(_elem, e, lo, hi); // 二分查找版本C（也有版本A，版本B，具体看对应头文件）
    //fibSearch_B(_elem, e, lo, hi); // Fibonacci查找版本B（也有版本A，具体看对应头文件）
}
