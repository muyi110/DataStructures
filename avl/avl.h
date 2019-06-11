/********************************************************/
/*
 * AVL树，基于BST树实现
 */
/********************************************************/
#pragma once
#include "../bst/bst.h"

template <typename T> class AVL : public BST<T>
{
public:
    BinNodePosi(T) insert(const T& e); // 重写
    bool remove(const T& e); // 重写
};

#include "avl_implementation.h"
