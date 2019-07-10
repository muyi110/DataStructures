/***************************************************************/
/*
 * 四联表节点模板类
 */
/***************************************************************/
#pragma once
#include "entry.h"
#define QListNodePosi(T) QuadListNode<T>*

template <typename T> struct QuadListNode
{
    T entry;
    QListNodePosi(T) pred;
    QListNodePosi(T) succ;
    QListNodePosi(T) above;
    QListNodePosi(T) below;

    QuadListNode(T e = T(), QListNodePosi(T) p=nullptr, QListNodePosi(T) s=nullptr, QListNodePosi(T) a=nullptr,
                 QListNodePosi(T) b=nullptr): entry(e), pred(p), succ(s), above(a), below(b){}
    // 插入新节点，以当前节点为前驱，以节点b为下邻
    QListNodePosi(T) insertAsSuccAbove(const T& e, QListNodePosi(T) b=nullptr);
};

template <typename T> QListNodePosi(T) QuadListNode<T>::insertAsSuccAbove(const T& e, QListNodePosi(T) b)
{
    QListNodePosi(T) x = new QuadListNode<T> (e, this, succ, nullptr, b);
    succ->pred = x;
    succ = x;
    if(b)
        b->above = x;
    return x;
}
