/**************************************************************/
/*
 * 沿着关键码k对应的查找链，找到首个可用的空桶（插入词条调用）
 * 试探策略选择二次试探
 */
/**************************************************************/
#pragma once

template <typename K, typename V> int HashTable<K, V>::probeForFree(const K& k)
{
    int r = hashCode(k) % M;
    int i = 1;
    while(ht[r] && (ht[r]->info!=DELETED))
    {
        // 查找空桶或者标记为删除的桶跳出
        r = r + i << 1 - 1;
        r = r % M;
        i++;
    }
    return r;
}
