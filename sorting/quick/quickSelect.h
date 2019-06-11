/***********************************************************************/
/*
 * 快速选择算法: 对于输入序列，找到第k个最大/最小元素
 * 平均时间复杂度O(N), 最坏时间复杂度O(N^2)（很少发生）
 */
/***********************************************************************/
#pragma once
#include "../insertion/insertionSort.h"

static const int selection_cutoff = 10;

/*
 * @brief: 交换两个元素
 */
template <typename T> inline void selection_swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/*
 * @brief: 利用三数中值分割法获取枢纽元
 */
template <typename T> T& selection_median3(T A[], int left, int right)
{
    int center = (left + right) / 2;
    if(A[left] > A[center])
        selection_swap(A[left], A[center]);
    if(A[left] > A[right])
        selection_swap(A[left], A[right]);
    if(A[center] > A[right])
        selection_swap(A[center], A[right]);
    selection_swap(A[center], A[right-1]); // 将枢纽元放到 right-1 位置
    return A[right-1];
}

/*
 * @params: A: 操作的数组
 *          k: 第k个元素
 *          left: 数组左边界
 *          right: 数组右边界
 */
template <typename T> void QSelect(T A[], int k, int left, int right)
{
    int i, j;
    T pivot;
    if(left + selection_cutoff <= right)
    {
        pivot = selection_median3(A, left, right);
        i = left;
        j = right - 1;
        for(;;)
        {
            while(A[++i] < pivot){;}
            while(A[--j] > pivot){;}
            if(i < j)
                selection_swap(A[i], A[j]);
            else
                break;
        }
        selection_swap(A[i], A[right-1]);
        if(k <= i)
            QSelect(A, k, left, i - 1);
        else if(k > i + 1)
            QSelect(A, k, i + 1, right);
    }
    else
        insertionSort(A+left, right-left+1);
}

/*
 * @params: A: 操作的数组
 *          k: 第k个元素
 *          left: 数组左边界
 *          right: 数组右边界
 *          smallestFlag: 返回第k个最小元素（默认）
 * @return: 第k个最大（最小）元素
 */
template <typename T> T& quickSelect(T A[], int k, int left, int right, bool smallestFlag = true)
{
    int N = right - left + 1;
    if(smallestFlag) //获取第k个最小值
    {
        QSelect(A, k, left, right);
        return A[k-1];
    }
    else // 获取第k个最大值(即第N-k+1个最小)
    {
        QSelect(A, N-k+1, left, right);
        return A[N-k];
    }
}
