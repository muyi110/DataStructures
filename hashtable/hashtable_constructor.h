/********************************************************************/
/*
 * hashtable 模板类构造函数
 */
/********************************************************************/
#pragma once

template <typename K, typename V> HashTable<K, V>::HashTable(int c)
{
    M = nextPrime(c); // 获取不小于c的素数
    N = 0; // 初始装填因子为0
    ht = new Cell<K, V>*[M];
    if(ht)
    {
        for(int i = 0; i < M; ++i)
        {
            ht[i] = nullptr;
        }
    }
    else
        std::cout << "初始化失败" << std::endl;
}
