/***********************************************************/
/*
 * B树模板类
 */
/***********************************************************/
#pragma once
#include "btnode.h"

template <typename T> class BTree
{
protected:
    int _size; // 记录总的关键码数目
    int _order; // B树的阶次，创建时指定，至少为3，一般不能修改
    BTNodePosi(T) _root;
    BTNodePosi(T) _hot; // search() 最后访问的非空节点的位置
    void solveOverFlow(BTNodePosi(T)); // 因插入而上溢之后的分裂处理
    void solveUnderFlow(BTNodePosi(T)); // 因删除而下溢之后的合并处理
public:
    BTree(int order = 3) : _order(order), _size(0)
    {
        _root = new BTNode<T>;
    }
    ~BTree()
    {
        if(_root)
            delete _root;
    }
    const int order() const {return _order;}
    const int size() const {return _size;}
    BTNodePosi(T) root() const {return _root;}
    bool empty() const {return !_root;}
    BTNodePosi(T) search(const T& e);
    bool insert(const T& e);
    bool remove(const T& e);
};
#include "btree_search.h"
#include "btree_insert.h"
#include "btree_remove.h"
#include "btree_solveOverFlow.h"
#include "btree_solveUnderFlow.h"
