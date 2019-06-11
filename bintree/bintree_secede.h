/*********************************************************/
/*
 * 子树分离算法：子树x从当前树中摘除，封装为一颗单独的子树
 */
/*********************************************************/
#pragma once

template <typename T> BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x){
    FromParentTo(*x) = NULL; // 切断父节点指针，一个宏定义(binnode_macro_basic.h)
    updateHeightAbove(x->parent);
    // 封装新的子树
    BinTree<T>* S = new BinTree<T>;
    S->_root = x;
    x->parent = NULL;
    S->_size = x->size();
    _size -= S->size(); // 更新删除后树的规模（不是新树）
    return S;
}
