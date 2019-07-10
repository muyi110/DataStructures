/*******************************************************/
/*
 * 二叉堆
 *     结构性质：完全二叉树，底层元素从左到右填入
 *     堆序性质：
 *         最大堆：任意节点都应该不小于其所有后裔
 *         最小堆：任意节点都应该不大于其所有后裔
 * 实际实现采用数组结构，数组下标从1开始，对于任意节点i，
 * 其左儿子位置2i，右儿子位置（2i+1）（层序遍历）
 */
/*******************************************************/
#pragma once
#include <vector>
#include "../priorityqueue.h"

template <typename T, typename VT> static inline bool inHeap(T n, VT i)
{
    return ((0 < i) && (i < n));
}
template <typename T> static inline T parent(T i)
{
    return i >> 1;
}
template <typename T> static inline T leftChild(T i)
{
    return i << 1;
}
template <typename T> static inline T rightChild(T i)
{
    return (i << 1 + 1);
}

template <typename T> class BinaryHeap : public PriorityQueue<T>
{
public:
    // vec[0] 是哨兵
    explicit BinaryHeap() : _size(0) {T dummy; vec.push_back(dummy);} // 默认构造函数
    explicit BinaryHeap(const std::vector<T>& vec) : _size(vec.size())
    {
        T dummy;
        this->vec.push_back(dummy); // 哨兵
        for(int i = 0; i < vec.size(); ++i)
        {
            this->vec.push_back(vec[i]);
        }
        buildHeap();
    }

    bool isEmpty() const {return _size <= 0;}
    void clear() {_size = 0; vec.clear();};
    size_t size() const {return _size;}
    const std::vector<T>& getHeap() const {return vec;}
    void insert(T&);
    T getMax() {return vec[1];};
    T deleteMax();
protected:
    void percolateDown(int i);
    void buildHeap();
private:
    size_t _size;
    std::vector<T> vec;
};
#include "binaryheap_insert.h"
#include "binaryheap_deleteMax.h"
#include "binaryheap_buildHeap.h"
#include "binaryheap_percolateDown.h"
