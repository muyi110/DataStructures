/*****************************************************/
/*
 * 返回子树规模
 */
/*****************************************************/
#pragma once

template <typename T> int BinTree<T>::size(BinNodePosi(T) x) const{
    return x ? size(x->lc) + size(x->rc) : 0; // ????????? 
}
