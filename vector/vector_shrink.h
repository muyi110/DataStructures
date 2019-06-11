/***************************************************/
/*
 * 向量容量压缩，节约内存（加倍压缩）
 */
/***************************************************/
#pragma once

template<typename T> void Vector<T>::shrink(){
    if(_capacity < DEFAULT_CAPACITY << 1) return; // 确保压缩后的容量不低于DEFAULT_CAPACITY
    if(_size << 2 > _capacity) return; // 空间利用率超过25%就不压缩，低于25%压缩
    T* oldElem = _elem; // 保存原来数据地址
    _elem = new T[_capacity >>= 1]; // 容量压缩至一半
    for(int i = 0; i < _size; ++i){ // 拷贝原来数据到新的空间
        _elem[i] = oldElem[i];
    }
    delete [] oldElem; // 删除旧的空间内存
}
