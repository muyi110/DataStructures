/*************************************************************************/
/*
 * 堆排序算法：时间复杂度O(NlogN)
 * 下面的例程实现没有使用附加的数组
 */
/*************************************************************************/
#pragma once

#define LeftChild(i) (2*(i)+1)

template <typename T> inline void heap_swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/*
 * @params: A: 需要排序的数组
 *          i: 第i个节点
 *          N: 需要排序数组的个数
 *          ascendingFlag: 升序排列（默认）
 * @brief: 此处堆排序数组包含位置0处的数据
 */
template <typename T> void percDown(T A[], int i, int N, bool ascendingFlag)
{
    int child;
    T tmp;
    for(tmp = A[i]; LeftChild(i) < N; i = child)
    {
        child = LeftChild(i);
        if(ascendingFlag) // 升序
        {
            if(child != N-1 && A[child+1] > A[child])
                ++child;
            if(tmp < A[child])
                A[i] = A[child];
            else
                break;
        }
        else // 降序
        {
            if(child != N-1 && A[child+1] < A[child])
                ++child;
            if(tmp > A[child])
                A[i] = A[child];
            else
                break;
        }
    }
    A[i] = tmp;
}

/*
 * @params: A: 需要排序的数组
 *          N: 排序数组的元素个数
 *          ascendingFlag: 升序排列（默认）
 */
template <typename T> void heapSort(T A[], int N, bool ascendingFlag = true)
{
    int i;
    for(i = N / 2; i >= 0; --i) // 构建堆
    {
        percDown(A, i, N, ascendingFlag);
    }
    for(i = N-1; i > 0; --i)
    {
        heap_swap(A[0], A[i]); // 删除最大值/最小值
        percDown(A, 0, i, ascendingFlag);
    }
}
