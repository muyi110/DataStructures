/**************************************************************/
/*
 * 沿着关键码k对应的查找链，找到与之匹配的桶（查找和删除调用）
 * 试探策略选择二次试探
 */
/**************************************************************/
#pragma once

template <typename K, typename V> int HashTable<K, V>::probeForHit(const K& k)
{
    int r = hashCode(k) % M; // 获取hash值
    int i = 1;
    while((ht[r] && (ht[r]->info == DELETED)) || (ht[r] && ht[r]->entry->key() != k))
    {
        // 跳过所有有冲突的桶和有惰性删除标记的桶
        //r = (r + 1) % M; // 线性探测
        // 平方探测 F(i) = F(i-1)+2i-1
        r = r + i << 1 - 1;
        r = r % M;
        i++;
    }
    return r; // 调用者根据ht[r]是否为空，可判断查找是否成功
}
