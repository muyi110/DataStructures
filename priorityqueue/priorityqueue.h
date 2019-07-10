/****************************************************************/
/*
 * 优先队列模板类（接口类）
 */
/****************************************************************/
#pragma once

template <typename T> class PriorityQueue
{
public:
    virtual void insert(T&) = 0;
    virtual T getMax() = 0;
    virtual T deleteMax() = 0;
};
