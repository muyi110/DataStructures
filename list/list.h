/***************************************************/
/*
 * 列表类
 */
/***************************************************/
#pragma once
#include "listnode.h"
template <typename T> class List{ // 列表模板类
private:
    int _size; // 列表规模（含有元素的数量）
    ListNodePosi(T) header; // 头部哨兵节点
    ListNodePosi(T) trailer; // 尾部哨兵节点
protected:
    void init(); // 列表初始化
    int clear(); // 清除所有节点
    void copyNodes(ListNodePosi(T) p, int n); // 复制列表中自p起的n项
    void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int); // 归并操作
    void mergeSort(ListNodePosi(T)& p, int n); // 自p开始连续n个节点进行归并排序
    void selectionSort(ListNodePosi(T) p, int n); // 自p开始连续n个节点进行选择排序
    void insertionSort(ListNodePosi(T) p, int n); // 自p开始连续n个节点进行插入排序
public:
    // 构造函数
    List(){init();} // 默认构造函数
    List(const List<T>& L); // 整体复制列表
    List(const List<T>& L, Rank r, int n); // 复制列表L中自r项起的n项
    List(ListNodePosi(T) p, int n); // 复制列表中位置p开始的n项
    // 析构函数
    ~List(); // 释放所有节点
    // 只读接口（声明为常量成员函数）
    Rank size() const{ return _size;} // 返回列表的规模
    bool empty() const { return _size <= 0;} // 判断列表是否是空
    T& operator[](Rank r) const; // 重载下标操作符，支持寻秩访问（效率低）
    ListNodePosi(T) first() const{ return header->succ;} // 首节点位置
    ListNodePosi(T) last() const { return trailer->pred;} // 末节点位置
    bool valid(ListNodePosi(T) p) const{ // 判断节点p是否合法
        return p && (trailer != p) && (header != p);
    }
    int disordered() const; // 判断列表是否有序
    ListNodePosi(T) find(const T& e) const{ // 无序列表查找
        return find(e, _size, trailer);
    }
    ListNodePosi(T) find(const T& e, int n, ListNodePosi(T) p) const; // 无序区间查找
    ListNodePosi(T) search(const T& e) const{ // 有序列表查找
        return search(e, _size, trailer);
    }
    ListNodePosi(T) search(const T& e, int n, ListNodePosi(T) p) const; // 有序列表区间查找
    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n) const; // 在p及其n-1个后继中选择最大者
    ListNodePosi(T) selectMax() const{ // 整体选择最大者
        selectMax(header->succ, _size);
    }
    // 可写访问接口
    ListNodePosi(T) insertAsFirst(const T& e); // 将e当作首节点插入
    ListNodePosi(T) insertAsLast(const T& e); // 将e当作末节点插入
    ListNodePosi(T) insertA(ListNodePosi(T) p, const T& e); // 将e当作p的后继插入
    ListNodePosi(T) insertB(ListNodePosi(T) p, const T& e); // 将e当作p的前驱插入
    T remove(ListNodePosi(T) p); // 删除合法位置p的节点，返回删除节点数据
    void merge(List<T>& L){ // 全列表归并
        merge(first(), size(), L, L.first(), L._size);
    }
    void sort(ListNodePosi(T) p, int n); // 列表区间排序
    void sort(){ // 列表整体排序
        sort(first(), _size);
    }
    int deduplicate(); // 无序列表去重
    int uniquify(); // 有序列表去重
    void reverse(); // 列表倒置
    void traverse(void (*)(T&)); // 利用函数指针遍历
    template <typename VST> void traverse(VST&); // 利用函数对象进行遍历(利用函数模板可以接收任意类型对象)
};
#include "list_implementation.h"
