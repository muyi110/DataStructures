/***************************************************************/
/*
 * 用于插入操作的双红修正
 */
/***************************************************************/
#pragma once

/*
 *@brief: 双红调整算法：解决节点x和其父节点均为红色问题，分两种情况:
          1. 2次颜色翻转，2次黑高度更新，1-2次旋转（单旋转或双旋转），不需要递归
          2. 3次颜色翻转，3次黑高度更新，0次旋转，需要递归
 */
template <typename T> void RedBlack<T>::solveDoubleRed(BinNodePosi(T) x)
{
    if(IsRoot(*x)) // 如果是树根，将其涂黑，整棵黑高度递增
    {
        this->_root->color = RB_BLACK;
        this->_root->height++;
        return;
    }
    BinNodePosi(T) p = x->parent;
    if(IsBlack(p)) return; // 若x的父节点是黑节点，直接结束
    BinNodePosi(T) g = p->parent; // p为红色，则x的祖父一定存在且为黑色
    BinNodePosi(T) u = uncle(x); // 获取x的父亲兄弟节点
    if(IsBlack(u)) // 叔父节点是黑节点，包括NULL（情况一）
    {
        if(IsLChild(*x) == IsLChild(*p)) // x与p同侧(zig-zig或者zag-zag)
            p->color = RB_BLACK;
        else
            x->color = RB_BLACK;
        g->color = RB_RED;
        BinNodePosi(T) gg = g->parent;
        // 对于赋值操作，先求哪边是不确定的，特别是两边的变量有关联的时候（例如下面的g)
        BinNodePosi(T) &fromParentTo = FromParentTo(*g);
        BinNodePosi(T) r = fromParentTo = this->rotateAt(x); // 调整后子树的根节点
        r->parent = gg;
        // 以上是先染色后旋转，但是先旋转后染色效率更高
    }
    else // 叔父节点是红节点（情况二）
    {
        p->color = RB_BLACK;
        p->height++;
        u->color = RB_BLACK;
        u->height++;
        if(!IsRoot(*g))
            g->color = RB_RED; // g若不是根节点，则转红色
        solveDoubleRed(g);
    }
}
