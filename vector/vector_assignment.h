/********************************************/
/*
 * 重载 = 操作，便于向量的直接赋值
 */
/********************************************/
#pragma once

template <typename T> Vector<T>& Vector<T>::operator=(const Vector<T>& V){
    if(_elem) delete [] _elem; // 释放 = 左边原有的内容
    copyFrom(V._elem, 0, V.size()); // 整体复制
    return *this; // 返回当前对象的引用; this 是一个指针，需要解引用获取其对象
}
