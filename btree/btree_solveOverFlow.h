/************************************************************/
/*
 * 因插入导致的节点上溢，分裂处理
 */
/************************************************************/
#pragma once
#include <algorithm>

template <typename T> void BTree<T>::solveOverFlow(BTNodePosi(T) v)
{
    if(_order >= v->child.size()) return; // 递归基，当前节点不需要上溢
    int s = _order / 2; // 轴点（此时有_order = key.size() = child.size() - 1), 分裂的两个节点尽可能均衡
    BTNodePosi(T) u = new BTNode<T>(); // 新节点已有一个空孩子
    for(int j = 0; j < _order - s - 1; ++j) // v 右侧_order-s-1个孩子及关键码分裂为右侧节点u
    {
        u->child.insert(u->child.begin()+j, *(v->child.erase(v->child.begin()+s+1)));
        u->key.insert(u->key.begin()+j, *(v->key.erase(v->key.begin()+s+1)));
    }
    u->child[_order-s-1] = *(v->child.erase(v->child.begin()+s+1)); // 移动v最靠右的孩子
    if(u->child[0])
    {
        for(int j = 0; j < _order - s ; ++j) // 父节点统一
        {
            u->child[j]->parent = u;
        }
    }
    BTNodePosi(T) p = v->parent; // 节点v当前的父节点
    if(!p) // 若父节点不存在，说明v是根节点
    {
        _root = p = new BTNode<T>();
        p->child[0] = v;
        v->parent = p;
    }
    auto r = std::lower_bound(p->key.begin(), p->key.end(), v->key[0]);//lower_bound 返回大于等于所查找元素的第一个位置
    auto b = p->key.begin();
    p->key.insert(p->key.begin()+(r-b), *(v->key.erase(v->key.begin()+s))); // 轴点关键码上升
    p->child.insert(p->child.begin()+(r-b)+1, u);
    u->parent = p;
    solveOverFlow(p);
}
