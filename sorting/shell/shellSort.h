/***********************************************************/
/*
 * Shell 排序算法，增量不同，时间复杂度也略有不同
 * shell 增量：时间复杂度N^2
 * Hibbard 增量: 时间复杂度N^(3/2)
 * Knuth 增量：
 * Sedgewick 增量：时间复杂度N^(7/6)
 */
/***********************************************************/
#pragma once
#include <vector>
enum ShellSequence{Shell, Hibbard, Knuth, Sedgewick, Other};
/*
 * @params: A: 需要排序的数组
 *          N: 需要排序的元素个数
 *          ascendingFlag: 升序排列（默认）
 */
template <typename T> void shellSort(T A[], int N, bool ascendingFlag = true, ShellSequence shellSequence = Sedgewick)
{
    int i, j, increment, h;
    int p = 2, q = 1;
    T tmp;
    std::vector<int> vec; // 用于存放希尔增量
    // 构造希尔增量序列
    switch(shellSequence)
    {
        case Shell: // { 1, ..., N/4, N/2 }
            h = N / 2;
            while(h >= 1)
            {
                vec.push_back(h);
                h /= 2;
            }
            break;
        case Hibbard: // { 1, 3, 7, ..., 2^k - 1 }
            h = 1;
            while(h < N)
            {
                vec.push_back(h);
                h = 2*h + 1;
            }
            for(int i = 0; i < vec.size() / 2; ++i)
            {
                int temp = vec[i];
                vec[i] = vec[vec.size()-1-i];
                vec[vec.size()-1-i] = temp;
            }
            break;
        case Knuth: // { 1, 4, 13, ..., 1/2(3^k - 1) } 不超过N/3
            h = 1;
            while(h < N/3)
            {
                vec.push_back(h);
                h = 3*h + 1;
            }
            for(int i = 0; i < vec.size() / 2; ++i)
            {
                int temp = vec[i];
                vec[i] = vec[vec.size()-1-i];
                vec[vec.size()-1-i] = temp;
            }
            break;
        case Sedgewick: // { 1, 5, 19, 41, ..., 9*4^i - 9*2^i + 1或4^i - 3*2^i + 1 }
            h = 1;
            while(h < N)
            {
                vec.push_back(h);
                if((9*(1 << 2*q)-9*(1 << q)) < (1 << 2*p)-3*(1 << p))
                {
                    h = 9*(1 << 2*q) - 9*(1 << q) + 1;
                    ++q;
                }
                else
                {
                    h = (1 << 2*p) - 3*(1 << p) + 1;
                    ++p;
                }
            }
            for(int i = 0; i < vec.size() / 2; ++i)
            {
                int temp = vec[i];
                vec[i] = vec[vec.size()-1-i];
                vec[vec.size()-1-i] = temp;
            }
            break;
        default: // { N/3 + 1, N/9 + 1, N/27 + 1, ..., 1 }
            h = N / 3;
            while(h > 0)
            {
                vec.push_back(h + 1);
                h /= 3;
            }
            vec.push_back(h + 1);
            break;
    }
    // 希尔排序
    if(vec.empty())
    {
        std::cout << "构造希尔序列失败" << std::endl;
        return;
    }
    for(int n = 0; n < vec.size(); ++n)
    {
        increment = vec[n];
        for(i = increment; i < N; ++i)
        {
            tmp = A[i];
            for(j = i; j >= increment; j -= increment)
            {
                if(ascendingFlag && tmp < A[j - increment]) // 升序
                    A[j] = A[j - increment];
                else if(!ascendingFlag && tmp > A[j - increment]) // 降序
                    A[j] = A[j - increment];
                else
                    break;
            }
            A[j] = tmp;
        }
    }
}
