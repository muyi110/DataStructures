/*******************************************************/
/*
 * 子树中搜索--递归版本
 */
/*******************************************************/
#pragma once
template <typename T> static BinNodePosi(T) & searchin(BinNodePosi(T) &v, const T& e, BinNodePosi(T)& hot)
{
    if(!v || (e == v->data))
        return v;
    hot = v;
    return searchin(((e < v->data) ? v->lc : v->rc), e, hot);
}
