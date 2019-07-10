/********************************************************/
/*
 * 二叉堆插入算法
 */
/********************************************************/
#pragma once

template <typename T> void BinaryHeap<T>::insert(T& x)
{
    vec.push_back(x); // 将数据插入向量末尾
    // 执行上溢操作
    int i;
    for(i = ++_size; i > 1 && x > vec[parent(i)]; i = parent(i))
    {
        vec[i] = vec[parent(i)];
    }
    vec[i] = x;
}
