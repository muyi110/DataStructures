/******************************************************/
/*
 * hashtable 查找算法
 */
/******************************************************/
#pragma once

template <typename K, typename V> V* HashTable<K, V>::get(K k)
{
    int r = probeForHit(k);
    return ht[r] ? const_cast<V*>(&(ht[r]->entry->value())) : nullptr;
}
