/*********************************************/
/*
 * 链表的析构函数
 */
/*********************************************/
#pragma once

template <typename T> List<T>::~List(){ // 清空链表，释放头尾哨兵
    clear();
    delete header;
    delete trailer;
}
