/**********************************************************/
/*
 * AVL树插入操作
 */
/**********************************************************/
#pragma once

template <typename T> BinNodePosi(T) AVL<T>::insert(const T& e)
{
    BinNodePosi(T) &x = this->search(e);
    if(x)
        return x;
    BinNodePosi(T) xx = x = new BinNode<T>(e, this->_hot);
    this->_size++;
    // 此时，x的父亲_hot若增高，则其祖父有可能失衡
    for(BinNodePosi(T) g = this->_hot; g; g = g->parent) // 依次检查祖先
    {
        if(!AvlBalanced(*g))
        {
            BinNodePosi(T) &temp_g = FromParentTo(*g);
            temp_g = this->rotateAt(tallerChild(tallerChild(g))); // 利用3+4算法使其复衡
            break;
            // 不能写成FromParentTo(*g) = this->rotateAt(tallerChild(tallerChild(g))); 形式，因为程序先执行等式右边，结果调整后树的结构发生
            // 变化，则FromParentTo(*g)得到的结果和期望的不一样。
        }
        else
            this->updateHeight(g);
    }
    return xx;
}
