/*******************************************************/
/*
 *BST删除操作
 */
/*******************************************************/
#pragma once

template <typename T> void swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

/*
 * @brief:删除位置x指向的节点
 * 目标x在此之前查找定位，确认非NULL，必删除成功；与searchin不同，调用之前不必将hot置空
 * 返回值指向实际被删除节点的接替者，hot指向实际被删除节点父亲（二者有可能为NULL）
 */
template <typename T> static BinNodePosi(T) removeAt(BinNodePosi(T) &x, BinNodePosi(T) &hot)
{
    BinNodePosi(T) w = x; // 实际被删除的节点，初始值为x
    BinNodePosi(T) succ = NULL; // 实际被删除节点的接替者（后继）
    if(!HasLChild(*x))
        succ = x = x->rc;
    else if(!HasRChild(*x))
        succ = x = x->lc;
    else // 左右字树都存在，直接删除后继
    {
        w = w->succ(); // 在右子树中获取后继
        swap(x->data, w->data);
        BinNodePosi(T) u = w->parent;
        ((u == x) ? u->rc : u->lc) = succ = w->rc;
    } 
    hot = w->parent;
    if(succ)
        succ->parent = hot;
    delete w;
    return succ;
}
