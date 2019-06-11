/***********************************************************/
/*
 * 有序列表的归并算法
 * 当前列表自p起的n个元素，与列表L中自p起的m个元素归并
 */
/***********************************************************/
#pragma once

template <typename T> void List<T>::merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m){
    ListNodePosi(T) pp = p->pred; // 借助前驱
    while(0 < m){ // q在区间内
        if((0 < n) && (p->data <= q->data)){ // p也在区间内
            if(q == (p = p->succ)) break;
            --n;
        }
        else{ //
            insertB(p, L.remove((q = q->succ)->pred));
            --m;
        }
    }
    p = pp->succ;
}
