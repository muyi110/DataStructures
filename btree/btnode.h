/*****************************************************************/
/*
 * B树节点类
 */
/*****************************************************************/
#pragma once
#include <vector>

#define BTNodePosi(T) BTNode<T>*

template <typename T> struct BTNode
{
    BTNodePosi(T) parent;
    std::vector<T> key; // 关键码向量
    std::vector<BTNodePosi(T)> child; // 孩子向量（长度比key多1）

    // 构造函数
    BTNode(): parent(nullptr)
    {
        child.insert(child.begin(), nullptr);
    }
    BTNode(T e, BTNodePosi(T) lc = nullptr, BTNodePosi(T) rc = nullptr): parent(nullptr)
    {
        key.insert(key.begin(), e);
        child.insert(child.begin(), lc);
        child.push_back(nullptr);
        if(lc)
            lc->parent = this;
        if(rc)
            rc->parent = this;
    }
};
