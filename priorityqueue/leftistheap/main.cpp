#include <iostream>
#include "leftistheap.h"

template <typename T> void printLeftistHeap(LeftistHeap<T>*& heap)
{
    std::queue<BinNodePosi(T)> Q;
    Q.push(heap->root());
    while(!Q.empty())
    {
        BinNodePosi(T) x = Q.front();
        Q.pop();
        std::cout << x->data << " ";
        if(x->lc)
            Q.push(x->lc);
        if(x->rc)
            Q.push(x->rc);
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    std::vector<int> vec{3, 6, 10, 15, 28, 21, 4, 1, 45, 23, 33, 44};
    for(int elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------------构建左式堆-----------------------" << std::endl;
    std::cout << "插入方式构建： " << std::endl;
    LeftistHeap<int>* lheap = new LeftistHeap<int>();
    for(int elem : vec)
    {
        lheap->insert(elem);
    }
    printLeftistHeap(lheap);
    std::cout << "直接构建：" << std::endl;
    LeftistHeap<int>* lheap1 = new LeftistHeap<int>(vec);
    printLeftistHeap(lheap1);
    std::cout << "--------------------删除最大值-----------------------" << std::endl;
    std::cout << "删除最大值：" << lheap->deleteMax() << std::endl;
    printLeftistHeap(lheap);
    std::cout << "--------------------合并左式堆-----------------------" << std::endl;
    std::vector<int> vec1{10, 20, 18, 12, 6};
    std::cout << "右子堆: " << std::endl;
    LeftistHeap<int>* rheap = new LeftistHeap<int>();
    for(int elem : vec1)
    {
        rheap->insert(elem);
    }
    printLeftistHeap(rheap);
    std::cout << "合并后的子堆: " << std::endl;
    LeftistHeap<int>* heap = lheap->heapMerge(rheap);
    printLeftistHeap(heap);
}
