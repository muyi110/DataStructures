/**************************************************/
/*
 * 归并排序算法，时间复杂度O(nlogn)
 * 归并的时间复杂度为O(n)
 * 一种分治算法
 */
/**************************************************/
#pragma once

template <typename T> void Vector<T>::mergeSort(Rank lo, Rank hi){ // 0 <= lo < hi <= _size
    if(hi - lo < 2) return; // 递归的基准情况，对于单元素向量直接返回
    Rank mi = (hi + lo) >> 1; // 取向量的中点为分界点
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi); // 归并
}

template <typename T> void Vector<T>::merge(Rank lo, Rank mi, Rank hi){ // 归并算法向量[lo, mi)和[mi, hi)都是有序的
    T* A = _elem + lo; // 合并后的向量A[0, hi-lo) = _elem[lo, hi)
    Rank lb = mi - lo;
    T* B = new T[lb]; // 分配空间，前子向量B[0, mi-lo) = _elem[lo, mi-lo)
    for(Rank i = 0; i < lb; B[i] = A[i++]); // 将前子向量复制到B中
    int lc = hi - mi;
    T* C = _elem + mi; // 后子向量C[0,lc) = _elem[mi, hi)
    for(Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);){ // i是A的秩，j是B的秩，k是C的秩
        if((j < lb) && (!(k < lc) || (B[j] <= C[k])))
            A[i++] = B[j++];
        if((k < lc) && (!(j < lb) || (C[k] < B[j])))
            A[i++] = C[k++];
    }
    delete [] B;
}
