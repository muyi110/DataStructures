/***********************************************/
/*
 * 链表的倒置
 */
/***********************************************/
#pragma once
template <typename T> void swap(T& a, T& b){
    T c = b;
    b = a;
    a = c;
}
// 方法1
/*template <typename T> void List<T>::reverse(){
    ListNodePosi(T) p = header; // 头节点
    ListNodePosi(T) q = trailer; // 尾节点
    for(int i = 1; i < _size; i += 2){
        swap((p = p->succ)->data, (q = q->pred)->data); // 交换数据项
    }
}*/
// 方法2
/*template <typename T> void List<T>::reverse(){
    if(_size < 2) return;
    for(ListNodePosi(T) p = header; p; p = p->pred){
        swap(p->pred, p->succ); // 交换链表中每一个节点里的前驱和后继节点
    }
    swap(header, trailer);
}*/
// 方法3
template <typename T> void List<T>::reverse(){
    if(_size < 2) return;
    ListNodePosi(T) p;
    ListNodePosi(T) q;
    for(p = header, q = p->succ; p != trailer; p = q, q = p->succ){
        p->pred = q; // 依次交换节点的前驱指针
    }
    trailer->pred = NULL;
    for(p = header, q = p->pred; p != trailer; p = q, q = p->pred){
        q->succ = p; // 依次交换节点的后继指针
    }
    header->succ = NULL;
    swap(header, trailer);
}
