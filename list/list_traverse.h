/******************************************************/
/*
 * 对链表进行遍历操作
 */
/******************************************************/
#pragma once

template <typename T> void List<T>::traverse(void(*visit)(T&)){ // 利用函数指针遍历
    for(ListNodePosi(T) p = header->succ; p != trailer; p = p->succ){
        visit(p->data);
    }
}

template <typename T> template< typename VST> 
void List<T>::traverse(VST& visit){ // 利用函数对象遍历操作
    for(ListNodePosi(T) p = header->succ; p != trailer; p = p->succ){
        visit(p->data);
    }
}
