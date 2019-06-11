/*****************************************************/
/*
 * 在有序列表中内节点p（可能是trailer）的n个真前驱
 * 找到不大于e测最后者
 */
/*****************************************************/
#pragma once

template <typename T> ListNodePosi(T) List<T>::search(const T& e, int n, ListNodePosi(T) p) const{
    while(0 <= n--){ // 对于p的n个最近的n个前驱，从右向左逐个比较
        if(((p = p->pred)->data) <= e) break;
    }
    return p;
}
