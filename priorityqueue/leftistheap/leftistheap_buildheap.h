/*******************************************************************/
/*
 * 构建左式堆（输入是向量）：以线性时间建立左式堆
 * 思路：
 *     把每个元素当作单节点左式堆，把所有这些堆放到一个队列中，之后
 *     让两个堆出队，合并，将合并后的堆入队，直到队列中只有一个堆。
 */
/*******************************************************************/
#pragma once
#include <queue>
template <typename T> void LeftistHeap<T>::buildHeap(const std::vector<T>& vec)
{
    std::queue<LeftistHeap<T>*> Q;
    for(T e : vec)
    {
        LeftistHeap<T>* leftistHeap = new LeftistHeap<T>();
        leftistHeap->_root = new BinNode<T>(e);
        Q.push(leftistHeap);
    }
    while(Q.size() > 1)
    {
        LeftistHeap<T>* first = Q.front();
        Q.pop();
        LeftistHeap<T>* second = Q.front();
        Q.pop();
        LeftistHeap<T>* heap = new LeftistHeap<T>();
        heap->_root = merge(first->root(), second->root());
        Q.push(heap);
    }
    if(!Q.empty())
        this->_root = Q.front()->root();
    else
        this->_root = nullptr;
}
