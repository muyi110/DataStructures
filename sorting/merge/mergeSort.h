/*****************************************************************/
/*
 * 归并排序算法：时间复杂度O(NlogN)，空间复杂度较大(线性的)
 * 很少用于主存排序
 * 基于比较的排序算法时间复杂度下界为O(NlogN)
 */
/*****************************************************************/
#pragma once

/*
 * @params: A: 需要排序的数组
 *          tmpArray: 和数组A一样大小的临时数组
 *          lpos: 划分左边数组的开始位置
 *          rpos: 划分右边数组的开始位置
 *          rightEnd: 划分右边数组的结束位置
 *          ascendingFlag: 升序排列（默认）
 */
template <typename T> void merge(T A[], T tmpArray[], int lpos, int rpos, int rightEnd, bool ascendingFlag)
{
    int i, leftEnd, numElements, tmpPos;
    leftEnd = rpos - 1;
    tmpPos = lpos;
    numElements = rightEnd - lpos + 1;

    while(lpos <= leftEnd && rpos <= rightEnd)
    {
        if(ascendingFlag) // 升序
        {
            if(A[lpos] <= A[rpos])
                tmpArray[tmpPos++] = A[lpos++];
            else
                tmpArray[tmpPos++] = A[rpos++];
        }
        else // 降序
        {
            if(A[lpos] >= A[rpos])
                tmpArray[tmpPos++] = A[lpos++];
            else
                tmpArray[tmpPos++] = A[rpos++];
        }
    }
    while(lpos <= leftEnd)
        tmpArray[tmpPos++] = A[lpos++];
    while(rpos <= rightEnd)
        tmpArray[tmpPos++] = A[rpos++];
    for(i = 0; i < numElements; ++i, --rightEnd) // 附加的拷贝时间
    {
        A[rightEnd] = tmpArray[rightEnd];
    }
}

/*
 * @params: A: 需要排序的数组
 *          tmpArray: 和数组A一样大小的临时数组
 *          left: 需要排序数组的左边界
 *          right: 需要排序数组的右边界
 *          ascendingFlag: 升序排列（默认）
 */
template <typename T> void Msort(T A[], T tmpArray[], int left, int right, bool ascendingFlag)
{
    int center;
    if(left < right)
    {
        center = (left + right) / 2;
        Msort(A, tmpArray, left, center, ascendingFlag);
        Msort(A, tmpArray, center+1, right, ascendingFlag);
        merge(A, tmpArray, left, center+1, right, ascendingFlag);
    }
}

/*
 * @params: A: 需要排序的数组
 *          N: 数组元素的个数
 *          ascendingFlag: 升序排序（默认）
 */
template <typename T> void mergeSort(T A[], int N, bool ascendingFlag = true)
{
    T *tmpArray = new T[N];
    if(tmpArray)
    {
        Msort(A, tmpArray, 0, N-1, ascendingFlag);
        delete [] tmpArray;
    }
    else
        std::cout << "分配内存失败" << std::endl;
}
