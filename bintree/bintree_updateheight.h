/*************************************************************/
/*
 * 更新树的高度
 */
/*************************************************************/
#pragma once 

template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x){ // 更新节点高度
    return x->height = 1 + std::max(stature(x->lc), stature(x->rc));
}

template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x){ // 更新x及其祖先高度
    while(x){
        updateHeight(x);
        x = x->parent;
    }
}
