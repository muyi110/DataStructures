/*******************************************************/
/*
 * B树的移除操作
 */
/*******************************************************/
#pragma once
#include <algorithm>

template <typename T> bool BTree<T>::remove(const T& e)
{
    BTNodePosi(T) v = search(e);
    if(!v)
        return false;
    auto r = std::find(v->key.begin(), v->key.end(), e); // 根据上面，一定可以找到
    auto b = v->key.begin();
    if(v->child[0]) // v 不是树叶，e 的后继必属于某个叶节点
    {
        BTNodePosi(T) u = v->child[r - b + 1]; // e 的右孩子
        while(u->child[0]) // 一直向左循环找到e的后继
            u = u->child[0];
        v->key[r - b] = u->key[0];
        v = u; // v 和 u 是两个指针，可以赋值
        r = b;
    }
    v->key.erase(v->key.begin() + (r - b));
    v->child.erase(v->child.begin() + 1 + (r - b));
    _size--;
    solveUnderFlow(v);
    return true;
}
