/***********************************************************/
/*
 * 四联表模板类
 */
/***********************************************************/
#pragma once
#include "quadlistnode.h"

template <typename T> class QuadList
{
public:
    QuadList() { init();}
    ~QuadList() 
    {
        clear();
        delete header;
        delete trailer;
    }
    size_t size() const { return _size;}
    bool empty() const { return _size <= 0;}
    QListNodePosi(T) first() const { return header->succ; } // 首节点位置
    QListNodePosi(T) last() const {return trailer->pred; }  // 末节点位置
    bool valid(QListNodePosi(T) p) { return p && (trailer != p) && (header != p); } // 判断节点p的位置是否合法

    T remove(QListNodePosi(T) p);
    // 将e插入作为节点p的后继，b的上邻
    QListNodePosi(T) insertAfterAbove(const T& e, QListNodePosi(T) p, QListNodePosi(T) b = nullptr);
    // 遍历节点
    void traverse(void (*)(T&));
    template <typename VS> void traverse(VS& );
protected:
    void init();
    int clear();              // 清除所有节点
private:
    size_t _size;
    QListNodePosi(T) header;  // 头哨兵
    QListNodePosi(T) trailer; // 尾哨兵
};
#include "quadlist_initialize.h"
#include "quadlist_insert.h"
#include "quadlist_remove.h"
#include "quadlist_traverse.h"
