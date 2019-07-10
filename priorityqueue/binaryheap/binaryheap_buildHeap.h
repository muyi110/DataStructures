/*************************************************************/
/*
 * 构建二叉堆
 */
/*************************************************************/
#pragma once

template <typename T> void BinaryHeap<T>::buildHeap()
{
    for(int i = parent(_size); i > 0; --i)
    {
        percolateDown(i);
    }
}
