/****************************************************/
/*
 * 向量模板类接口
 */
/****************************************************/
#pragma once // 在C++语言中防止头文件被编译多次（也可用 #ifndef ）
typedef int Rank; // 秩的数据类型
#define DEFAULT_CAPACITY 20 // 默认的初始容量

template <typename T> class Vector{
protected:
    Rank _size; int _capacity; T *_elem; // 大小，容量，数据起始地址
    void copyFrom(T const *A, Rank lo, Rank hi); // 复制数组区间
    void expand(); // 扩容
    void shrink(); // 缩容
    Rank bubble(Rank lo, Rank hi); // 扫描交换
    void bubbleSort(Rank lo, Rank hi); // 起泡排序算法
    Rank max(Rank lo, Rank hi); // 选取最大元素
    void merge(Rank lo, Rank mi, Rank hi); // 归并算法
    void mergeSort(Rank lo, Rank hi); // 归并排序算法
    // 还有其他的排序算法，后续补充
public:
    // 构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0){ // 容量为c，大小为s，元素初始值为v
        _elem = new T[_capacity = c];
        for(_size = 0; _size < s; _elem[_size++]=v);
    }
    Vector(T const* A, Rank n) {copyFrom(A, 0, n);} // 数组的整体复制
    Vector(T const* A, Rank lo, Rank hi) {copyFrom(A, lo, hi);} // 数组区间复制
    Vector(Vector<T> const &V) {copyFrom(V._elem, 0, V._size);} // 向量的整体复制
    Vector(Vector<T> const &V, Rank lo, Rank hi) {copyFrom(V._elem, lo, hi);} // 向量的区间复制
    // 析构函数
    ~Vector() {delete [] _elem;} // 释放空间
    // 只读接口（常量成员函数）
    Rank size() const {return _size;} // 返回大小（包含原始个数）
    bool empty() const {return !_size;} // 判断是否为空
    int disordered() const; // 判断向量是否已经排序
    Rank find(const T &e) const {return find(e, 0, _size);} // 无序向量整体查找
    Rank find(const T &e, Rank lo, Rank hi) const; // 无序向量区间查找
    Rank search(T const &e) const {return (_size <= 0) ? -1 : search(e, 0, _size);} // 有序向量整体查找
    Rank search(T const &e, Rank lo, Rank hi) const; // 有序向量区间查找
    T& operator[](Rank r) const; // 重载下标操作符
    // 可读可写接口
    Vector<T>& operator= (Vector<T> const &); // 重载赋值操作符，便于整个向量的赋值
    T remove(Rank r); // 删除秩为r的元素
    int remove(Rank lo, Rank hi); // 删除区间[lo, hi)类的元素
    Rank insert(Rank r, T const& e); //插入元素
    Rank insert(T const& e) {return insert(_size, e);} // 默认在尾元素后插入
    void sort(Rank lo, Rank hi); //对区间[lo, hi)排序
    void sort() {sort(0, _size);} // 对整体排序
    //void unsort(Rank lo, Rank hi); //对[lo, hi)打乱
    //void unsort() {unsort(0, _size);} // 对整体打乱
    int deduplicate(); // 无序向量唯一化
    int uniquify(); // 有序向量唯一化

    void traverse(void (*)(T&)); // 遍历（使用函数指针，只读或局部修改）
    template<typename VST> void traverse(VST&); // 遍历（使用函数对象，全局性修改）
};
#include "vector_implementation.h"
