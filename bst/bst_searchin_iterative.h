/*******************************************************/
/*
 * 子树中搜索--迭代版本
 */
/*******************************************************/
#pragma once

#define EQUAL(e, v) (!(v) || (e) == (v)->data) // 节点v（或假象的通配哨兵）的关键码等于e
/*
 *@brief: 以v为根的BST子树中查找关键码e
 */
template <typename T> static BinNodePosi(T) & searchin(BinNodePosi(T) &v, const T& e, BinNodePosi(T)& hot)
{
    if(EQUAL(e, v))
        return v;
    hot = v;
    while(true)
    {
        BinNodePosi(T) &c = (e < hot->data) ? hot->lc : hot->rc; // 确定深入的方向
        if(EQUAL(e, c))
            return c;
        hot = c;
    } // hot 始终指向最后一个失败节点
} // 返回时，返回指向命中节点（或假象的通配哨兵）hot 指向其父亲
