/********************************************************/
/*
 * 栈的接口实现
 * 基于向量或者链表实现
 */
/********************************************************/
#pragma once

#include "../chap02/vector.h"
template <typename T> class Stack: public Vector<T>{ //将向量的首/末节点作为栈低/顶
public:
    void push(const T& e){
        this->insert(this->size(), e); // 入栈操作，将新元素作为向量的末元素插入
    }
    T pop(){
        return this->remove(this->size() - 1); // 出栈操作，删除向量末尾元素
    }
    T& top(){
        return (*this)[this->size() - 1]; // 取顶操作，直接返回向量末元素
    }
}; // size() 和 empty() 可直接继承vector
/*
#include "../chap03/list.h"
template <typename T> class Stack:public List<T>{ // 将链表的首/末节点作为栈低/首
public:
    void push(const T& e){
        this->insertAsLast(e); // 入栈操作，将新元素作为链表的未元素
    }
    void pop(){
        return this->remove(last()); // 出栈操作，等效删除链表未元素
    }
    T& top(){
        return this->last()->data; // 取顶操作，直接返回链表的尾元素
    }
};
*/
