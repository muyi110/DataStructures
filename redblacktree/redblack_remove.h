/****************************************************************/
/*
 * 红黑树删除操作 
 */
/****************************************************************/
#pragma once

template <typename T> bool RedBlack<T>::remove(const T& e)
{
    BinNodePosi(T) &x = this->search(e);
    if(!x)
        return false;
    BinNodePosi(T) r = removeAt(x, this->_hot); // 返回删除节点的接替者，_hot 为删除节点的父亲
    if(!(--this->_size)) // 若只有一个节点被删除
        return true;
    if(!this->_hot) // 若被删除的节点是根节点
    {
        this->_root->color = RB_BLACK;
        updateHeight(this->_root);
        return true;
    }
    if(BlackHeightUpdated(*(this->_hot))) // 若高度平衡 (删除节点x是红色)
        return true;
    if(IsRed(r)) // 若r为红色，只需让其转黑（r为红色，x必为黑色)
    {
        r->color = RB_BLACK;
        r->height++;
        return true;
    }
    solveDoubleBlack(r); // 执行双黑调整
    return true;
}
