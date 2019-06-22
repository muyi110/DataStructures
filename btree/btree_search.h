/********************************************************/
/*
 * B树搜索
 */
/********************************************************/
#pragma once
#include <algorithm>

template <typename T> BTNodePosi(T) BTree<T>::search(const T& e)
{
    BTNodePosi(T) v = _root; // 从根节点开始找
    _hot = nullptr;
    while(v)
    {
        //lower_bound 返回大于等于所查找元素的第一个位置
        auto r = std::lower_bound(v->key.begin(), v->key.end(), e);
        auto b = v->key.begin();
        if((r != v->key.end()) && (e == *r))
            return v;
        _hot = v;
        v = v->child[r - b]; // 转入对应的子树(_hot指向其父亲) 需要做I/O操作，耗时间
    }
    return nullptr;
}
