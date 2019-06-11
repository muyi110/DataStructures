/********************************************************/
/*
 * AVL树删除
 */
/********************************************************/
#pragma once

template <typename T> bool AVL<T>::remove(const T& e)
{
    BinNodePosi(T) &x = this->search(e);
    if(!x)
        return false;
    removeAt(x, this->_hot);
    this->_size--;
    for(BinNodePosi(T) g=this->_hot; g; g = g->parent)
    {
        if(!AvlBalanced(*g))
        {
            BinNodePosi(T) &temp_g = FromParentTo(*g);
            g = temp_g = this->rotateAt(tallerChild(tallerChild(g)));
        }
        this->updateHeight(g);
    }
    return true;
}
