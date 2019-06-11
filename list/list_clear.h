/*******************************************/
/*
 * 列表（链表）的清空操作
 */
/*******************************************/
#pragma once

template <typename T> int List<T>::clear(){
    int oldSize = _size;
    while(0 < _size){ // 循环删除首节点，直到链表为空
        remove(header->succ);
    }
    return oldSize; // 返回删除之前元素的个数
}
