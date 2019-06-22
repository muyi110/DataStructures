/****************************************************************/
/*
 * 关键码删除后若节点下溢，做节点旋转或合并处理
 */
/****************************************************************/
#pragma once
#include <algorithm>

template <typename T> void BTree<T>::solveUnderFlow(BTNodePosi(T) v)
{
    if((_order + 1) / 2 <= v->child.size()) // 递归基（向上取整）
        return;
    BTNodePosi(T) p = v->parent;
    if(!p) // 递归基，根节点，没有孩子的下限
    {
        if(!v->key.size() && v->child[0]) // 若v不含关键码，有（唯一）的非空孩子
        {
            _root = v->child[0];
            _root->parent = nullptr;
            v->child[0] = nullptr;
            delete v;
        }
        return;
    }
    auto r = std::find(p->child.begin(), p->child.end(), v); // v 是p的第r个孩子
    auto b = p->child.begin();
    if(r != p->child.begin() && r != p->child.end()) // 左兄弟存在
    {
        BTNodePosi(T) ls = *(r-1);
        if((_order + 1) / 2 < ls->child.size()) // 左兄弟有足够的关键码可以借
        {
            v->key.insert(v->key.begin(), p->key[r - b - 1]); // p 借一个关键码给v（作为其最小关键码）
            p->key[r - b - 1] = *(ls->key.erase(ls->key.end()-1)); // 左兄弟最大关键码给p
            v->child.insert(v->child.begin(), *(ls->child.erase(ls->child.end() - 1)));
            if(v->child[0]) v->child[0]->parent = v;
            return;
        }
    }
    if(r < p->child.end() - 1) // 右兄弟存在
    {
        BTNodePosi(T) rs = *(r+1); // 右孩子存在
        if((_order + 1) / 2 < rs->child.size()) // 右兄弟有足够的关键码
        {
            v->key.insert(v->key.end(), p->key[r - b]); // p借一个关键码给v(作为其最大关键码)
            p->key[r - b] = *(rs->key.erase(rs->key.begin())); // 右兄弟最小关键码给p
            v->child.insert(v->child.end(), *(rs->child.erase(rs->child.begin())));
            if(v->child[v->child.size() - 1]) v->child[v->child.size()-1]->parent = v;
            return;
        }
    }
    if(r != p->child.begin()) // 和左兄弟合并
    {
        BTNodePosi(T) ls = *(r-1);
        ls->key.insert(ls->key.end(), *(p->key.erase(r - 1 - b + p->key.begin()))); // 从父节点借一个关键码
        p->child.erase(r);
        ls->child.insert(ls->child.end(), *(v->child.erase(v->child.begin())));
        if(ls->child[ls->child.size() - 1]) // v 的最左侧孩子给ls做最右侧孩子
            ls->child[ls->child.size() - 1]->parent = ls;
        while(!v->key.empty()) // v中剩余的关键码和孩子依次转入ls
        {
            ls->key.insert(ls->key.end(), *(v->key.erase(v->key.begin())));
            ls->child.insert(ls->child.end(), *(v->child.erase(v->child.begin())));
            if(ls->child[ls->child.size() - 1])
                ls->child[ls->child.size() - 1]->parent = ls;
        }
        delete v;
    }
    else // 和右兄弟合并
    {
        BTNodePosi(T) rs = *(r+1);
        rs->key.insert(rs->key.begin(), *(p->key.erase(r - b + p->key.begin()))); // 从父节点借一个关键码
        p->child.erase(r);
        rs->child.insert(rs->child.begin(), *(v->child.erase(v->child.end() - 1)));
        if(rs->child[0])
            rs->child[0]->parent = rs;
        while(!v->key.empty()) // v中剩余的关键码和孩子依次转入rs
        {
            rs->key.insert(rs->key.begin(), *(v->key.erase(v->key.end()-1)));
            rs->child.insert(rs->child.begin(), *(v->child.erase(v->child.end()-1)));
            if(rs->child[0])
                rs->child[0]->parent = rs;
        }
        delete v;
    }
    solveUnderFlow(p); // 上升一层，有必要递归调用
    return;
}
