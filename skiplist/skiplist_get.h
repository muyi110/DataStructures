/***************************************************/
/*
 * 跳转表查找算法
 */
/***************************************************/
#pragma once

template <typename K, typename V> V* SkipList<K, V>::get(K k)
{
    if(this->empty())
        return nullptr;
    ListNode<QuadList<Entry<K, V>>*>* qlist = this->first(); // 从顶层的quadlist开始
    QuadListNode<Entry<K, V>>* p = qlist->data->first(); // 首节点开始
    return skipSearch(qlist, p, k) ? const_cast<char*>(&(p->entry.value())) : nullptr;
} // 有多个命中时后者优先
