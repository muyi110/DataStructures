/********************************************************/
/*
 * 跳转表插入算法
 */
/********************************************************/
#pragma once
#include <cstdlib>
#include <ctime>

template <typename K, typename V> bool SkipList<K, V>::put(K k, V v)
{
    Entry<K, V> e = Entry<K, V>(k, v); // 待插入词条（被随机插入多个副本）
    if(this->empty())
        this->insertAsFirst(new QuadList<Entry<K, V>>);
    ListNode<QuadList<Entry<K, V>>*>* qlist = this->first(); // 顶层quadlist
    QuadListNode<Entry<K, V>>* p = qlist->data->first(); // 首节点
    if(skipSearch(qlist, p, k)) // 查找适当插入位置（不大于k的最后一个节点p）
        while(p->below)  // 有雷同词条，转到塔底
            p = p->below;
    qlist = this->last();
    QuadListNode<Entry<K, V>>* b = qlist->data->insertAfterAbove(e, p); // b 为新塔基座
    while(rand() & 1) // 1/2 概率确定新塔是否需要长高
    {
        while(qlist->data->valid(p) && !p->above) p = p->pred; // 获得不低于此高度的最近前驱
        if(!qlist->data->valid(p)) // 该前驱是header
        {
            if(qlist == this->first()) // 当前是最顶层
            {
                this->insertAsFirst(new QuadList<Entry<K, V>>);
            }
            p = qlist->pred->data->first()->pred;
        }
        else
        {
            p = p->above;
        }
        qlist = qlist->pred;
        b = qlist->data->insertAfterAbove(e, p, b);
    }
    return true;
} // 允许重复元素
