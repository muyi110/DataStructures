/**************************************************************/
/*
 * hashtable 的插入算法
 */
/**************************************************************/
#pragma once

template <typename K, typename V> bool HashTable<K, V>::put(K k, V v)
{
    if(ht[probeForHit(k)]) return false; // 雷同元素不需要插入
    int r = probeForFree(k);
    ht[r] = new Cell<K, V>(k, v);
    ++N;
    if(N << 1 > M)
        rehash();
    return true;
}
