/**********************************************************/
/*
 * 红黑树类（具有下列性质的二叉查找树）
 * 1、每一个节点要么是黑色，要么是红色；
 * 2、根是黑色的；
 * 3、如果一个节点是红色，它的子节点必须是黑色；
 * 4、从一个节点到NULL指针的每一条路径包含相同数目的黑色节点
 */
/**********************************************************/
#pragma once
#include "../bst/bst.h"

template <typename T> class RedBlack : public BST<T>
{
protected:
    void solveDoubleRed(BinNodePosi(T) x); // 双红修正
    void solveDoubleBlack(BinNodePosi(T) x); // 双黑修正
    int updateHeight(BinNodePosi(T) x); // 更新节点x的高度
public:
    BinNodePosi(T) insert(const T& e);
    bool remove(const T& e);
    // 沿用继承来的接口
};

#include "redblack_insert.h"
#include "redblack_remove.h"
#include "redblack_updateHeight.h"
#include "redblack_solveDoubleRed.h"
#include "redblack_solveDoubleBlack.h"
