/*******************************************************/
/*
 * 跳转表删除算法
 */
/*******************************************************/
#pragma once

template <typename K, typename V> bool SkipList<K, V>::remove(K k)
{
    if(this->empty())
        return false;
    ListNode<QuadList<Entry<K, V>>*>* qlist = this->first(); // 顶层quadlist
    QuadListNode<Entry<K, V>>* p = qlist->data->first(); // 首节点
    if(!skipSearch(qlist, p, k)) return false;
    do // 若词条存在，逐层拆除与之对应的塔
    {
        QuadListNode<Entry<K, V>>* lower = p->below;
        qlist->data->remove(p);
        p = lower;
        qlist = qlist->succ; // 转入下一层
    }while(qlist->succ);
    while(!this->empty() && this->first()->data->empty())
        List<QuadList<Entry<K, V>>*>::remove(this->first());
    return true;
}
