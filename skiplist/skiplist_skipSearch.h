/*********************************************************/
/*
 * @brief: 跳转表查找算法(若有多个词条命中，沿着四联表取靠后者)
 * @params:
 *     qlist: 顶层列表，p为qlist的首节点
 * @return:
 *     若成功，p为命中关键码所属塔的顶部节点，qlist为p的所属列表
 *     若失败，p为所属塔的基座，该塔对应于不大于k的最大者且靠右关键码，qlist为空
 */
/*********************************************************/
#pragma once

template <typename K, typename V> 
bool SkipList<K, V>::skipSearch(ListNode<QuadList<Entry<K, V>>*>* &qlist, QuadListNode<Entry<K, V>>* &p, K& k)
{
    while(true)
    {
        while(p->succ && (p->entry.key() <= k))
        {
            p = p->succ;
        }
        p = p->pred; // 到回一步
        if(p->pred && (k == p->entry.key())) return true;
        qlist = qlist->succ; // 转入下一层
        if(!qlist->succ) return false; // 若已经跨过低层，意味着失败
        p = (p->pred) ? p->below : qlist->data->first(); // 转到当前塔的下一节点
    }
}
