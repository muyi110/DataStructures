/********************************************************/
/*
 * 列表（链表）的节点类（列表的基本构成）
 */
/********************************************************/
// 一旦一个类的名字出现后，被认为是声明过的（尚未定义）
// 因此类允许包含指向它自身类型的引用或指针，但不允许一个
// 类的成员类型是该类自己 (C++Prime P250)
#pragma once

typedef int Rank; // 秩的类型
#define ListNodePosi(T) ListNode<T>* // 列表节点类型

template <typename T> struct ListNode{ // 列表节点模板类，以双向列表实现
    T data; // 数据
    ListNodePosi(T) pred; // 前驱
    ListNodePosi(T) succ; // 后继
    // 构造函数
    ListNode() = default;
    ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL):
    data(e), pred(p), succ(s){}
    // 操作接口
    ListNodePosi(T) insertAsPred(const T& e); // 在当前节点前插入新节点
    ListNodePosi(T) insertAsSucc(const T& e); // 在当前节点后插入新节点
};

#include "listnode_implementation.h"
