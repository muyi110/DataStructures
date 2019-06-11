/**************************************************/
/*
 * 有序向量的Fibonacci查找
 */
/**************************************************/
#pragma once

class Fib{ // Fibonacci 类
private:
    int f, g; // f = fib(k-1), g = fib(k). 注意 int 型数据很块会溢出
public:
    Fib(int n){ // 构造函数，初始化不小于 n 的最小 Fibonacci 项
        f = 1;
        g = 0;
        while(g < n)
            next();
    }
    int get() const{return g;} // 获取当前的 Fibonacci 项
    int next(){g = g + f; f = g - f; return g;} // 获取下一项 Fibonacci 项
    int prev(){f = g - f; g = g - f; return g;} // 获取前一项 Fibonacci 项
};
// 模板参数

// 版本A：在有序向量区间[lo, hi) 内查找元素e，0 <= lo <= hi <= _size
template <typename T> static Rank fibSearch_A(const T* A, const T& e, Rank lo, Rank hi){
    Fib fib(hi - lo); // 构造 Fibonacci 类实例
    while(lo < hi){ // 两次比较，3个分支
        while(hi - lo < fib.get())
            fib.prev();
        Rank mi = lo + fib.get() - 1;
        if(e < A[mi]) hi = mi;
        else if(A[mi] < e) lo = mi + 1;
        else return mi;
    }
    return -1;
} // 有多个元素命中时不能保证返回秩最大者，查找失败简单返回-1，不能指示失败的位置

// 版本B：在有序向量区间[lo, hi) 内查找元素e，0 <= lo <= hi <= _size
template <typename T> static Rank fibSearch_B(const T* A, const T& e, Rank lo, Rank hi){
    Fib fib(hi - lo);
    while(lo < hi){ // 一次比较，2个分支
        while(hi - lo < fib.get())
            fib.prev();
        Rank mi = lo + fib.get() - 1;
        (e < A[mi]) ? hi = mi: lo = mi + 1;
    }
    return --lo; // 循环结束后，lo为大于e的最小秩，lo-1为不大于e的最大秩
} // 有多个元素命中可以保证返回秩的最大者，查找失败可以返回失败的位置
