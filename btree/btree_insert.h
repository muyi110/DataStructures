/******************************************************************/
/*
 * B树的插入
 */
/******************************************************************/
#pragma once
#include <algorithm>

template <typename T> bool BTree<T>::insert(const T& e)
{
    BTNodePosi(T) v = search(e);
    if(v)
    {
        return false;
    }
    if(_hot->key.empty()) // 如果关键码为空（第一次插入的情况）
    {
        _hot->key.push_back(e);
        _hot->child.insert(_hot->child.begin()+1, nullptr);
        ++_size;
        solveOverFlow(_hot);
    }
    else
    {
        auto r = std::lower_bound(_hot->key.begin(), _hot->key.end(), e); //lower_bound 返回大于等于查找元素的第一个位置
        auto b = _hot->key.begin();
        _hot->key.insert(r, e);
        _hot->child.insert(_hot->child.begin() + (r - b + 1), nullptr);
        ++_size;
        solveOverFlow(_hot);
    }
    return true;
}
