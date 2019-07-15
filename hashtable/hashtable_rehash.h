/*****************************************************/
/*
 * 在散列实现
 */
/*****************************************************/
#pragma once

template <typename K, typename V> void HashTable<K, V>::rehash()
{
    int oldCapacity = M;
    Cell<K, V>** old_ht = ht;
    M = nextPrime(M << 1); // 容量加倍
    N = 0;
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
    for(int i = 0; i < oldCapacity; ++i)
    {
        if(old_ht[i] && old_ht[i]->info != DELETED)
            put(old_ht[i]->entry->key(), old_ht[i]->entry->value());
    }
    delete [] old_ht; // 原存放的词条已经转移，只需要释放桶数组本身
}
