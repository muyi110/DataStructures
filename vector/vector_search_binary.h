/*************************************************/
/*
 * 有序向量的二分查找算法
 */
/*************************************************/
#pragma once
// 静态函数不能被其它文件所用; 其它文件中可以定义相同名字的函数，不会发生冲突;

                                // 模板函数
// 版本A：在有序向量区间[lo, hi)内查找元素e，0 <= lo <= hi <= _size（找到元素可以提取终止）
template <typename T> static Rank binSearch_A(const T *A, const T& e, Rank lo, Rank hi){
    while(lo < hi){
        Rank mi = (hi + lo) >> 1; // 取中点为轴点
        // 两次比较，有三个分支
        if(e < A[mi]) hi = mi; // 转入区间[lo, mi)查找
        else if(A[mi] < e) lo = mi + 1; // 转入区间[mi+1, hi)查找
        else return mi;
    }
    return -1; // 查找失败
} // 当有多个元素命中时，不能确保返回秩最大者；查找失败简单指示-1不能表示失败的位置

// 版本B：在有序向量区间[lo, hi)内查找元素e，0 <= lo <= hi <= _size (不能提前终止)
template <typename T> static Rank binSearch_B(const T* A, const T& e, Rank lo, Rank hi){
    while(1 < hi - lo){
        Rank mi = (lo + hi) >> 1; // 取中点为轴点
        // 一次比较，有两个分支
        (e < A[mi]) ? hi = mi : lo = mi; // 经过比较确定转入区间[lo, mi) 或者[mi, hi)
    } // 循环结束后hi = lo + 1 查找区间为A[lo]
    return (e == A[lo]) ? lo : -1;
} // 当有多个元素命中时，不能确保返回秩最大者；查找失败简单指示-1不能表示失败的位置

// 版本C：在有序向量区间[lo, hi)内查找元素e，0 <= lo <= hi <= _size (不能提前终止)
template <typename T> static Rank binSearch_C(const T* A, const T& e, Rank lo, Rank hi){
    while(lo < hi){
        Rank mi = (lo + hi) >> 1;
        // 一次比较有两个分支
        (e < A[mi]) ? hi = mi : lo = mi + 1; // 经过比较确定进入区间[lo, mi)或者[mi+1, hi)
    }
    return --lo; // 查找结束时，lo为大于 e 的最小秩，所以 lo-1 为不大于 e 的最大秩
} // 有多个元素时可以保证返回秩的最大者，查找失败时返回失败的位置
