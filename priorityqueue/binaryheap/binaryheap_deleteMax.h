/**************************************************************/
/*
 * 删除二叉堆的最大者
 */
/**************************************************************/
#pragma once

template <typename T> T BinaryHeap<T>::deleteMax()
{
    if(isEmpty())
    {
        std::cout << "binary heap is empty." << std::endl;
        return vec[0];
    }
    T minItem = vec[1];
    vec[1] = vec[_size--];
    percolateDown(1);
    return minItem;
}
