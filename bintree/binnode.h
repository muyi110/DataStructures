/**********************************************************/
/*
 * 二叉树节点类实现
 */
/**********************************************************/
#pragma once

#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1) // 节点p的高度，空树节点高度为-1
typedef enum {RB_RED, RB_BLACK}RBColor; // 红黑树节点颜色

template <typename T> struct BinNode{ // 二叉树节点模板类
    T data;
    BinNodePosi(T) parent; 
    BinNodePosi(T) lc; 
    BinNodePosi(T) rc; // 父节点，左孩子及右孩子
    int height; // 树高
    int npl; // Null Path Length (左式堆，第10章介绍)
    RBColor color; // 颜色（用于红黑树）
    // 构造函数
    BinNode():parent(NULL), lc(NULL), rc(NULL), height(0), color(RB_RED){} // 默认构造函数
    BinNode(T e, BinNodePosi(T) p=NULL, BinNodePosi(T) lc=NULL, BinNodePosi(T) rc=NULL,
            int h=0, int npl=1, RBColor c=RB_RED):data(e), parent(p), lc(lc), rc(rc), height(h), npl(npl), color(c){}
    // 操作接口
    int size(); // 当前节点后代总数（以其为根的子树规模）
    BinNodePosi(T) insertAsLC(const T&); // 作为当前节点左孩子插入
    BinNodePosi(T) insertAsRC(const T&); // 作为当前节点右孩子插入
    BinNodePosi(T) succ(); // 取当前节点的直接后继
    template <typename VST> void travLevel(VST&); // 层次遍历
    template <typename VST> void travPre(VST&); // 先序遍历
    template <typename VST> void travIn(VST&); // 中序遍历
    template <typename VST> void travPost(VST&); // 后续遍历
    // 比较器和判别器
    bool operator< (const BinNode& bn){
        return data < bn.data;
    }
    bool operator== (const BinNode& bn){
        return data == bn.data;
    }
    BinNodePosi(T) zig(); // 顺时针旋转
    BinNodePosi(T) zag(); // 逆时针旋转
};
#include "binnode_implementation.h"
