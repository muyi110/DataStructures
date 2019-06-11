/********************************************************/
/*
 * 删除节点及其后代，返回删除的节点数
 */
/********************************************************/
#pragma once

template <typename T> int BinTree<T>::remove(BinNodePosi(T) x){
    FromParentTo(*x) = NULL; // 宏定义在binnode_macro_basic.h文件中，切断来自父亲节点指针
    updateHeightAbove(x->parent); // 更新祖先的高度
    int n = removeAt(x); // 删除子树x
    _size -= n; // 更新树规模
    return n;
}

template <typename T> static int removeAt(BinNodePosi(T) x){
    if(!x) return 0; // 递归基
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    // 释放删除节点资源
    delete x;
    return n;
}
