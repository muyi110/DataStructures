/**********************************************/
/*
 * 向量的插入操作
 */
/**********************************************/
#pragma once

template<typename T> Rank Vector<T>::insert(Rank r, const T& e){ // 0 <= r <= _size（向量空间是连续的）
    expand(); // 若有需要进行扩容
    for(int i = _size; i > r; --i){ // 从后往前将元素后移一位
        _elem[i] = _elem[i-1];
    }
    _elem[r] = e; // 在秩为r的位置插入指定元素
    ++_size; //更新向量大小
    return r; // 返回插入位置的秩
}
