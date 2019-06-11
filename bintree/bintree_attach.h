/*****************************************************/
/*
 * 子树接入算法
 */
/*****************************************************/
#pragma once

template <typename T> // 将S当作x的左子树接入，S置空
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>*& S){ // x->lc == NULL
    if(x->lc = S->_root)
        x->lc->parent = x;
    _size += S->size();
    updateHeightAbove(x); // 更新x及其祖先的高度
    S->_root = NULL;
    S->_size = 0;
    delete S;
    return x;
}
template <typename T> // 将S当作x的右子树接入，S置空
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>*& S){ // x->rc == NULL
    if(x->rc = S->_root)
        x->rc->parent = x;
    _size += S->size();
    updateHeightAbove(x); // 更新x及其祖先高度
    S->_root = NULL;
    S->_size = 0;
    delete S;
    return x;
}
