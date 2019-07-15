/*************************************************************/
/*
 * 实现hash函数模板函数和获取下一个质数模板函数
 */
/*************************************************************/
#pragma once
#include <cmath>
/*
 * @return: 获取大于表大小的最小素数 
 */
template <typename T> static T nextPrime(T tableSize)
{
    while(tableSize > 0)
    {
        int i;
        T mid = static_cast<T>(sqrt(tableSize));
        for(i = 2; i <= mid; ++i)
        {
            if(tableSize % i == 0)
                break;
        }
        if(i > mid)
            break;
        tableSize++;
    }
    return tableSize;
}

static size_t hashCode(char c) { return static_cast<size_t>(c);}
static size_t hashCode(int k) {return static_cast<size_t>(k);}
static size_t hashCode(long long i) { return static_cast<size_t>((i >> 32)+static_cast<int>(i));}
static size_t hashCode(const std::string & s)
{
    int h = 0;
    auto iter = s.begin();
    while(iter != s.end())
    {
        h = (h << 5) | (h >> 27);  // 循环左移5位
        h += static_cast<int>(*iter);
        iter++;
    }
    return static_cast<size_t>(h);
}
