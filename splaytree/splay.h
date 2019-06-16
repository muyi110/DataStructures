/********************************************************/
/*
 * 伸展树(splay tree)实现
 */
/********************************************************/
#pragma once

#include "../bst/bst.h"

template <typename T> class SPlay : public BST<T>
{
protected:
    BinNodePosi(T) splay(BinNodePosi(T) v); // 将节点V伸展到根
public:
    BinNodePosi(T) &search(const T& e);
    BinNodePosi(T) insert(const T& e);
    bool remove(const T& e);
};

#include "splay_search.h"
#include "splay_insert.h"
#include "splay_remove.h"
#include "splay_splay.h"
