/***************************************************************/
/*
 * 在链表中选择最大的元素
 */
/***************************************************************/
#pragma once

template <typename T> ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n) const{
    ListNodePosi(T) max = p; // 初始化节点的位置
    for(ListNodePosi(T) cur = p; 1 < n; --n){
        if((cur = cur->succ)->data >= max->data){
            max = cur;
        }
    }
    return max; // 返回最大元素对应的节点位置
}
