/**************************************************************/
/*
 * 插入排序算法：平均时间复杂度下界N^2
 * 任何只进行相邻元素交换的排序算法时间复杂度的下界是N^2
 */
/**************************************************************/
#pragma once
/*
 * @params: A: 需要排序的数组
 *          N: 数组元素的个数
 *          ascendingFlag: 升序排列（默认）
 */
template <typename T> void insertionSort(T A[], int N, bool ascendingFlag = true)
{
    int j, p;
    T tmp;
    for(p = 1; p < N; ++p)
    {
        tmp = A[p];
        if(ascendingFlag == true) // 升序
        {
            for(j = p; j > 0 && A[j-1] > tmp; --j)
            {
                A[j] = A[j-1];
            }
            A[j] = tmp;
        }
        else if(ascendingFlag == false) // 降序
        {
            for(j = p; j > 0 && A[j-1] < tmp; --j)
            {
                A[j] = A[j-1];
            }
            A[j] = tmp;
        }

    }
}
