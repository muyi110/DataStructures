/***********************************************************/
/*
 * 快速排序算法：平均时间复杂度O(NlogN)，最坏为O(N^2)（通过
 * 枢纽元的选取可以避免）
 * 比归并排序快（分割两组是在适当的位置进行并且非常有效）
 */
/***********************************************************/
#pragma once

static const int cutoff = 10;

/*
 * @brief: 交换两个元素
 */
template <typename T> inline void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/*
 * @brief: 利用三数中值分割法获取枢纽元
 */
template <typename T> T median3(T A[], int left, int right, bool ascendingFlag)
{
    int center = (left + right) / 2;
    if(ascendingFlag) // 升序
    {
        if(A[left] > A[center])
            swap(A[left], A[center]);
        if(A[left] > A[right])
            swap(A[left], A[right]);
        if(A[center] > A[right])
            swap(A[center], A[right]);
        swap(A[center], A[right-1]); // 将枢纽元放到 right-1 位置
    }
    else // 降序
    {
        if(A[left] < A[center])
            swap(A[left], A[center]);
        if(A[left] < A[right])
            swap(A[left], A[right]);
        if(A[center] < A[right])
            swap(A[center], A[right]);
        swap(A[center], A[right-1]); // 将枢纽元放到 right-1 位置
    }
    return A[right-1];
}

/*
 * @params: A: 需要排序的数组
 *          left: 排序数组的左边界
 *          right: 排序数组的右边界
 *          ascendingFlag: 升序排列（默认）
 */
template <typename T> void QSort(T A[], int left, int right, bool ascendingFlag)
{
    int i, j;
    T pivot;
    if(left + cutoff <= right)
    {
        pivot = median3(A, left, right, ascendingFlag);
        i = left;
        j = right - 1;
        if(ascendingFlag) // 升序
        {
            for(;;)
            {
                while(A[++i] < pivot){;}
                while(A[--j] > pivot){;}
                if(i < j)
                    swap(A[i], A[j]);
                else
                    break;
            }
        }
        else // 降序
        {
            for(;;)
            {
                while(A[++i] > pivot){;}
                while(A[--j] < pivot){;}
                if(i < j)
                    swap(A[i], A[j]);
                else
                    break;
            }
        }
        swap(A[i], A[right-1]);
        QSort(A, left, i-1, ascendingFlag);
        QSort(A, i+1, right, ascendingFlag);
    }
    else
        insertionSort(A+left, right-left+1, ascendingFlag);
}

/*
 * @params: A: 需要排序的数组
 *          N: 排序数组的大小
 *          ascendingFlag: 升序排列（默认）
 */
template <typename T> void quickSort(T A[], int N, bool ascendingFlag = true)
{
    QSort(A, 0, N-1, ascendingFlag);
}
