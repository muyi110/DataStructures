/***************************************************************/
/*
 * 桶式排序算法：时间复杂度O(M+N)
 * 适用于已知输入是小的整数的情况
 */
/***************************************************************/
#pragma once

/*
 * @params: A: 需要排序的数组
 *          N: 排序数组的元素个数
 *          M: 排序数组中最大元素的最小上界
 *          ascendingFlag: 升序排列（默认）
 */
template <typename T> void bucketSort(T A[], int N, int M, bool ascendingFlag = true)
{
    int countArray[M+1];
    int pos = 0;
    for(int i = 0; i < M+1; ++i)
    {
        countArray[i] = 0;
    }
    for(int i = 0; i < N; ++i)
    {
        countArray[A[i]] += 1;
    }
    if(ascendingFlag) // 升序
    {
        for(int j = 0; j < M+1; ++j)
        {
            for(int n = 0; n < countArray[j]; ++n)
                A[pos++] = j;
        }
    }
    else // 降序
    {
        for(int j = M; j >= 0; --j)
        {
            for(int n = 0; n < countArray[j]; ++n)
                A[pos++] = j;
        }
    }
    if(pos != N)
    {
        std::cout << "桶式排序失败" << std::endl;
    }
}
