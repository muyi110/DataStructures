#include <iostream>
#include "binaryheap.h"
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<int> init_vec = {65, 26, 32, 31, 19, 14, 13, 21, 19, 16, 68};
    std::cout << "--------------------输入序列-------------------" << std::endl;
    for(int elem : init_vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    BinaryHeap<int> binaryHeap(init_vec);
    std::cout << "--------------------构造二叉堆-------------------" << std::endl;
    const std::vector<int>& vec = binaryHeap.getHeap();
    for(int i = 1; i <= binaryHeap.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------------删除最大值-------------------" << std::endl;
    binaryHeap.deleteMax();
    const std::vector<int>& vec1 = binaryHeap.getHeap();
    for(int i = 1; i <= binaryHeap.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------------插入-------------------" << std::endl;
    std::cout << "insert 20: " << std::endl;
    int a = 20;
    binaryHeap.insert(a);
    const std::vector<int>& vec2 = binaryHeap.getHeap();
    for(int i = 1; i <= binaryHeap.size(); ++i)
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
