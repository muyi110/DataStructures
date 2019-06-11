/************************************************/
/*
 * 重载列表（链表）的下标操作，效率低
 */
/************************************************/
#pragma once

template <typename T> T& List<T>::operator[](Rank r) const{ // assert 0 <= r < _size
    ListNodePosi(T) p = first(); // 获取链表首节点位置
    while(0 < r--){ // 从首节点出发，循环 r 次，指向目标节点（--优先级高于 < 操作符）
        p = p->succ;
    }
    return p->data; // 返回目标节点的元素
}
