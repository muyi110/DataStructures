/************************************************************/
/*
 * 下溢算法
 */
/************************************************************/
#pragma once

template <typename T> void BinaryHeap<T>::percolateDown(int i)
{
    int child;
    T lastElement = vec[i];
    for(;leftChild(i) <= _size; i = child)
    {
        child = leftChild(i);
        if(child != _size && vec[child+1] > vec[child])
        {
            ++child;
        }
        if(lastElement < vec[child])
        {
            vec[i] = vec[child];
        }
        else
            break;
    }
    vec[i] = lastElement;
}
