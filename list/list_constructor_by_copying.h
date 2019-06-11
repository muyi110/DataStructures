/******************************************/
/*
 * 构造函数
 */
/******************************************/
#pragma once

template <typename T> List<T>::List(ListNodePosi(T) p, int n){
    copyNodes(p, n);
}

template <typename T> List<T>::List(const List<T>& L){
    copyNodes(L.first(), L._size);
}

template <typename T> List<T>::List(const List<T>& L, Rank r, int n){ // 复制L中自r项起的n项（r+n <= L._size)
    ListNodePosi(T) p = L.first();
    while(0 < r--){
        p = p->succ;
    }
    copyNodes(p, n);
}
