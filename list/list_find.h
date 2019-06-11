/***********************************************/
/*
 * 链表的查找操作
 */
/***********************************************/
#pragma once

template <typename T> ListNodePosi(T) List<T>::find(const T& e, int n, ListNodePosi(T) p) const{
    // 在无序链表内p位置的n个真前驱中查找元素e的后者
    while(0 < n--){
        if(e == (p = p->pred)->data) return p;
    }
    return NULL; // 查找失败
}
