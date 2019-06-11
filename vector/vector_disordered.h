/*************************************************/
/*
 * 检查向量是否有序，并返回逆序对总数
 */
/*************************************************/
#pragma once

template <typename T> int Vector<T>::disordered() const{
    int n = 0; // 逆序对计数器
    for(Rank i = 1; i < _size; ++i){ //从前往后依次线性扫描
        if(_elem[i-1] > _elem[i])
            ++n;
    }
    return n; // 当n=0时，向量有序
}
