/******************************************************/
/*
 * hashtable 模板类析构函数
 */
/******************************************************/
#pragma once

template <typename K, typename V> HashTable<K, V>::~HashTable()
{
    for(int i = 0; i < M; ++i)
    {
        if(ht[i])
            delete ht[i];
    }
    delete [] ht;
}
