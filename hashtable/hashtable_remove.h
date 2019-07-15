/******************************************************/
/*
 * hashtable 删除操作
 */
/******************************************************/
#pragma once

template <typename K, typename V> bool HashTable<K, V>::remove(K k)
{
    int r = probeForHit(k);
    if(!ht[r])
        return false;
    ht[r]->info = DELETED; // 惰性删除
    delete ht[r]->entry;
    ht[r]->entry = nullptr;
    N--;
    return true;
}
