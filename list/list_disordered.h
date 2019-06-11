/**********************************************************/
/*
 * 判断列表是否有序，函数返回逆序对的个数
 */
/**********************************************************/
#pragma once

template <typename T> int List<T>::disordered() const{
    int n = 0;
    ListNodePosi(T) p = first();
    for(int i = 0; i < _size - 1; p = p->succ, ++i){
        if(p->data > p->succ->data)
            ++n;
    }
    return n;
}
