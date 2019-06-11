/****************************************************/
/*
 * 实现向量的扩容（采用加倍扩容策略）
 */
/****************************************************/
#pragma once
template<typename T> void Vector<T>::expand(){
    if(_size < _capacity) return; // 未满员时不需要扩容
    if(_capacity < DEFAULT_CAPACITY) 
        _capacity = DEFAULT_CAPACITY; // 确保不低于最低容量
    T* oldElem = _elem; // 复制扩容前数据的地址
    _elem = new T[_capacity <<= 1]; // 加倍扩容
    for(int i = 0; i < _size; ++i){ // 将之前的数据拷贝到新的内存中
        _elem[i] = oldElem[i];
    }
    delete [] oldElem; // 释放旧的内存
}
