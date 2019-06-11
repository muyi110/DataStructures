/****************************************************/
/*
 * 顺时针旋转
 */
/****************************************************/
#pragma once

template <typename T> BinNodePosi(T) BinNode<T>::zig(){
    BinNodePosi(T) lChild = lc;
    lChild->parent = this->parent; // 当前节点左孩子指向当前节点父亲
    if(lChild->parent){ // 当前节点父亲存在
        ((this == lChild->parent->lc) ? lChild->parent->lc : lChild->parent->rc) = lChild;
    }
    lc = lChild->rc;
    if(lc) lc->parent = this;
    lChild->rc = this;
    this->parent = lChild;
    return lChild;
}
