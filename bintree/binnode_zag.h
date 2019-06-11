/*********************************************************/
/*
 * 逆时针旋转
 */
/*********************************************************/
#pragma once

template <typename T> BinNodePosi(T) BinNode<T>::zag(){
    BinNodePosi(T) rChild = rc;
    rChild->parent = this->parent; // 右孩子的父亲指向当前节点父亲
    if(rChild->parent){ // 旋转后右孩子不是根节点
        ((this == rChild->parent->lc) ? rChild->parent->lc : rChild->parent->rc) = rChild;
    }
    rc = rChild->lc;
    if(rc) rc->parent = this;
    rChild->lc = this;
    this->parent = rChild;
    return rChild;
}
