/*************************************************************/
/*
 * 左式堆的合并操作
 *     最小堆: 递归地将具有大的根值与具有小的根值的堆的右子堆合并
 *     最大堆: 递归地将具有小的根值与具有大的根值的堆的右子堆合并
 */
/*************************************************************/
#pragma once

template <typename T> static BinNodePosi(T) merge(BinNodePosi(T) a, BinNodePosi(T) b)
{
    if(!a) return b;
    if(!b) return a;
    if(a->data < b->data) // 确保b为较小的那个
        std::swap(a, b); 
    a->rc = merge(a->rc, b);
    a->rc->parent = a;
    if(!a->lc || a->lc->npl < a->rc->npl)
    {
        std::swap(a->lc, a->rc);
    }
    a->npl = a->rc ? a->rc->npl + 1 : 1; // 新建节点默认NPL为1
    return a;
}

template <typename T> LeftistHeap<T>* LeftistHeap<T>::heapMerge(LeftistHeap* rheap)
{
    this->_root = merge(this->root(), rheap->root());
    return this;
}
