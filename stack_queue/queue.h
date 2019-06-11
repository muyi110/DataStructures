/********************************************************/
/*
 * 队列的接口实现
 * 基于向量或者链表实现
 */
/********************************************************/
#pragma once

#include "../chap03/stack.h"

template <typename T> class Queue: public List<T>{ // 基于列表实现队列
public: // size() 和 empty() 直接继承
    void enqueue(const T& e){
        this->insertAsLast(e); // 入对，在尾部插入
    }
    T dequeue(){
        return this->remove(first()); // 出队，首部删除
    }
    T& front(){
        return this->first()->data; // 读取队首元素
    }
};
