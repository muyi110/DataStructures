/****************************************************/
/*
 * 遍历操作，对向量中的每一个元素进行操作
 * 方法1：利用函数指针实现
 * 方法2：利用函数对象实现
 */
/****************************************************/
#pragma once

template <typename T> void Vector<T>::traverse(void (*visit)(T&)){ //利用函数指针实现
    for(int i = 0; i < _size; ++i){
        visit(_elem[i]);
    }
}

template <typename T> template <typename VST>
void Vector<T>::traverse(VST& visit){ // 利用函数对象实现（利用模板参数可以接收任意对象）
    for(int i = 0; i < _size; ++i){
        visit(_elem[i]);
    }
}
