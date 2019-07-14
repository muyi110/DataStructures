/***********************************************************/
/*
 * 左式堆模板类:
 *     零路径长(NPL): 节点X到一个没有两个儿子节点的最短路径长
 *     具有一个或0个儿子的节点的NPL为0, NPL(NULL)=-1
 *     性质：对堆中的每一个节点X，左儿子的NPL >= 右儿子的NPL
 */
/***********************************************************/
#pragma once
#include "../..//bintree/bintree.h"
#include "../priorityqueue.h"

template <typename T> class LeftistHeap : public PriorityQueue<T>, public BinTree<T>
{
public:
    LeftistHeap(){}
    LeftistHeap(const std::vector<T>& vec)
    {
        buildHeap(vec);
    }
    ~LeftistHeap(){}

    void insert(T&);
    T getMax() { return this->_root->data;}
    T deleteMax();
    LeftistHeap* heapMerge(LeftistHeap* rheap);
protected:
    void buildHeap(const std::vector<T>& vec);
};
#include "leftistheap_merge.h"
#include "leftistheap_insert.h"
#include "leftistheap_deletemax.h"
#include "leftistheap_buildheap.h"
